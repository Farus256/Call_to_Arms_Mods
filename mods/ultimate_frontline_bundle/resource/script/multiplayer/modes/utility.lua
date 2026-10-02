-- Utility variables for various game modes

printDebug = true
printTempDebug = false

spawnPoint = BotApi.Instance.spawnPointName
spawnSide = string.sub(spawnPoint,1,1)
gameMode = BotApi.Instance.gameMode
enemyTeam = BotApi.Instance.enemyTeam
team = BotApi.Instance.team
teamSize = BotApi.Instance.ownTeamSize

MaxSquadSize = 0
gameModeSpawnTimer = 0
Purchases = {}
PIter = {}
PIter.__index = PIter

FlagOwnership = {
    Allied = 1,
    Opponent = 2,
    Neutral = 3
}

-- Is the flag located on the bot's team side of the map, enemies side of the map, or on the center line
FlagLocation = {
    Enemy = 1,
    Friendly = 3,
    Center = 6,
    EnemyBase = 1,
    FriendlyBase = 5,
    EvacFriendlyBase = 3,
}

FlagCaptureArea = {
	-- applying any props to cannons class vehicles does not seem to work
	-- These props do Not work
	Helicopter = 3, -- props helicopter (reserved)
	Artillery = 175, -- props detect_artillery (not work)
	Mortar = 100, -- props mortar (reserved)
	ATgun = 50, -- props detect_atgun (not work)
	Captor = 100, -- props captor (transport trucks)
	Vehicle = 18, -- props vehicle
	Infantry = 25 -- ~= to any of the props above
}

-- Utility functions and shared logic for various game modes

Context = {
	Purchase = nil,
	SpawnInfo = nil,
	SpawnWait = {
		CooldownTimer = nil,
		WaitTimer = nil,
		RetryPendingUnit = false
	},
	SquadTimers = {}
}

-- Function to set spawn cooldown timer
function SetSpawnCooldownTimer()
	gameModeSpawnTimer = GameModeSpawnCooldown()
	print("Print: player#".. BotApi.Instance.playerId.. " will wait ".. (gameModeSpawnTimer / 1000) .."s before purchasing another unit")
	Context.SpawnWait.CooldownTimer = BotApi.Events:SetQuantTimer(
		function() 
			Context.SpawnWait.CooldownTimer = nil 
		end, 
		gameModeSpawnTimer)
end

-- Function to kill spawn cooldown timer
function KillSpawnCooldownTimer()
	if Context.SpawnWait.CooldownTimer then
		BotApi.Events:KillQuantTimer(Context.SpawnWait.CooldownTimer)
		Context.SpawnWait.CooldownTimer = nil
	end
end

-- Function to kill spawn wait timer
function KillSpawnWaitTimer()
	if Context.SpawnWait.WaitTimer then
		BotApi.Events:KillQuantTimer(Context.SpawnWait.WaitTimer)
		Context.SpawnWait.WaitTimer = nil
	end
	Context.SpawnWait.RetryPendingUnit = false
end

-- Function to check how far forward unit selection looks when filtering by TimeToSpawnUnit
function GetUnitSelectionTTSLimit()
	return GetCurrentSpawnWaitTime()
end

-- PIter class for managing unit purchases
function PIter:new(data)
    local obj = {
        idx = nil,
        rpt = nil,
        purchases = data
    }
    setmetatable(obj, self)
    obj:nextIndex()
    return obj
end

function PIter:current()
    if self.idx then
		return self.purchases[self.idx].Units
	end
end

function PIter:nextIndex()
    if not self.purchases or next(self.purchases) == nil then
        self.idx, self.rpt = nil, nil
        return
    end
    
    self.idx = next(self.purchases, self.idx)
    if self.idx then
        self.rpt = self.purchases[self.idx].Repeat
    else
        self.rpt = nil
    end
end

function PIter:moveNext()
	if not self.rpt or self.rpt == 0 then
		return
	end
	
	self.rpt = self.rpt - 1

	if self.rpt == 0 then
		self:nextIndex()
	end
end

-- UFB: weighted selection is independent of debug stack names and logging.
-- Opening rear-flag state is owned by GetFlagToCapture in battlezones.lua.
function GetRandomItem(items, getRate)
    local rates, total = {}, 0
    for _, item in pairs(items) do
        local rate = getRate(item)
        if type(rate) == "number" and rate > 0 and rate < math.huge then
            total = total + rate
            rates[#rates + 1] = {item = item, bound = total}
        end
    end
    if total <= 0 or total == math.huge then return nil end
    local target = math.random() * total
    for _, entry in ipairs(rates) do
        if target < entry.bound then return entry.item end
    end
    return rates[#rates].item -- floating point rounding at the upper boundary
end

-- QueryScene returns rows {playerId, propCounts}; row index is not an ID.
function GetPlayerUnitCounts(sceneUnits, playerId)
    for _, row in pairs(sceneUnits or {}) do
        if row[1] == playerId then return row[2] or {} end
    end
    return {}
end

-- Function to get team that owns flag
function GetFlagOwner(flag)
    if flag.occupant == team then
        return FlagOwnership.Allied
    elseif flag.occupant == enemyTeam then
        return FlagOwnership.Opponent
    else
        return FlagOwnership.Neutral
    end
end

-- Function to get flags location of the map in relation to each team
function LookupFlagLocation(flag, flagLocationMap, spawnSide)
	local flagLocationsForCurrentGameMode = flagLocationMap[gameMode] or flagLocationMap
    local locationData = flagLocationsForCurrentGameMode[flag.name] or flagLocationsForCurrentGameMode["default"]
    if type(locationData) == "function" then
        return locationData(spawnSide)
    else
        return locationData
    end
end

-- Function to give Flag a capture priority
function getDefaultFlagPriority(flag)
    if not flagLocationMap then
        return GetFlagOwner(flag) * 1
    end
    return GetFlagOwner(flag) * LookupFlagLocation(flag, flagLocationMap, spawnSide)
end

-- Function used for ordering units to capture flag
function GetFlagPosition(flag)
    local location = LookupFlagLocation(flag, flagLocationMap, spawnSide)
    if location == FlagLocation.Center then
        return "center"
    elseif location == FlagLocation.Friendly or location == FlagLocation.FriendlyBase then
        return "friendly"
    elseif location == FlagLocation.Enemy or location == FlagLocation.EnemyBase then
        return "enemy"
    end
    return
end

-- Function to calculate flag statistics
function CalculateFlagStatistics(flags)
    local alliedFlags, opponentFlags, neutralFlags, totalFlags = 0, 0, 0, 0
    for i, flag in pairs(flags) do
        totalFlags = totalFlags + 1
        if flag.occupant == team then
            alliedFlags = alliedFlags + 1
        elseif flag.occupant == enemyTeam then
            opponentFlags = opponentFlags + 1
        else
            neutralFlags = neutralFlags + 1
        end
    end
    return alliedFlags, opponentFlags, neutralFlags, totalFlags
end

-- Function to calculate capturable flags
function CalculateCapturableFlags(totalFlags, alliedFlags)
    return totalFlags - alliedFlags
end

-- Function to print flag debug information
function PrintFlagDebugInfo(alliedFlags, opponentFlags, neutralFlags, totalFlags, capturableFlags, teamIsLosing)
    if printDebug then
        print("alliedFlags:", alliedFlags, "opponentFlags:", opponentFlags, "neutralFlags:", neutralFlags, "totalFlags:", totalFlags, "capturableFlags:", capturableFlags)
        print("teamIsLosing:", teamIsLosing)
    end
end

-- Function to calculate search destroy value
function CalculateSearchDestroyValue(capturableFlags, alliedFlags, opponentFlags)
    if capturableFlags > alliedFlags then
        return 0.60
    elseif capturableFlags == opponentFlags then
        return 0.40
    else
        return 0.30
    end
end

-- Function to prepare flags for random selection
function PrepareFlags(flagPoints, getPriority, getPosition)
    local flags = {}
    for i, flag in pairs(flagPoints) do
        table.insert(flags, {name = flag.name, priority = getPriority(flag), owner = flag.occupant, location = getPosition(flag)})
    end
    return flags
end

function GetNextUnitToSpawn(purchase)
	local units = purchase:current()
	
	if not units then
		return nil
	end
	
	local unit = GetUnitToSpawn(units)
	purchase:moveNext()
	return unit
end


function UpdateUnitToSpawn(purchase)
	Context.SpawnInfo = GetNextUnitToSpawn(purchase)
end

function GameModeSpawnUnit(unit, maxSquadSize)
	return BotApi.Commands:Spawn(unit, maxSquadSize)
end

-- Called OnGameStart()
function OnGameStartUtility(purchasesModuleSuffix)
    print("Print: AI Bot is player#" .. BotApi.Instance.playerId .. ", nation " .. BotApi.Instance.army .. ", on team " .. team .. " which has " .. teamSize .. " player(s)")
    print("Print: player#" .. BotApi.Instance.playerId .. ", has a difficulty of " .. BotApi.Instance.difficulty)

    -- Seed random for unpredictability
    math.randomseed(os.time() * BotApi.Instance.hostId)
    math.random() math.random() math.random() math.random()

    -- Load purchases module
    local purchasesModule = [[/script/multiplayer/units/]] .. BotApi.Instance.army .. "/" .. purchasesModuleSuffix .. "." .. BotApi.Instance.army
    if module_exists(purchasesModule) then
        require(purchasesModule)
    else
        print("Print: Module does not exist: " .. purchasesModule)
    end

    -- Get purchases
    local purchases = Purchases[purchasesModuleSuffix .. "." .. BotApi.Instance.army]
    if not purchases then
        print("Print: !!WARNING!! NoPurchases")
        purchases = {}
    end

    -- Set up context
    Context.Purchase = PIter:new(purchases)

    -- Update and set cooldown. unit selection now happens when the bot is ready to spawn
    Context.SpawnInfo = nil
    SetSpawnCooldownTimer()
end

---[=[
function TrySpawnUnit()
	if Context.SpawnWait.CooldownTimer then
		return
	end

	if Context.SpawnWait.WaitTimer then
		return
	end

	if not BotApi.Commands:CanSpawn() then
		return
	end

	if spawningUnit then
		if OnUnitPurchased then -- used for conquest
			OnUnitPurchased()
		elseif enableWaveCounter then
			WaveUnitCounter()
		end

		KillSpawnWaitTimer()
		Context.SpawnInfo = nil
		SetSpawnCooldownTimer()
		spawningUnit = nil
		return
	end

	local retryPendingUnit = Context.SpawnWait.RetryPendingUnit
	Context.SpawnWait.RetryPendingUnit = false

	if not retryPendingUnit or not Context.SpawnInfo then
		-- Updates the unit selection at the moment bot is ready to buy, instead of immediately after previous purchase
		UpdateUnitToSpawn(Context.Purchase)
	end

	if not Context.SpawnInfo then
		-- No eligible purchase: retry once a second, not on every game quant.
		Context.SpawnWait.WaitTimer = BotApi.Events:SetQuantTimer(function()
			Context.SpawnWait.WaitTimer = nil
		end, 1000)
		return
	end

	local unit = Context.SpawnInfo.unit

	---[[ -- ! Moved to GetUnitToSpawn(). Active for debuging
	if not BotApi.Commands:IsUnitAvailable(unit) then
		print("Print: !!WARNING!! player#".. BotApi.Instance.playerId.. " tried to purchase: ".. unit .." which is not available")
		KillSpawnWaitTimer()
		Context.SpawnInfo = nil
		return
	end
	--]]

	if GameModeSpawnUnit(unit, MaxSquadSize) then
		spawningUnit = true
		return
	end
	
	local currentUnitSpawnWaitTime = GetCurrentSpawnWaitTime()
	---[[ -- TODO: Move to GetUnitToSpawn()
	local tts = BotApi.Commands:TimeToSpawnUnit(unit)
	local min_tts = GetUnitSelectionTTSLimit()
	if tts > min_tts then
		print("Print: !!WARNING!! player#".. BotApi.Instance.playerId.. " tried to purchase: ".. unit .." but the TTS (unit timer) is greater than UnitSpawnWaitTime ".. (tts / 1000) .."s verses ".. (min_tts / 1000) .."s")
		KillSpawnWaitTimer()
		Context.SpawnInfo = nil
		return
	end
	--]]

	if retryPendingUnit then
		Context.SpawnInfo = nil
	end

	-- TODO: Move to GetUnitToSpawn()
	if not Context.SpawnWait.WaitTimer then
		if printDebug then 
			print("Print: player#".. BotApi.Instance.playerId .." tried to purchase: ".. unit .." Not enough MP, DP, CP, or the unit timer is not unlocked")
			print("Print: player#".. BotApi.Instance.playerId .." will wait a maximum of ".. (currentUnitSpawnWaitTime / 1000 + 1) .."s for resources or unit timer before it attempts a new unit purchase")
		end
		Context.SpawnWait.WaitTimer = BotApi.Events:SetQuantTimer(
			function()
				Context.SpawnWait.WaitTimer = nil
				Context.SpawnWait.RetryPendingUnit = Context.SpawnInfo ~= nil
			end, currentUnitSpawnWaitTime + 1000)
	end
end
--]=]
function OnGameStop()
	KillSpawnCooldownTimer()
	KillSpawnWaitTimer()

	for squad, timer in pairs(Context.SquadTimers) do
		if timer then
			BotApi.Events:KillQuantTimer(timer)
		end
		Context.SquadTimers[squad] = nil
	end
end

function SetSquadOrder(order, squad, delay)
    -- Replacing an assignment must retire its old recurring timer first.
    local previous = Context.SquadTimers[squad]
    if previous then BotApi.Events:KillQuantTimer(previous) end
    Context.SquadTimers[squad] = nil
    if not BotApi.Scene:IsSquadExists(squad) then return end
    order(squad)

    local function schedule()
        local timer
        timer = BotApi.Events:SetQuantTimer(function()
            -- A killed timer may already have been queued by the engine.
            if Context.SquadTimers[squad] ~= timer then return end
            Context.SquadTimers[squad] = nil
            if not BotApi.Scene:IsSquadExists(squad) then return end
            order(squad)
            if BotApi.Scene:IsSquadExists(squad) and not Context.SquadTimers[squad] then
                schedule()
            end
        end, delay)
        Context.SquadTimers[squad] = timer
    end
    if BotApi.Scene:IsSquadExists(squad) and not Context.SquadTimers[squad] then schedule() end
end
