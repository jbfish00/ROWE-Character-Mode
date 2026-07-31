-- character_select_e2e.lua -- pick a character that is NOT the default, and
-- prove the commit grants THAT character's fixed starter.
--
-- Closes two playthrough checklist items that nothing else touched:
--
--   item 3   "scroll to your character -> START commits the selection".
--            Every other drive in this suite commits the DEFAULT Gen I/Red
--            pick, so the scrolling half of the only selection mechanism the
--            game has was completely unproven.
--   item 16  "Tobias's starter is always Darkrai, never Latios."
--            audit_rosters.py pins the DATA (his roster[0] is Darkrai), but
--            nothing ever drove the grant. This does.
--
-- WHY TOBIAS. His roster is [DARKRAI, LATIOS] -- all legendary -- so
-- ui_mode_menu.c's RandomizeStarterSelection takes the `starterCount == 0`
-- branch and hands out roster[0] instead of rolling. Before 2026-07-28 it fell
-- through to `Random() % GetNumStarters()` and he got a *coin flip* between two
-- legendaries. He is also the only character in ROWE in that state.
--
-- HOW HE IS REACHED, and why it is one keypress and not 232.
-- CycleCharacter() skips entries whose generation does not match genSelection,
-- and WRAPS (sel < 1 -> GetCharacterCount()). Tobias is character 233 of 236
-- but the LAST selectable character in generation 4 -- so from anywhere in gen
-- 4, a single LEFT wraps straight onto him. Walking forwards would be 28 taps
-- and would prove nothing extra.
--
-- ⚠️ THE STEERING IS CLOSED-LOOP, AND THAT IS NOT OPTIONAL. mGBA drops short
-- taps, so "press LEFT once" is a wish, not an instruction -- a fixed count
-- lands somewhere different every run. gen_anchors.py now exports
-- ui_mode_menu.c's file-static cursorRow / genSelection / characterSelection,
-- so every phase below reads where the menu ACTUALLY is, presses only while it
-- is not where it should be, and fails loudly if it stops converging. This is
-- the same lesson gTestMenuPtr taught the intro drive.
--
-- Run:
--   timeout 300 <mgba-headless> \
--       --script tools/mgba_scripts/character_select_e2e.lua pokeemerald.gba

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local REQ_QUERY_PARTY_MON = H.anchors.REQ.QUERY_PARTY_MON
local REQ_QUERY_FLAG      = H.anchors.REQ.QUERY_FLAG
local REQ_QUERY_VAR       = H.anchors.REQ.QUERY_VAR

local FLAG_CHARACTER_MODE = 9135
local VAR_CHARACTER_ID    = 17001

local SPECIES_DARKRAI = 491
local SPECIES_LATIOS  = 381

-- Tobias: 1-based index into gCharacters, generation 4, last selectable in it.
local TOBIAS_ID   = 233
local TOBIAS_GEN  = 4
local ROW_GEN     = 3   -- cursorRow for the Generation row
local ROW_CHAR    = 4   -- cursorRow for the Character row

local function cursorRow()          return H.rd8(H.anchors.cursorRow) end
local function genSelection()       return H.rd8(H.anchors.genSelection) end
local function characterSelection() return H.rd16(H.anchors.characterSelection) end
local function starterSelection()   return H.rd8(H.anchors.starterselection) end

-- ---------------------------------------------------------------- the drive

D.questionsPick("pick Character Mode at questions index 2",
    D.IDX_CHARACTER_MODE,
    function() return not D.onField() end)

-- Steer the open menu to Tobias, then hold still. Four phases, each with its
-- own convergence budget so a stuck phase names ITSELF instead of timing out
-- the whole step with no clue which control stopped responding.
local phase, phaseStart, settleAt = 1, nil, nil
local reached = {}

D.addStep("steer the character menu to Tobias (gen 4, wrap onto the last entry)",
    nil,
    function(f)
        D.heartbeat(f)
        local age = f - D.stepStart()
        -- Let the menu finish loading; genSelection is only set on open.
        if age < 400 then return false end
        phaseStart = phaseStart or f

        if age > 30000 then
            H.assertTrue("steering converged (stuck in phase " .. phase .. ")", false)
            return true
        end
        -- Each phase gets 4000 frames. Overrunning one is a real failure: it
        -- means a control that used to respond has stopped.
        if f - phaseStart > 4000 then
            H.assertTrue(string.format(
                "phase %d converged (cursorRow=%d gen=%d char=%d)",
                phase, cursorRow(), genSelection(), characterSelection()), false)
            return true
        end

        if phase == 1 then                      -- cursor onto the Generation row
            if cursorRow() == ROW_GEN then
                reached.gotGenRow = true
                phase, phaseStart = 2, f
                D.clearAll()
            elseif cursorRow() < ROW_GEN then
                D.tapEvery(f, H.KEY.DOWN, 21)
            else
                D.tapEvery(f, H.KEY.UP, 21)
            end
        elseif phase == 2 then                  -- generation -> 4
            if genSelection() == TOBIAS_GEN then
                reached.gotGen = true
                phase, phaseStart = 3, f
                D.clearAll()
            else
                D.tapEvery(f, H.KEY.RIGHT, 21)
            end
        elseif phase == 3 then                  -- cursor onto the Character row
            if cursorRow() == ROW_CHAR then
                reached.gotCharRow = true
                phase, phaseStart = 4, f
                D.clearAll()
            elseif cursorRow() < ROW_CHAR then
                D.tapEvery(f, H.KEY.DOWN, 21)
            else
                D.tapEvery(f, H.KEY.UP, 21)
            end
        else                                    -- wrap backwards onto Tobias
            if characterSelection() == TOBIAS_ID then
                D.clearAll()
                settleAt = settleAt or f
                -- Hold still briefly: a press still buffered when we stop
                -- steering would cycle us off him again, and the commit would
                -- silently grant somebody else's starter.
                if f - settleAt > 120 then
                    H.log(string.format(
                        "settled on character %d (gen %d, starterselection %d)",
                        characterSelection(), genSelection(), starterSelection()))
                    return true
                end
            else
                settleAt = nil
                D.tapEvery(f, H.KEY.LEFT, 21)
            end
        end
        return false
    end)

D.addStep("the menu really is on Tobias before committing",
    nil,
    function()
        H.assertTrue("reached the Generation row", reached.gotGenRow == true)
        H.assertEq("genSelection is 4", genSelection(), TOBIAS_GEN)
        H.assertTrue("reached the Character row", reached.gotCharRow == true)
        H.assertEq("characterSelection is Tobias (233)",
                   characterSelection(), TOBIAS_ID)
        -- roster[0], i.e. the fixed-starter branch. If this is non-zero the
        -- Random() fallthrough is back and the grant below is a coin flip.
        H.assertEq("starterselection is 0 (the fixed roster[0] branch)",
                   starterSelection(), 0)
        return true
    end)

D.addStep("START commits Tobias; the starter is granted at commit",
    nil,
    function(f)
        D.heartbeat(f)
        if D.partyCount() == 1 then
            D.clearAll()
            H.log("commit grant seen at frame " .. f)
            return true
        end
        if f - D.stepStart() > 20000 then
            H.assertTrue("mode-menu commit granted Tobias's starter", false)
            return true
        end
        D.tapEvery(f, H.KEY.START, 47)
        return false
    end)

D.questionsPick("pick Start Game at questions index 3 (after the commit)",
    D.IDX_START_GAME,
    function()
        return D.menuMax() ~= D.QUESTIONS_MAX or not D.inTruck()
    end)

-- Reuse the wall-clock-aware overworld walk. The clock's yes/no defaults to NO,
-- so a plain A-mash cycles confirm-open -> pick-NO forever.
local upTries = 0
D.addStep("reach the overworld outside the truck",
    nil,
    function(f)
        D.heartbeat(f)
        if not D.inTruck() and D.onField() and D.partyCount() >= 1
           and D.mbAlive() then
            D.clearAll()
            H.log("overworld reached at frame " .. f)
            return true
        end
        if f - D.stepStart() > 40000 then
            H.assertTrue("reached the overworld before step timeout", false)
            return true
        end
        if D.cb2() >= H.anchors.CB2_StartWallClock
           and D.cb2() < H.anchors.CB2_StartWallClock + 0x800 then
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.UP)
            if (f % 21) == 0 then
                if D.menuCur() == 0 then
                    emu:addKey(H.KEY.A)
                elseif upTries < 3 then
                    emu:addKey(H.KEY.UP)
                    upTries = upTries + 1
                else
                    emu:addKey(H.KEY.A)
                    upTries = 0
                end
            end
            return false
        end
        emu:clearKey(H.KEY.UP)
        D.tapEvery(f, H.KEY.A, 31)
        return false
    end)

D.addStep("settle on the field", nil, function(f)
    if f - D.stepStart() >= 300 then D.clearAll(); return true end
    D.tapEvery(f, H.KEY.B, 30)
    return false
end)

-- ------------------------------------------------------------- the verdict

D.addStep("party count is exactly 1", nil, function()
    H.assertEq("party count is exactly 1", D.partyCount(), 1)
    return true
end)

D.mbStep("query CM flag", REQ_QUERY_FLAG, FLAG_CHARACTER_MODE, 0, function()
    H.assertEq("FLAG_CHARACTER_MODE set", D.mbResult(), 1)
end)

D.mbStep("query character id", REQ_QUERY_VAR, VAR_CHARACTER_ID, 0, function()
    -- The whole point: a NON-default character survived the commit. Red is 1.
    H.assertEq("VAR_CHARACTER_ID == 233 (Tobias, not the default Red)",
               D.mbResult(), TOBIAS_ID)
end)

D.mbStep("query party slot 0", REQ_QUERY_PARTY_MON, 0, 0, function()
    local r = D.mbResult()
    local species = r % 65536
    H.assertEq("slot 0 species is DARKRAI (Tobias roster[0])",
               species, SPECIES_DARKRAI)
    -- Stated separately so a regression reads as what it is. Before the
    -- 2026-07-28 fix this was Random() % 2 over the two, and a run that
    -- happened to roll Darkrai looked identical to a correct one.
    H.assertTrue("slot 0 is NOT Latios (the old coin flip's other face)",
                 species ~= SPECIES_LATIOS)
    H.assertEq("slot 0 level is 10", math.floor(r / 65536), 10)
end)

-- NB: D.run() calls H.finish() itself when the steps run out or the deadline
-- hits. Calling H.finish() here as well fires it IMMEDIATELY at script load,
-- emitting a `PASSED 0, FAILED 0 / RESULT: PASS` summary before a single
-- frame has run -- which a runner reading the last RESULT line would report
-- as a pass if the real run then wedged. Do not add it back.
D.run()
