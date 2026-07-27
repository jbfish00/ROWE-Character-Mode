-- Johto-leader-as-player gym e2e: plays AS Falkner (character 28) and beats
-- FALKNER'S OWN gym script, proving the Phase 6 "Johto-leader-as-player vs
-- their gym scripts" item:
--   * the leader script runs to completion with the player character set to
--     that same leader (static audit says no gym script reads CM state --
--     this is the live confirmation),
--   * the badge chain fires: FLAG_BADGE09_GET (Zephyr) + the count-based
--     FLAG_GOT_BADGE_01 + VAR_NUM_BADGES 0 -> 1,
--   * bonus CM coverage: the gift gate accepts Falkner's roster (Aerodactyl
--     -> party) and still blocks off-roster (Meowth -> PC) while playing a
--     Johto leader.
--
-- Vehicle: the proven starter_regression normal-path intro drive (fresh
-- flash -> Littleroot with a Meowth starter), then the test mailbox sets
-- character 28, gifts a Lv100 Aerodactyl (last-4 learnset moves are all
-- damaging -- safe for a blind FIGHT/A drive), faints the Meowth lead so
-- the battle auto-sends Aerodactyl, switches battle style to SET (no switch
-- prompt to wedge on), and runs Common_Eventscript_Gym_Leader_Falkner
-- directly (trainerbattle works from any map; faceplayer no-ops).
--
-- Run:
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/johto_gym_e2e.lua pokeemerald.gba \
--     > /tmp/johto_gym.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")

-- ---------------------------------------------------------------- constants

local SPECIES_MEOWTH     = 52
local SPECIES_AERODACTYL = 142

local CHAR_FALKNER = 28          -- 1-based gCharacters index

local FLAG_CHARACTER_MODE   = 9135
local FLAG_BADGE09_GET      = 676    -- FLAG_RECEIVED_BADGE_09 (Zephyr)
local FLAG_GOT_BADGE_01     = 3620   -- count-based award at 0 prior badges
local VAR_NUM_BADGES        = 0x4061

local MAP_TRUCK_GROUP = 25
local MAP_TRUCK_NUM   = 40

local QUESTIONS_MAX  = 3
local IDX_START_GAME = 3

-- Request ids come from anchors.lua (derived from the C enum by
-- gen_anchors.py); the enum is positional, so literals here rot
-- silently the moment a request is inserted rather than appended.
local REQ_SET_CHARACTER = H.anchors.REQ.SET_CHARACTER
local REQ_GIVE_MON = H.anchors.REQ.GIVE_MON
local REQ_UNLOCK = H.anchors.REQ.UNLOCK
local REQ_QUERY_PARTY_MON = H.anchors.REQ.QUERY_PARTY_MON
local REQ_QUERY_FLAG = H.anchors.REQ.QUERY_FLAG
local REQ_QUERY_VAR = H.anchors.REQ.QUERY_VAR
local REQ_RUN_SCRIPT = H.anchors.REQ.RUN_SCRIPT
local REQ_SET_MON_HP = H.anchors.REQ.SET_MON_HP
local REQ_SET_BATTLE_STYLE = H.anchors.REQ.SET_BATTLE_STYLE

local MON_GIVEN_TO_PARTY = 0
local MON_GIVEN_TO_PC    = 1

local B_OUTCOME_WON = 1

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

local DEADLINE = 150000

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

local function cb2()        return H.rd32(H.anchors.gMain + 4) end
local function onField()    return cb2() == H.anchors.CB2_Overworld + 1 end
local function inBattle()   return cb2() == H.anchors.BattleMainCB2 + 1 end
local function partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

local function mapGroup() return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 4) end
local function mapNum()   return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 5) end
local function inTruck()
    return mapGroup() == MAP_TRUCK_GROUP and mapNum() == MAP_TRUCK_NUM
end

local function menuAddr()  return H.rd32(H.anchors.gTestMenuPtr) end
local function menuCur()   return H.rd8(menuAddr() + 2) end
local function menuMax()   return H.rd8(menuAddr() + 4) end
local function poisonMenu() H.wr8(menuAddr() + 4, 0x7F) end

-- ------------------------------------------------------------ state machine

local steps = {}
local stepIndex = 0
local stepStart = 0
local current = nil

local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end

local function tapEvery(f, key, every, phase)
    if (f % every) == (phase or 0) then emu:addKey(key) else emu:clearKey(key) end
end

local function clearAll()
    for _, k in pairs(H.KEY) do emu:clearKey(k) end
end

local function heartbeat(f)
    if (f % 1000) == 0 then
        H.log(string.format(
            "hb f=%d cb2=%s field=%s battle=%s map=%d/%d party=%d",
            f, H.hex(cb2()), tostring(onField()), tostring(inBattle()),
            mapGroup(), mapNum(), partyCount()))
    end
end

local function mbStep(name, req, a, b, onDone)
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
            if f - stepStart > 2000 then
                H.assertTrue(name .. " (mailbox answered)", false)
                return true
            end
            return false
        end)
end

-- ------------------------------- phase 1: intro drive (starter_regression)

addStep("pick Start Game at questions index 3",
    nil,
    function(f)
        heartbeat(f)
        if f - stepStart > 30000 then
            H.assertTrue("picked Start Game before step timeout", false)
            return true
        end
        local menuUp = inTruck() and menuMax() == QUESTIONS_MAX
        if not menuUp then
            tapEvery(f, H.KEY.A, 29)
            tapEvery(f, H.KEY.START, 173)
            return false
        end
        emu:clearKey(H.KEY.START)
        if (f % 17) == 0 then
            local cur = menuCur()
            if cur < IDX_START_GAME then
                emu:addKey(H.KEY.DOWN)
            elseif cur > IDX_START_GAME then
                emu:addKey(H.KEY.UP)
            else
                emu:addKey(H.KEY.A)
                poisonMenu()
                clearAll()
                return true
            end
        else
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.DOWN)
            emu:clearKey(H.KEY.UP)
        end
        return false
    end)

local upTries = 0
addStep("reach the overworld outside the truck",
    nil,
    function(f)
        heartbeat(f)
        if not inTruck() and onField() and partyCount() >= 1
           and H.rd32(MB) == MB_MAGIC then
            clearAll()
            H.log("overworld reached at frame " .. f ..
                  " map " .. mapGroup() .. "/" .. mapNum())
            return true
        end
        if f - stepStart > 40000 then
            H.assertTrue("reached the overworld before step timeout", false)
            return true
        end
        if cb2() >= H.anchors.CB2_StartWallClock
           and cb2() < H.anchors.CB2_StartWallClock + 0x800 then
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.UP)
            if (f % 21) == 0 then
                if menuCur() == 0 then
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
        tapEvery(f, H.KEY.A, 31)
        return false
    end)

addStep("settle on the field",
    nil,
    function(f)
        if f - stepStart >= 300 then
            clearAll()
            return true
        end
        tapEvery(f, H.KEY.B, 30)
        return false
    end)

-- --------------------------------- phase 2: become Falkner, arm the party

mbStep("battle style = SET", REQ_SET_BATTLE_STYLE, 1, 0, function()
    H.assertEq("optionsBattleStyle == SET", mbResult(), 1)
end)

mbStep("enter Character Mode as Falkner", REQ_SET_CHARACTER, CHAR_FALKNER, 0,
    function()
        H.assertEq("InCharacterMode() after SET_CHARACTER(28)", mbResult(), 1)
    end)

mbStep("gift Lv100 Aerodactyl (on Falkner's roster)", REQ_GIVE_MON,
    SPECIES_AERODACTYL, 100, function()
        H.assertEq("Aerodactyl gift joined the party (roster allows)",
                   mbResult(), MON_GIVEN_TO_PARTY)
    end)

mbStep("gift off-roster Meowth (control)", REQ_GIVE_MON, SPECIES_MEOWTH, 10,
    function()
        H.assertEq("off-roster Meowth routed to PC while playing Falkner",
                   mbResult(), MON_GIVEN_TO_PC)
    end)

mbStep("faint the Meowth lead", REQ_SET_MON_HP, 0, 0, function()
    H.assertEq("slot 0 HP forced to 0", mbResult(), 0)
end)

mbStep("badge 9 flag clear before the fight", REQ_QUERY_FLAG,
    FLAG_BADGE09_GET, 0, function()
        H.assertEq("FLAG_BADGE09_GET clear pre-battle", mbResult(), 0)
    end)

mbStep("badge count var 0 before the fight", REQ_QUERY_VAR, VAR_NUM_BADGES, 0,
    function()
        H.assertEq("VAR_NUM_BADGES == 0 pre-battle", mbResult(), 0)
    end)

-- --------------------------------------- phase 3: run Falkner's gym script

mbStep("run Common_Eventscript_Gym_Leader_Falkner", REQ_RUN_SCRIPT,
    H.anchors.Common_Eventscript_Gym_Leader_Falkner % 65536,
    math.floor(H.anchors.Common_Eventscript_Gym_Leader_Falkner / 65536))

-- Dialogue -> trainerbattle_no_intro(TRAINER_LEADER_FALKNER). Drive: mash A
-- to the battle, then steer the action cursor to FIGHT and A the first move
-- (Fly/Rock Slide/Hyper Beam/Giga Impact -- all damaging). SET style means
-- no switch prompt; the fainted Meowth lead means Aerodactyl auto-sends.
addStep("win the Falkner battle",
    nil,
    function(f)
        heartbeat(f)
        if f - stepStart > 60000 then
            H.assertTrue("Falkner battle resolved before step timeout", false)
            return true
        end
        if inBattle() then
            local outcome = H.rd8(H.anchors.gBattleOutcome)
            if outcome ~= 0 then
                -- battle decided; mash through the outro text
                tapEvery(f, H.KEY.A, 33)
                return false
            end
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.LEFT)
            emu:clearKey(H.KEY.UP)
            if (f % 23) == 0 then
                local cursor = H.rd8(H.anchors.gActionSelectionCursor)
                if cursor == 0 then
                    emu:addKey(H.KEY.A)      -- FIGHT, then move 0
                elseif cursor == 1 then
                    emu:addKey(H.KEY.LEFT)
                else
                    emu:addKey(H.KEY.UP)
                end
            end
            return false
        end
        if onField() and H.rd8(H.anchors.gBattleOutcome) ~= 0 then
            clearAll()
            H.assertEq("Falkner battle outcome == B_OUTCOME_WON",
                       H.rd8(H.anchors.gBattleOutcome), B_OUTCOME_WON)
            return true
        end
        tapEvery(f, H.KEY.A, 29)  -- pre-battle leader dialogue
        return false
    end)

-- Post-battle: badge speech, fanfares, count-based item, random gift. Mash A
-- and poll the Zephyr badge flag until it sets.
local pollOut = false
addStep("mash to the badge award (poll FLAG_BADGE09_GET)",
    nil,
    function(f)
        heartbeat(f)
        if f - stepStart > 40000 then
            H.assertTrue("badge flag set before step timeout", false)
            return true
        end
        tapEvery(f, H.KEY.A, 29)
        if not pollOut and (f % 401) == 0 then
            mbRequest(REQ_QUERY_FLAG, FLAG_BADGE09_GET, 0)
            pollOut = true
        elseif pollOut and mbStatus() == STATUS_DONE then
            pollOut = false
            if mbResult() == 1 then
                clearAll()
                H.assertTrue("FLAG_BADGE09_GET set after the win", true)
                return true
            end
        end
        return false
    end)

-- Let the tail of the script (gifts, heal, release) finish under an A-mash.
addStep("finish the gym script",
    nil,
    function(f)
        if f - stepStart >= 3000 then
            clearAll()
            return true
        end
        tapEvery(f, H.KEY.A, 29)
        return false
    end)

mbStep("unlock the field", REQ_UNLOCK, 0, 0)

-- --------------------------------------------------- phase 4: final asserts

mbStep("count-based badge flag", REQ_QUERY_FLAG, FLAG_GOT_BADGE_01, 0,
    function()
        H.assertEq("FLAG_GOT_BADGE_01 set (count-based award)", mbResult(), 1)
    end)

mbStep("badge count var", REQ_QUERY_VAR, VAR_NUM_BADGES, 0, function()
    H.assertEq("VAR_NUM_BADGES == 1 after Falkner", mbResult(), 1)
end)

mbStep("CM still on", REQ_QUERY_FLAG, FLAG_CHARACTER_MODE, 0, function()
    H.assertEq("FLAG_CHARACTER_MODE still set", mbResult(), 1)
end)

addStep("party unchanged by the gym rewards",
    nil,
    function()
        H.assertEq("party count still 2 (Meowth + Aerodactyl)",
                   partyCount(), 2)
        return true
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
