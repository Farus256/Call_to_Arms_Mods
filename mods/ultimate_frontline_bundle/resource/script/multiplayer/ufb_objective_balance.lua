-- Per-bot objective reservations. No visibility queries or invented path API.
local Balance = { Enabled = true, PreferredWeight = 1.5 }
local assignments = {}

function Balance.Choose(squad, flags, preferred, ownTeam)
    if not Balance.Enabled or not preferred or preferred.owner == ownTeam then
        assignments[squad] = nil
        return preferred
    end
    local candidates, counts = {}, {}
    for _, flag in pairs(flags or {}) do
        -- Conquest prioritizes enemy-held flags over neutral flags. Preserve that
        -- eligibility decision instead of letting a high neutral priority bypass it.
        if flag.name and flag.owner == preferred.owner and (flag.priority or 1) > 0 then
            candidates[flag.name] = flag
        end
    end
    for id, target in pairs(assignments) do
        if not BotApi.Scene:IsSquadExists(id) or not candidates[target] then
            assignments[id] = nil
        elseif id ~= squad then
            counts[target] = (counts[target] or 0) + 1
        end
    end
    -- Keep a live assignment until its objective changes hands; no periodic zigzag.
    local previous = candidates[assignments[squad]]
    if previous then return previous end
    local chosen, best = preferred, -1
    local names = {}
    for name in pairs(candidates) do table.insert(names, name) end
    table.sort(names)
    for _, name in ipairs(names) do
        local flag = candidates[name]
        local bias = name == preferred.name and Balance.PreferredWeight or 1
        local score = bias * (flag.priority or 1) / (1 + (counts[name] or 0))
        if score > best then chosen, best = flag, score end
    end
    return chosen
end

function Balance.Commit(squad, flag)
    assignments[squad] = flag and flag.name or nil
end

BotApi.Events:Subscribe(BotApi.Events.GameEnd, function() assignments = {} end)
return Balance
