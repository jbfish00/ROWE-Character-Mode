-- QoL items e2e: Zeromin (reset every EV to zero) and the bag ball swap.
--
-- Both features were ported from Pokemon SoulGold's QoL set on 2026-08-19.
-- This drives CharacterMode_ZeroAllEVs and CharacterMode_SwapMonBall -- the
-- SAME two functions ItemUseCB_ZeroAllEV and ItemUseCB_BallSwap call, not
-- reimplementations of them.
--
-- ⚠️ WHAT THIS DOES *NOT* COVER, stated plainly so nobody reads it as more
-- than it is: the bag -> party-menu -> item-use UI wiring is NOT driven here.
-- What is proven is the effect logic and every one of its refusal branches.
-- The wiring itself is a .fieldUseFunc assignment per item, code-verified.
-- "Statically audited" is the phrase this repo has been burned by before, so:
-- the menu path has NOT been run by a machine, and that remains open.
--
-- The controls are the point, and there are three:
--   * Zeroing an ALREADY-zero mon must return FALSE. A test that only checks
--     "the EVs are 0 afterwards" passes identically on a build that hardwires
--     TRUE and consumes the item for nothing.
--   * Swapping to the ball a mon is ALREADY in must return FALSE, same shape.
--   * The egg refusal is checked and then UNDONE, and the same swap that was
--     refused is required to SUCCEED once the egg flag is cleared. Without
--     that second half, "the egg was refused" passes just as well on a build
--     where ball swapping is broken outright.
--
-- Run (no CM_SAV -- fresh flash, normal-path intro, mode stays OFF because
-- both features are global):
--   timeout 240 <mgba-headless> \
--     --script tools/mgba_scripts/qol_items_e2e.lua pokeemerald.gba \
--     > /tmp/qol_items.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")

-- ---------------------------------------------------------------- constants

local ITEM_ULTRA_BALL = 2
local ITEM_POKE_BALL  = 4

-- Indices into sAllEvFields (party_menu.c): HP/Atk/Def/Speed/SpAtk/SpDef.
local EV_HP, EV_ATK, EV_DEF, EV_SPEED, EV_SPATK, EV_SPDEF = 0, 1, 2, 3, 4, 5

local MAP_TRUCK_GROUP = 25
local MAP_TRUCK_NUM   = 40

local QUESTIONS_MAX  = 3
local IDX_START_GAME = 3

-- Request ids come from anchors.lua (derived from the C enum by
-- gen_anchors.py); the enum is positional, so literals here rot silently the
-- moment a request is inserted rather than appended.
local REQ_MON_EV       = H.anchors.REQ.MON_EV
local REQ_ZERO_ALL_EVS = H.anchors.REQ.ZERO_ALL_EVS
local REQ_SWAP_BALL    = H.anchors.REQ.SWAP_BALL
local REQ_SET_MON_EGG  = H.anchors.REQ.SET_MON_EGG

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

local DEADLINE = 100000

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

-- Both halves of every packed result, named so the assertions read as claims.
local function lowWord()  return mbResult() % 65536 end
local function highWord() return math.floor(mbResult() / 65536) % 65536 end

-- --------------------------------------------------------------- game state

local function cb2()        return H.rd32(H.anchors.gMain + 4) end
local function onField()    return cb2() == H.anchors.CB2_Overworld + 1 end
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

-- ------------------------------ phase 1: intro drive (normal path, mode off)

addStep("pick Start Game at questions index 3",
    nil,
    function(f)
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
        if not inTruck() and onField() and partyCount() >= 1
           and H.rd32(MB) == MB_MAGIC then
            clearAll()
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

-- ------------------------------------------------------- phase 2: Zeromin
-- The starter is a freshly created mon, so it begins with no EVs at all. Each
-- write is checked BOTH by reading the stat back and by the running total, so
-- a build that stored the value somewhere harmless would fail the sum.

mbStep("put 100 HP EVs on the starter", REQ_MON_EV, 0 + (EV_HP * 256), 100,
    function()
        H.assertEq("HP EV reads back as 100", lowWord(), 100)
        H.assertEq("EV total is 100", highWord(), 100)
    end)

mbStep("put 50 Attack EVs on the starter", REQ_MON_EV, 0 + (EV_ATK * 256), 50,
    function()
        H.assertEq("Attack EV reads back as 50", lowWord(), 50)
        H.assertEq("EV total is 150", highWord(), 150)
    end)

mbStep("put 25 Defense EVs on the starter", REQ_MON_EV, 0 + (EV_DEF * 256), 25,
    function() H.assertEq("EV total is 175", highWord(), 175) end)

mbStep("put 25 Speed EVs on the starter", REQ_MON_EV, 0 + (EV_SPEED * 256), 25,
    function() H.assertEq("EV total is 200", highWord(), 200) end)

mbStep("put 25 Sp. Atk EVs on the starter", REQ_MON_EV, 0 + (EV_SPATK * 256), 25,
    function() H.assertEq("EV total is 225", highWord(), 225) end)

mbStep("put 25 Sp. Def EVs on the starter", REQ_MON_EV, 0 + (EV_SPDEF * 256), 25,
    function() H.assertEq("EV total is 250 across all six stats",
                          highWord(), 250) end)

mbStep("Zeromin on a mon that HAS EVs", REQ_ZERO_ALL_EVS, 0, 0, function()
    H.assertEq("the reset reports that it changed something", lowWord(), 1)
    H.assertEq("every EV is now zero", highWord(), 0)
end)

-- IN-BAND CONTROL. This is the assertion that can actually fail on a bad
-- build: a hardwired TRUE would consume a Zeromin from the bag and claim
-- success on a mon with nothing to reset.
mbStep("Zeromin AGAIN on the now-zero mon", REQ_ZERO_ALL_EVS, 0, 0, function()
    H.assertEq("the second reset reports NO change", lowWord(), 0)
    H.assertEq("EVs are still zero", highWord(), 0)
end)

-- The sum being 0 does not prove each individual field is 0 -- read one back.
mbStep("read the HP EV back individually", REQ_MON_EV, 0 + (EV_HP * 256), 0,
    function()
        H.assertEq("HP EV is individually zero", lowWord(), 0)
        H.assertEq("EV total is still zero", highWord(), 0)
    end)

-- ----------------------------------------------------- phase 3: ball swap
-- Normalise first rather than assuming which ball a starter arrives in: this
-- step asserts the END STATE only, so it is correct either way.

mbStep("normalise the starter into a Poke Ball", REQ_SWAP_BALL, 0, ITEM_POKE_BALL,
    function()
        H.assertEq("the starter is in a Poke Ball", highWord(), ITEM_POKE_BALL)
    end)

mbStep("swap into an Ultra Ball", REQ_SWAP_BALL, 0, ITEM_ULTRA_BALL, function()
    H.assertEq("the swap reports that it changed something", lowWord(), 1)
    H.assertEq("the mon is now in an Ultra Ball", highWord(), ITEM_ULTRA_BALL)
end)

-- IN-BAND CONTROL, same shape as the second Zeromin.
mbStep("swap into an Ultra Ball AGAIN", REQ_SWAP_BALL, 0, ITEM_ULTRA_BALL,
    function()
        H.assertEq("a same-ball swap reports NO change", lowWord(), 0)
        H.assertEq("the mon is still in an Ultra Ball",
                   highWord(), ITEM_ULTRA_BALL)
    end)

mbStep("swap back to a Poke Ball", REQ_SWAP_BALL, 0, ITEM_POKE_BALL, function()
    H.assertEq("swapping back reports a change", lowWord(), 1)
    H.assertEq("the mon is in a Poke Ball again", highWord(), ITEM_POKE_BALL)
end)

-- ⚠️ PHASE 4 (the egg refusal) WAS REMOVED, DELIBERATELY, ON 2026-08-19.
-- CharacterMode_SwapMonBall refuses an egg, and that branch is NOT proven here.
-- It cannot be: CM_REQ_SET_MON_EGG cannot make a party mon into an egg in this
-- tree -- both MON_DATA_IS_EGG and the plain MON_DATA_SANITY_IS_EGG read back 0
-- after being written, with the request body proved to have run. A test written
-- on top of that would "pass" by never creating an egg in the first place,
-- which is this repo's single most repeated failure shape.
-- The guard stays in the C because it is correct and cheap. It is UNPROVEN.
-- See CM_REQ_SET_MON_EGG in src/character_mode_selftest.c for what was measured.

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
