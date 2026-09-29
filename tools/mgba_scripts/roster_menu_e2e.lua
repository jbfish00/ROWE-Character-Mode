-- Character Mode roster screen -- live end-to-end.
--
-- Opens the START menu on a real save, walks to the "Roster" row, opens the
-- screen, scrolls it, closes it, and asserts the game comes back. Also writes
-- screenshots, because the failures this feature can have are LAYOUT failures
-- (icon over the text, window off-screen, name clipped) and no assertion sees
-- those. The images are for a human; the assertions are for the suite.
--
-- ⚠️ gMain.callback2 CANNOT tell you whether this screen is open. It is a
-- field-hosted overlay -- AddWindow over the live map, exactly like the skills
-- menu -- so callback2 stays CB2_Overworld from START to close. The same trap
-- is recorded for the FireRed pair's PC menu in rowe_parity.md: "the PC really
-- opened" is not the same measurement in the two engine families. What IS
-- discriminating is a live task running RosterMenu_HandleInput, so that is
-- what every assertion below keys on.
--
-- ⚠️ THE ROUTE IS START **THEN SELECT**, and both halves were got wrong once.
-- START opens ROWE's GRAPHICAL 8-slot grid (ui_start_menu.c) -- Pokedex / Aa /
-- Pokemon / Feats / Bag / Options / PokeNav / DexNav -- a tilemap with no row
-- for this. SELECT *from the grid* opens the classic list (BuildSaveMenu:
-- Save / Skills / Roster / Exit), which is what the grid's footer means by
-- "SELECT Save". SELECT on the FIELD does something else entirely: it offers
-- to register a bag item.
--
-- Two runs were spent on this, and BOTH were diagnosed by LOOKING at the
-- screenshots rather than by reading the failures. The assertions only ever
-- said "the task is not alive", which is equally consistent with a broken
-- screen and with never reaching the screen -- run 1 had opened the BAG and
-- run 2 was still standing on the field. This is why the layer photographs
-- every step even though no assertion reads the images.
--
-- Roster is second-to-last, right before EXIT, so UP-UP from the cursor's home
-- position lands on it whether or not DEBUG_MENU added a row.
--
--   CM_SAV=<fixture.sav> CM_SHOTS=/tmp/roster-shots \
--     timeout 240 <mgba-headless> \
--     --script tools/mgba_scripts/roster_menu_e2e.lua pokeemerald.gba

local H = dofile("tools/mgba_scripts/harness.lua")

local sav = os.getenv("CM_SAV")
if not sav then error("set CM_SAV to the .sav file to continue from") end
if not emu:loadSaveFile(sav, false) then error("loadSaveFile failed: " .. sav) end
emu:reset()

local SHOTS = os.getenv("CM_SHOTS") or "/tmp/rowe-roster-shots"
local CHARACTER = tonumber(os.getenv("CM_CHAR") or "1")   -- 1 = Red

if H.anchors.RosterMenu_HandleInput == nil or H.anchors.gTasks == nil
   or H.anchors.sSpritePaletteTags == nil then
    error("anchors.lua predates the roster menu -- re-run gen_anchors.py")
end

-- ⚠️ THE PALETTE LEAK (fixed 2026-09-28). The screen used to free each icon
-- with FreeAndDestroyMonIconSprite alone, on the belief that it also frees the
-- palette. It does not (sub_80D328C only calls DestroySprite), so every icon
-- palette the cursor touched stayed loaded on the field after closing. The
-- first 8 assertions all passed on that build. These read the engine's own
-- 16-slot tag table: mon-icon tags are POKE_ICON_BASE_PAL_TAG (56000) + 0..6.
local ICON_TAG_LO, ICON_TAG_HI = 56000, 56006
local function iconTagsLoaded()
    local set, n = {}, 0
    for i = 0, 15 do
        local tag = H.rd16(H.anchors.sSpritePaletteTags + i * 2)
        if tag >= ICON_TAG_LO and tag <= ICON_TAG_HI then
            set[tag] = true; n = n + 1
        end
    end
    return set, n
end
local function describeTags(set)
    local out = {}
    for t = ICON_TAG_LO, ICON_TAG_HI do if set[t] then table.insert(out, tostring(t)) end end
    return "{" .. table.concat(out, ",") .. "}"
end
-- Tags loaded by something else before the screen opened. The screen may
-- neither free these nor leave anything of its own behind.
local baselineTags = nil
local function newTagCount(set)
    local n = 0
    for t = ICON_TAG_LO, ICON_TAG_HI do
        if set[t] and not baselineTags[t] then n = n + 1 end
    end
    return n
end
local function sameAsBaseline(set)
    for t = ICON_TAG_LO, ICON_TAG_HI do
        if (set[t] or false) ~= (baselineTags[t] or false) then return false end
    end
    return true
end

local STATUS_DONE, STATUS_REJECTED = 1, 2
local MB, MB_MAGIC = H.anchors.gCharacterModeTestMailbox, 0x434D5442
local TASK_STRIDE, NUM_TASKS = 40, 16          -- struct Task: func,4 flags,data[16]
local ROSTER_FUNC = H.anchors.RosterMenu_HandleInput + 1   -- Thumb bit

local function mbRequest(req, a, b)
    H.wr16(MB + 6, a or 0); H.wr16(MB + 8, b or 0)
    H.wr32(MB + 12, 0); H.wr8(MB + 5, 0); H.wr8(MB + 4, req)
end
local function mbStatus() return H.rd8(MB + 5) end
local function cb2() return H.rd32(H.anchors.gMain + 4) end
local function onField() return cb2() == H.anchors.CB2_Overworld + 1 end

-- The discriminator: is character_roster_menu.c's input task alive?
local function rosterTaskId()
    for i = 0, NUM_TASKS - 1 do
        local base = H.anchors.gTasks + i * TASK_STRIDE
        if H.rd8(base + 4) ~= 0 and H.rd32(base) == ROSTER_FUNC then
            return i
        end
    end
    return nil
end
local function rosterOpen() return rosterTaskId() ~= nil end

-- data[3] is tIconSprite. MAX_SPRITES (64) means "no icon right now".
local function iconSpriteId()
    local id = rosterTaskId()
    if id == nil then return nil end
    return H.rd16(H.anchors.gTasks + id * TASK_STRIDE + 8 + 3 * 2)
end

-- struct ListMenu is overlaid on the LIST task's data[]: template is 0x18
-- bytes, then u16 scrollOffset, u16 selectedRow. Reading the real cursor
-- position is what lets this layer steer closed-loop instead of counting
-- keypresses that mGBA may or may not deliver.
local function selectedIndex()
    local t = rosterTaskId()
    if t == nil then return nil end
    local listTask = H.rd16(H.anchors.gTasks + t * TASK_STRIDE + 8 + 0 * 2)
    if listTask < 0 or listTask >= NUM_TASKS then return nil end
    local base = H.anchors.gTasks + listTask * TASK_STRIDE + 8
    return H.rd16(base + 0x18) + H.rd16(base + 0x1A)
end

local steps, stepIndex, stepStart = {}, 0, 0
local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end
local function mashEvery(f, key, every)
    if (f % every) == 0 then emu:addKey(key) else emu:clearKey(key) end
end
local function mbStep(name, req, a, b)
    addStep(name, function() mbRequest(req, a, b) end, function(f)
        local s = mbStatus()
        if s == STATUS_REJECTED then
            H.assertTrue(name .. " (mailbox rejected)", false); return true
        end
        if s == STATUS_DONE then return true end
        if f - stepStart > 4000 then
            H.assertTrue(name .. " (mailbox answered)", false); return true
        end
        return false
    end)
end

addStep("continue to overworld", nil, function(f)
    if onField() and H.rd32(MB) == MB_MAGIC then emu:clearKey(H.KEY.A); return true end
    if f - stepStart > 200 then mashEvery(f, H.KEY.A, 25) end
    return false
end)

addStep("settle on the field", nil, function(f)
    return f - stepStart >= 120
end)

-- CM_NO_SET=1 skips the mailbox character-set, so the run depends only on what
-- the SAVE carries. Used to confirm a hand-off fixture really is in Character
-- Mode -- if the Roster row is gated correctly, the screen simply will not open
-- without it.
if os.getenv("CM_NO_SET") == nil then
    mbStep("select the character", H.anchors.REQ.SET_CHARACTER, CHARACTER)
end

addStep("open the START grid", function()
    baselineTags = iconTagsLoaded()
    H.log("mon-icon palette tags before opening: " .. describeTags(baselineTags))
    H.press(H.KEY.START, 8)
end, function(f)
    if f - stepStart >= 90 then
        emu:screenshot(SHOTS .. "/1-start-grid.png")
        return true
    end
    return false
end)

addStep("SELECT from the grid to reach the save menu", function()
    H.press(H.KEY.SELECT, 8)
end, function(f)
    if f - stepStart >= 90 then
        emu:screenshot(SHOTS .. "/2-save-menu.png")
        return true
    end
    return false
end)

-- DOWN twice from the top: Save -> Skills -> Roster.
-- ⚠️ Count from the TOP, not the bottom. BuildSaveMenu's first three rows
-- (Save, Skills, Roster) are unconditional; what comes AFTER Roster is not --
-- MENU_ACTION_DEBUG is there only when DEBUG_MENU is defined, which it is in
-- this build. The first version counted UP from the top on the theory that
-- Roster was "second to last, right before Exit", and landed on DEBUG. Photo
-- 2-save-menu.png shows the real list: Save / Skills / Roster / Debug / Exit.
addStep("move to the Roster row", function()
    H.press(H.KEY.DOWN, 6, 14)
    H.press(H.KEY.DOWN, 6, 14)
end, function(f)
    if f - stepStart >= 90 then
        emu:screenshot(SHOTS .. "/3-roster-row-highlighted.png")
        return true
    end
    return false
end)

addStep("open the roster screen", function()
    H.press(H.KEY.A, 8)
end, function(f)
    if rosterOpen() then
        H.log(string.format("roster task alive at frame %d", f))
        return true
    end
    if f - stepStart > 400 then
        H.assertTrue("roster screen opened (RosterMenu_HandleInput task alive)", false)
        return true
    end
    return false
end)

addStep("let it draw, then photograph it", nil, function(f)
    if f - stepStart < 90 then return false end
    emu:screenshot(SHOTS .. "/4-roster-open.png")
    H.assertTrue("roster screen still open after drawing", rosterOpen())
    -- The icon is the half of "name + icon" no text assertion can see.
    local icon = iconSpriteId()
    H.log(string.format("icon sprite id = %s", tostring(icon)))
    H.assertTrue("an icon sprite exists for the highlighted row (id < 64)",
                 icon ~= nil and icon < 64)
    H.assertTrue("icon sprite is marked in use",
                 icon ~= nil and icon < 64
                 and (H.rd8(H.anchors.gSprites + icon * 0x44 + 0x3E) % 2) == 1)
    return true
end)

-- ⚠️ CLOSED LOOP, NOT A PRESS COUNT. The list reads DPAD with JOY_REPEAT, and
-- mGBA drops short taps -- four DOWN presses at 5 frames each moved the cursor
-- exactly ONE row (measured; the photo showed it on Bellsprout). gen_anchors.py
-- already records this for the intro drive: "blind counts are what every
-- earlier drive got wrong". So mash until the observed row actually changes.
local scrolledFrom, scrolledAt, scrolledTo = nil, nil, nil
addStep("scroll down and re-photograph", function()
    scrolledFrom, scrolledAt, scrolledTo = selectedIndex(), nil, nil
end, function(f)
    local now = selectedIndex()

    -- ⚠️ Do NOT photograph on the frame the index changes. The list redraws
    -- over the following frames, so a same-frame screenshot shows the cursor
    -- still on the old row -- which is how the first version produced a photo
    -- identical to the un-scrolled one while its own assertion said the cursor
    -- had moved. A passing assertion that the picture contradicts is a broken
    -- assertion, so the picture is now taken after the redraw has landed.
    if scrolledAt ~= nil then
        if f - scrolledAt < 40 then return false end
        emu:screenshot(SHOTS .. "/5-roster-scrolled.png")
        H.log(string.format("cursor %d -> %d", scrolledFrom, scrolledTo))
        H.assertTrue("cursor moved down the roster", scrolledTo > scrolledFrom)
        H.assertTrue("roster screen survives scrolling", rosterOpen())
        local icon = iconSpriteId()
        H.assertTrue("icon still present after scrolling",
                     icon ~= nil and icon < 64)
        -- One icon on screen needs one palette. The previous row's palette
        -- must be gone unless the new row shares it.
        local tags = iconTagsLoaded()
        H.log("mon-icon palette tags after scrolling: " .. describeTags(tags))
        H.assertTrue("exactly one mon-icon palette held while open (the highlighted row's)",
                     newTagCount(tags) == 1)
        return true
    end

    if now ~= nil and scrolledFrom ~= nil and now > scrolledFrom then
        emu:clearKey(H.KEY.DOWN)
        scrolledAt, scrolledTo = f, now
        return false
    end
    mashEvery(f, H.KEY.DOWN, 16)
    if f - stepStart > 400 then
        emu:clearKey(H.KEY.DOWN)
        H.assertTrue("cursor moved down the roster", false)
        return true
    end
    return false
end)

addStep("close with B", nil, function(f)
    if not rosterOpen() then
        emu:clearKey(H.KEY.B)
        H.log(string.format("roster task gone at frame %d", f))
        return true
    end
    mashEvery(f, H.KEY.B, 16)
    if f - stepStart > 400 then
        emu:clearKey(H.KEY.B)
        H.assertTrue("roster screen closed on B", false)
        return true
    end
    return false
end)

addStep("field comes back", nil, function(f)
    if f - stepStart < 120 then return false end
    emu:screenshot(SHOTS .. "/6-back-on-field.png")
    H.assertTrue("back on the overworld after closing", onField())
    H.assertTrue("roster task really is gone", not rosterOpen())
    local tags = iconTagsLoaded()
    H.log("mon-icon palette tags after closing: " .. describeTags(tags))
    H.assertTrue("no mon-icon palette left behind on the field (tags == before opening)",
                 sameAsBaseline(tags))
    return true
end)

H.onFrame(function(f)
    if stepIndex == 0 then
        stepIndex, stepStart = 1, f
        if steps[1].enter then steps[1].enter() end
        H.log("step 1: " .. steps[1].name)
        return
    end
    local step = steps[stepIndex]
    if step == nil then return end
    if step.tick(f) then
        stepIndex = stepIndex + 1
        stepStart = f
        local nxt = steps[stepIndex]
        if nxt then
            if nxt.enter then nxt.enter() end
            H.log("step " .. stepIndex .. ": " .. nxt.name)
        else
            H.finish()
        end
    end
end)
