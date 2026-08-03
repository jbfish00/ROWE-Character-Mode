-- Encounter markers e2e (§7.14): the wild-battle intro must NAME the character
-- when the Character Mode roster override or the 1% legendary roll produced the
-- Pokemon, and must be the untouched vanilla line when it did not.
--
-- ⭐ WHY THIS TEST HAS THE SHAPE IT DOES. "The marker appeared" is satisfied by
-- a working feature AND by a marker hardwired on -- the exact shape of the five
-- vacuously-passing checks this repo has shipped. So every battle here is asked
-- the SAME question in a state where the answer must be DIFFERENT, in one run:
--
--   1. ordinary encounter   -> vanilla "Wild X appeared!", no character named
--   2. roster override      -> "A wild X destined for Red appeared!"
--   3. ordinary encounter   -> vanilla again  <- the NON-STICKY control: a
--                              marker that latches passes 1 and 2 and dies here
--   4. 1% legendary         -> "X revealed itself to Red!"
--   5. scripted spawn       -> vanilla, proving CreateScriptedWildMon clears the
--                              marker the legendary battle just set
--   6. plain CreateWildMon  -> vanilla even though the marker was deliberately
--      with the marker set     left set beforehand: the outbreak / Feebas /
--                              DexNav / trade shape
--
-- ⚠️ STEP 6 EXISTS BECAUSE A NEGATIVE CONTROL PASSED. Deleting CreateWildMon's
-- clear and rebuilding left this run 36/36 green, because the override wrapper
-- writes the kind on every call (NORMAL included) and so never depended on that
-- clear. The clear protects the four paths that do NOT go through the wrapper,
-- and none of them was exercised. Step 6 drives one of them, and now the same
-- deletion turns the run red.
--
-- ⭐ AND NOTHING HERE FORCES THE MARKER. CM_REQ_OVERRIDE_WILD_BATTLE calls the
-- shipping CreateWildMonWithCharacterOverride -- the one function both wild call
-- sites in wild_encounter.c go through -- in a loop until the roll produces the
-- kind being asked about, then starts the battle through BattleSetup_StartWildBattle,
-- the same entry point TryStandardWildEncounter uses. The rates are untouched;
-- the loop just waits for an outcome that happens ~10% and ~1% of the time.
--
-- The string is read from gDisplayedStringBattle -- the bytes the game actually
-- printed -- not from the state byte. A test that reads the state byte back
-- proves a byte round-trips, not that the player is told anything.
--
--   CM_SAV=<fixture.sav> timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/encounter_marker_e2e.lua pokeemerald.gba \
--     > /tmp/encounter_marker_e2e.log 2>&1
--
-- Nothing is saved; every mutation lives and dies in RAM.

local H = dofile("tools/mgba_scripts/harness.lua")

local sav = os.getenv("CM_SAV")
if not sav then
    error("set CM_SAV to the .sav file to continue from")
end
if not emu:loadSaveFile(sav, false) then
    error("loadSaveFile failed: " .. sav)
end
emu:reset()

-- ---------------------------------------------------------------- constants

-- Off-roster fallback, i.e. what the map's own table would have produced.
-- Chosen by FAMILY BASE and re-checked after any roster change: Poochyena is
-- absent from Red, Falkner and Lance. If it ever joins Red's roster the
-- "ordinary encounter" battles stop being ordinary and this test starts lying.
local SPECIES_POOCHYENA = 261
local CHARACTER_RED = 1
local WILD_LEVEL = 10

local KIND_NORMAL    = 0
local KIND_ROSTER    = 1
local KIND_LEGENDARY = 2

-- B_WIN_MSG is 26 tiles wide (gStandardBattleWindowTemplates, src/battle_bg.c)
-- and the battle message prints at x = 0 with letterSpacing 0.
local MSG_WIDTH_PX = 26 * 8

local REQ_SET_CHARACTER = H.anchors.REQ.SET_CHARACTER
local REQ_WILD_BATTLE = H.anchors.REQ.WILD_BATTLE
local REQ_UNLOCK = H.anchors.REQ.UNLOCK
local REQ_OVERRIDE_WILD_BATTLE = H.anchors.REQ.OVERRIDE_WILD_BATTLE
local REQ_PLAIN_WILD_BATTLE = H.anchors.REQ.PLAIN_WILD_BATTLE
local REQ_BATTLE_STRING_WIDTH = H.anchors.REQ.BATTLE_STRING_WIDTH

if not REQ_OVERRIDE_WILD_BATTLE or not REQ_BATTLE_STRING_WIDTH
   or not REQ_PLAIN_WILD_BATTLE then
    error("anchors.lua predates the marker requests -- re-run gen_anchors.py")
end

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

local DEADLINE = 200000

-- ------------------------------------------------------------- mailbox pipe

local function mbRequest(req, a, b)
    H.wr16(MB + 6, a or 0)
    H.wr16(MB + 8, b or 0)
    H.wr32(MB + 12, 0)
    H.wr8(MB + 5, 0)
    H.wr8(MB + 4, req)
end

local function mbStatus() return H.rd8(MB + 5) end
local function mbResult() return H.rd32(MB + 12) end

-- --------------------------------------------------------------- game state

local function cb2()      return H.rd32(H.anchors.gMain + 4) end
local function onField()  return cb2() == H.anchors.CB2_Overworld + 1 end
local function inBattle() return cb2() == H.anchors.BattleMainCB2 + 1 end

-- ------------------------------------------------------------ charmap decode
--
-- gDisplayedStringBattle holds charmap bytes, not ASCII. Decoding rather than
-- comparing encoded blobs is deliberate: when this fails, the log has to show
-- the sentence the player would have read, or diagnosing it means hand-decoding
-- hex out of a suite log.

local DECODE = {}
do
    DECODE[0x00] = " "
    DECODE[0xAB] = "!"
    DECODE[0xAC] = "?"
    DECODE[0xAD] = "."
    DECODE[0xAE] = "-"
    DECODE[0xB4] = "'"
    DECODE[0xB8] = ","
    DECODE[0xBA] = "/"
    for i = 0, 9 do DECODE[0xA1 + i] = string.char(48 + i) end
    for i = 0, 25 do DECODE[0xBB + i] = string.char(65 + i) end
    for i = 0, 25 do DECODE[0xD5 + i] = string.char(97 + i) end
    -- Control codes kept VISIBLE. A line break in the wrong place is a real
    -- defect in a two-line box, so it must not decode to nothing.
    DECODE[0xFA] = "\\l"
    DECODE[0xFB] = "\\p"
    DECODE[0xFE] = "\\n"
end

local function readBattleString()
    local addr = H.anchors.gDisplayedStringBattle
    local bytes = emu:readRange(addr, 200)
    local out = {}
    for i = 1, #bytes do
        local b = string.byte(bytes, i)
        if b == 0xFF then break end   -- EOS
        out[#out + 1] = DECODE[b] or string.format("<%02X>", b)
    end
    return table.concat(out)
end

local function contains(hay, needle)
    return string.find(hay, needle, 1, true) ~= nil
end

-- ------------------------------------------------------------ state machine

local steps = {}
local stepIndex = 0
local stepStart = 0
local current = nil

local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end

local function mashEvery(f, key, every)
    if (f % every) == 0 then emu:addKey(key) else emu:clearKey(key) end
end

local function mbStep(name, req, a, b, onDone, timeoutFrames)
    local limit = timeoutFrames or 4000
    addStep(name,
        function() mbRequest(req, a, b) end,
        function(f)
            local s = mbStatus()
            if s == STATUS_REJECTED then
                H.assertTrue(name .. " (mailbox rejected the request)", false)
                return true
            end
            if s == STATUS_DONE then
                if onDone then onDone() end
                return true
            end
            if f - stepStart > limit then
                H.assertTrue(name .. " (mailbox answered)", false)
                return true
            end
            return false
        end)
end

-- ------------------------------------------------------------------- steps

addStep("continue to overworld", nil, function(f)
    if onField() and H.rd32(MB) == MB_MAGIC then
        emu:clearKey(H.KEY.A)
        return true
    end
    if f - stepStart > 200 then mashEvery(f, H.KEY.A, 25) end
    return false
end)

addStep("settle on the field", nil, function(f)
    if f - stepStart >= 240 then
        emu:clearKey(H.KEY.B)
        return true
    end
    mashEvery(f, H.KEY.B, 30)
    return false
end)

mbStep("enter Character Mode as Red", REQ_SET_CHARACTER, CHARACTER_RED, 0, function()
    H.assertEq("InCharacterMode() after SET_CHARACTER(1)", mbResult(), 1)
end)

-- One battle: start it, capture the FIRST intro string the game prints, measure
-- it with the game's own GetStringWidth, then run away and unlock the field.
--
-- The capture watches for "appeared" / "revealed": the intro window is redrawn
-- with later messages (the action prompt, "Go! X!") within a few frames, so a
-- single late sample reads whatever happened to be there. Taking the first
-- match instead makes the sample deterministic.
local function battle(label, req, argA, argB, wantSpeciesCheck, onString)
    local captured = nil
    local widthPx = nil
    local widthKind = nil
    local species = nil
    local kind = nil

    mbStep("[" .. label .. "] roll until the encounter kind comes up, then battle",
        req, argA, argB,
        function()
            local r = mbResult()
            if req == REQ_OVERRIDE_WILD_BATTLE then
                species = r % 65536
                kind = math.floor(r / 65536)
                H.assertTrue("[" .. label .. "] the roll produced the requested kind " ..
                             "(0 = it never came up in 3000 tries)", r ~= 0)
            elseif req == REQ_PLAIN_WILD_BATTLE then
                species = argA
                kind = r   -- the marker as it stood AFTER CreateWildMon
            else
                -- CM_REQ_WILD_BATTLE returns no result; the species is the one
                -- that was asked for and the kind must be NORMAL.
                species = argA
                kind = KIND_NORMAL
            end
            if wantSpeciesCheck then wantSpeciesCheck(species, kind) end
        end,
        -- 3000 attempts of a real roll + a real CreateWildMon happen inside one
        -- pump call, but VBlank keeps firing, so frames advance while it works.
        60000)

    addStep("[" .. label .. "] capture the battle intro string",
        function() captured = nil end,
        function(f)
            if inBattle() and captured == nil then
                local s = readBattleString()
                if contains(s, "appeared") or contains(s, "revealed") then
                    captured = s
                    H.log("[" .. label .. "] intro string: " .. s)
                end
            end
            if captured ~= nil then
                return true
            end
            if inBattle() then
                mashEvery(f, H.KEY.B, 37)
            end
            if f - stepStart > 20000 then
                H.assertTrue("[" .. label .. "] an intro string was printed", false)
                return true
            end
            return false
        end)

    mbStep("[" .. label .. "] measure the printed string with GetStringWidth",
        REQ_BATTLE_STRING_WIDTH, 0, 0,
        function()
            local r = mbResult()
            widthPx = r % 65536
            widthKind = math.floor(r / 65536)
        end)

    addStep("[" .. label .. "] assert the string", nil, function()
        if captured == nil then return true end   -- already failed above
        H.assertTrue("[" .. label .. "] widest line fits B_WIN_MSG (" ..
                     tostring(widthPx) .. " <= " .. MSG_WIDTH_PX .. " px)",
                     widthPx ~= nil and widthPx > 0 and widthPx <= MSG_WIDTH_PX)
        H.assertEq("[" .. label .. "] the measured string is the marked one",
                   widthKind, kind)
        onString(captured, species, kind)
        return true
    end)

    addStep("[" .. label .. "] run from the battle", nil, function(f)
        if not inBattle() and onField() then
            emu:clearKey(H.KEY.B)
            return true
        end
        if inBattle() then
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.B)
            emu:clearKey(H.KEY.DOWN)
            emu:clearKey(H.KEY.RIGHT)
            local cursor = H.rd8(H.anchors.gActionSelectionCursor)
            local tick = f % 24
            if tick == 0 then
                if cursor == 3 then
                    emu:addKey(H.KEY.A)
                elseif cursor == 2 then
                    emu:addKey(H.KEY.RIGHT)
                else
                    emu:addKey(H.KEY.DOWN)
                end
            elseif tick == 12 then
                emu:addKey(H.KEY.B)
            end
        end
        if f - stepStart > 20000 then
            H.assertTrue("[" .. label .. "] escaped the battle before deadline", false)
            return true
        end
        return false
    end)

    mbStep("[" .. label .. "] unlock the field", REQ_UNLOCK, 0, 0)
end

local function overrideArgB(kind) return WILD_LEVEL + kind * 256 end

-- 1. ORDINARY. The map table's own pick, no override. This is the baseline the
--    other four are measured against: if THIS one is already marked, the marker
--    is stuck on and every later "marker present" assertion is worthless.
battle("ordinary", REQ_OVERRIDE_WILD_BATTLE, SPECIES_POOCHYENA,
    overrideArgB(KIND_NORMAL),
    function(species, kind)
        H.assertEq("[ordinary] the table's species was kept", species, SPECIES_POOCHYENA)
        H.assertEq("[ordinary] encounter kind is NORMAL", kind, KIND_NORMAL)
    end,
    function(s)
        H.assertTrue("[ordinary] prints the vanilla line", contains(s, "Wild Poochyena appeared!"))
        H.assertTrue("[ordinary] does NOT say destined", not contains(s, "destined"))
        H.assertTrue("[ordinary] does NOT name the character", not contains(s, "Red"))
    end)

-- 2. ROSTER OVERRIDE. The 10% roll fired.
battle("roster", REQ_OVERRIDE_WILD_BATTLE, SPECIES_POOCHYENA,
    overrideArgB(KIND_ROSTER),
    function(species, kind)
        H.assertEq("[roster] encounter kind is ROSTER", kind, KIND_ROSTER)
        -- The whole reason the feature exists: what came back is a member of
        -- Red's roster, not the map's pick -- and without the message the
        -- player has no way to know that happened.
        H.assertTrue("[roster] the override replaced the table's species",
                     species ~= SPECIES_POOCHYENA and species ~= 0)
    end,
    function(s)
        H.assertTrue("[roster] says destined for", contains(s, "destined for"))
        H.assertTrue("[roster] names the character", contains(s, "Red"))
        H.assertTrue("[roster] is NOT the vanilla line",
                     not contains(s, "Wild Poochyena appeared!"))
        H.assertTrue("[roster] breaks the line rather than running on",
                     contains(s, "\\n"))
    end)

-- 3. THE NON-STICKY CONTROL, and the reason this run is worth having. An
--    ordinary encounter immediately after a marked one. A marker that is set
--    and never cleared passes steps 1 and 2 and fails here; so does one whose
--    clear happens in the wrong place. This is the in-band control -- it goes
--    red in EVERY future run, not just at the commit that broke it.
battle("ordinary-after-marked", REQ_OVERRIDE_WILD_BATTLE, SPECIES_POOCHYENA,
    overrideArgB(KIND_NORMAL),
    function(species, kind)
        H.assertEq("[ordinary-after-marked] encounter kind fell back to NORMAL",
                   kind, KIND_NORMAL)
    end,
    function(s)
        H.assertTrue("[ordinary-after-marked] the marker did NOT stick",
                     not contains(s, "destined") and not contains(s, "revealed"))
        H.assertTrue("[ordinary-after-marked] prints the vanilla line",
                     contains(s, "Wild Poochyena appeared!"))
    end)

-- 4. THE 1% LEGENDARY. A different sentence, so a single shared marker string
--    cannot satisfy both this and step 2.
battle("legendary", REQ_OVERRIDE_WILD_BATTLE, SPECIES_POOCHYENA,
    overrideArgB(KIND_LEGENDARY),
    function(species, kind)
        H.assertEq("[legendary] encounter kind is LEGENDARY", kind, KIND_LEGENDARY)
        H.assertTrue("[legendary] a legendary species was produced",
                     species ~= SPECIES_POOCHYENA and species ~= 0)
    end,
    function(s)
        H.assertTrue("[legendary] says revealed itself", contains(s, "revealed itself"))
        H.assertTrue("[legendary] names the character", contains(s, "Red"))
        H.assertTrue("[legendary] is NOT the roster override line",
                     not contains(s, "destined"))
    end)

-- 5. THE SCRIPTED-SPAWN CONTROL. CreateScriptedWildMon does not go through
--    CreateWildMon, so it clears the marker itself. Without that line, the
--    Alpha boss or static legendary you walk into after a roster override
--    would be announced as destined for your character.
battle("scripted", REQ_WILD_BATTLE, SPECIES_POOCHYENA, WILD_LEVEL,
    nil,
    function(s)
        H.assertTrue("[scripted] a scripted spawn is never marked",
                     not contains(s, "destined") and not contains(s, "revealed"))
        H.assertTrue("[scripted] prints the vanilla line",
                     contains(s, "Wild Poochyena appeared!"))
    end)

-- 6. THE NON-OVERRIDE WILD PATH. The mailbox sets the marker to ROSTER and then
--    makes the mon with a bare CreateWildMon -- the shape of the mass outbreak,
--    the Feebas spot, DexNav and the in-game trade mon. None of those goes
--    through CreateWildMonWithCharacterOverride, so the ONLY thing that can
--    unmark them is CreateWildMon's own clear. Delete that line and this is the
--    battle that goes red; the other five do not.
battle("plain-wild-after-marked", REQ_PLAIN_WILD_BATTLE, SPECIES_POOCHYENA, WILD_LEVEL,
    function(species, kind)
        H.assertEq("[plain-wild-after-marked] CreateWildMon cleared a marker " ..
                   "that was deliberately left set", kind, KIND_NORMAL)
    end,
    function(s)
        H.assertTrue("[plain-wild-after-marked] an outbreak/DexNav/Feebas mon " ..
                     "is never marked",
                     not contains(s, "destined") and not contains(s, "revealed"))
        H.assertTrue("[plain-wild-after-marked] prints the vanilla line",
                     contains(s, "Wild Poochyena appeared!"))
    end)

-- -------------------------------------------------------------------- pump

local finished = false

H.onFrame(function(f)
    if finished then return end

    if f >= DEADLINE then
        finished = true
        H.assertTrue("finished all steps before global deadline (stuck at: " ..
                     (current and current.name or "?") .. ")", false)
        H.finish()
        return
    end

    if current == nil then
        stepIndex = stepIndex + 1
        current = steps[stepIndex]
        if current == nil then
            finished = true
            H.finish()
            return
        end
        stepStart = f
        H.log(string.format("STEP %d/%d: %s (frame %d)",
                            stepIndex, #steps, current.name, f))
        if current.enter then current.enter(f) end
    end

    if current.tick and current.tick(f) then
        current = nil
    end
end)
