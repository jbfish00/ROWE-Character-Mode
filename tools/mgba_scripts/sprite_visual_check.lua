-- Sprite visual check — the "somebody has to LOOK at it" item, automated far
-- enough that a person only has to glance at a contact sheet.
--
-- Checklist item 19 has been the top of the human list since 2026-07-30: 27 new
-- overworld sheets and 7 new back pics landed, verified by decoding the BUILT
-- .4bpp/.gbapal back out, and **nobody has watched one animate**. The failure
-- modes that survives a decode check are exactly the ones only a moving,
-- in-engine sprite shows: a scrambled walk cycle, a frame-width guess that
-- halved every frame, a palette that decodes fine but reads wrong on the map,
-- a back sprite whose y_offset was set by convention rather than measured.
--
-- ⚠️ THIS IS NOT A SUITE RUN AND MUST NOT BECOME ONE. It asserts nothing about
-- how the art LOOKS, because no assertion can — that judgement is the user's.
-- It produces the images so the judgement takes a minute instead of an hour.
-- run_suite.sh deliberately does not call it.
--
-- ⚠️ SET_CHARACTER ALONE PHOTOGRAPHS THE WRONG CHARACTER. It changes
-- VAR_CHARACTER_ID, but the player object keeps the graphics it was created
-- with, so the screenshot shows the PREVIOUS costume and looks perfectly fine.
-- CM_REQ_REFRESH_AVATAR (RefreshPlayerAvatarGraphics, the call
-- ApplyCostumeChoice makes) is what actually repaints it.
--
--   CM_SAV=<fixture.sav> CM_SHOTS=/tmp/shots CM_CHARS=112,113,24 \
--     timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/sprite_visual_check.lua pokeemerald.gba
--
-- Writes <CM_SHOTS>/<id>-<facing>.png for each character and
-- <CM_SHOTS>/<id>-battle.png for the back sprite.

local H = dofile("tools/mgba_scripts/harness.lua")

local sav = os.getenv("CM_SAV")
if not sav then error("set CM_SAV to the .sav file to continue from") end
if not emu:loadSaveFile(sav, false) then error("loadSaveFile failed: " .. sav) end
emu:reset()

local SHOTS = os.getenv("CM_SHOTS") or "/tmp/rowe-shots"
local SKIP_BATTLE = os.getenv("CM_NO_BATTLE") ~= nil
local CHARS = {}
for id in string.gmatch(os.getenv("CM_CHARS") or "112,113,24", "[^,]+") do
    table.insert(CHARS, tonumber(id))
end

-- An on-roster species every listed character can legally hold is not worth
-- deriving: the battle here exists to render the PLAYER's back sprite, and the
-- opponent is whatever the scripted spawn makes.
local SPECIES_POOCHYENA = 261
local WILD_LEVEL = 10

local REQ_SET_CHARACTER = H.anchors.REQ.SET_CHARACTER
local REQ_REFRESH_AVATAR = H.anchors.REQ.REFRESH_AVATAR
local REQ_WILD_BATTLE = H.anchors.REQ.WILD_BATTLE
local REQ_UNLOCK = H.anchors.REQ.UNLOCK

if not REQ_REFRESH_AVATAR then
    error("anchors.lua predates CM_REQ_REFRESH_AVATAR -- re-run gen_anchors.py")
end

local STATUS_DONE, STATUS_REJECTED = 1, 2
local MB, MB_MAGIC = H.anchors.gCharacterModeTestMailbox, 0x434D5442
local DEADLINE = 300000

local function mbRequest(req, a, b)
    H.wr16(MB + 6, a or 0); H.wr16(MB + 8, b or 0)
    H.wr32(MB + 12, 0); H.wr8(MB + 5, 0); H.wr8(MB + 4, req)
end
local function mbStatus() return H.rd8(MB + 5) end
local function cb2()      return H.rd32(H.anchors.gMain + 4) end
local function onField()  return cb2() == H.anchors.CB2_Overworld + 1 end
local function inBattle() return cb2() == H.anchors.BattleMainCB2 + 1 end

local steps, stepIndex, stepStart, current = {}, 0, 0, nil
local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end
local function mashEvery(f, key, every)
    if (f % every) == 0 then emu:addKey(key) else emu:clearKey(key) end
end
local function mbStep(name, req, a, b, onDone)
    addStep(name, function() mbRequest(req, a, b) end, function(f)
        local s = mbStatus()
        if s == STATUS_REJECTED then
            H.assertTrue(name .. " (mailbox rejected)", false); return true
        end
        if s == STATUS_DONE then if onDone then onDone() end return true end
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
    if f - stepStart >= 240 then emu:clearKey(H.KEY.B); return true end
    mashEvery(f, H.KEY.B, 30)
    return false
end)

for _, id in ipairs(CHARS) do
    mbStep("character " .. id .. ": select", REQ_SET_CHARACTER, id, 0)
    mbStep("character " .. id .. ": repaint the avatar", REQ_REFRESH_AVATAR, 0, 0)

    -- Walk each way, then photograph. Holding a direction for ~40 frames both
    -- turns the sprite AND takes at least one step, so the shot lands mid-walk
    -- rather than on the idle frame -- which is the point: a scrambled walk
    -- cycle looks fine standing still.
    for _, dir in ipairs({ {"down", H.KEY.DOWN}, {"up", H.KEY.UP},
                           {"left", H.KEY.LEFT}, {"right", H.KEY.RIGHT} }) do
        addStep("character " .. id .. ": face/walk " .. dir[1], nil, function(f)
            local t = f - stepStart
            if t < 40 then
                emu:addKey(dir[2])
                return false
            end
            emu:clearKey(dir[2])
            if t == 44 then
                emu:screenshot(SHOTS .. "/" .. id .. "-" .. dir[1] .. ".png")
                H.log("shot " .. id .. "-" .. dir[1] .. ".png")
                return true
            end
            return false
        end)
    end

    if not SKIP_BATTLE then
    mbStep("character " .. id .. ": start a battle for the back sprite",
           REQ_WILD_BATTLE, SPECIES_POOCHYENA, WILD_LEVEL)

    -- ⚠️ THE TRAINER BACK SPRITE IS ONLY ON SCREEN DURING THE THROW. Two
    -- reasonable-looking shots both miss it: a fixed delay catches the
    -- TRANSITION WIPE (blank), and waiting for the action menu catches the
    -- battle after the trainer has already left and the Pokemon is out. The
    -- window is the send-out animation between the two, and it is short.
    -- So: burst the whole intro and keep every frame. Cheap, and the alternative
    -- is a magic constant that rots the first time an animation length changes.
    addStep("character " .. id .. ": photograph the back sprite (burst)", nil, function(f)
        local t = f - stepStart
        if inBattle() then
            if t % 20 == 0 and t <= 400 then
                emu:screenshot(string.format("%s/%d-back-%03d.png", SHOTS, id, t))
            end
            if t > 400 then
                H.log("burst done for " .. id)
                emu:clearKey(H.KEY.B)
                return true
            end
            mashEvery(f, H.KEY.B, 37)
        end
        if t > 20000 then
            H.assertTrue("character " .. id .. " reached a battle", false)
            return true
        end
        return false
    end)

    addStep("character " .. id .. ": leave the battle", nil, function(f)
        if not inBattle() and onField() then
            emu:clearKey(H.KEY.A); emu:clearKey(H.KEY.B); return true
        end
        if inBattle() then
            emu:clearKey(H.KEY.A); emu:clearKey(H.KEY.B)
            emu:clearKey(H.KEY.DOWN); emu:clearKey(H.KEY.RIGHT)
            local cursor = H.rd8(H.anchors.gActionSelectionCursor)
            local tick = f % 24
            if tick == 0 then
                if cursor == 3 then emu:addKey(H.KEY.A)
                elseif cursor == 2 then emu:addKey(H.KEY.RIGHT)
                else emu:addKey(H.KEY.DOWN) end
            elseif tick == 12 then emu:addKey(H.KEY.B) end
        end
        if f - stepStart > 20000 then
            H.assertTrue("character " .. id .. " left the battle", false)
            return true
        end
        return false
    end)

    mbStep("character " .. id .. ": unlock the field", REQ_UNLOCK, 0, 0)
    end
end

-- The only thing this run can honestly assert: that it produced its images.
addStep("all shots taken", nil, function()
    H.assertTrue("visual check ran to completion for " .. #CHARS ..
                 " character(s) -- now LOOK at " .. SHOTS, true)
    return true
end)

local finished = false
H.onFrame(function(f)
    if finished then return end
    if f >= DEADLINE then
        finished = true
        H.assertTrue("finished before deadline (stuck at: " ..
                     (current and current.name or "?") .. ")", false)
        H.finish(); return
    end
    if current == nil then
        stepIndex = stepIndex + 1
        current = steps[stepIndex]
        if current == nil then finished = true; H.finish(); return end
        stepStart = f
        H.log(string.format("STEP %d/%d: %s (frame %d)", stepIndex, #steps, current.name, f))
        if current.enter then current.enter(f) end
    end
    if current.tick and current.tick(f) then current = nil end
end)
