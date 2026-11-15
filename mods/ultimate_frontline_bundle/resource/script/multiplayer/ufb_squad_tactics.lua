-- Small objective cohorts: one advancing squad, a covering interval, then a reserve.
-- Uses native CaptureFlag only. No extra event subscriptions, scene queries or order storms.
local Tactics = {}
local plans, assignments, stopped, planCount = {}, {}, false, 0
local live = {}
local MAX_PLANS, PLAN_LIFE, STEP = 24, 12000, 750
local delays, roles = {0, 1500, 3000}, {"advance", "cover", "reserve"}
local nativeClasses = {"_ufb_k_armor", "_ufb_k_gun_light", "_ufb_k_gun_heavy", "_ufb_k_gun_at", "bot_arty", "bot_aa_guard"}

local function cancel(state)
    if state.timer then BotApi.Events:KillQuantTimer(state.timer); state.timer = nil end
end

function Tactics.Cancel(squad)
    local state = assignments[squad]
    if state then cancel(state); assignments[squad] = nil end
end

function Tactics.Capture(squad, target, protected, resume)
    if stopped or not BotApi.Scene:IsSquadExists(squad) then return end
    local old = assignments[squad]
    if ShouldStopNormalSquadOrders and ShouldStopNormalSquadOrders() then
        if old then cancel(old); assignments[squad] = nil end
        return
    end
    if protected(squad) then
        if old then cancel(old); assignments[squad] = nil end
        return resume(squad)
    end
    -- Infantry pacing must not hold classified guns or armor before a native order.
    for _, tag in ipairs(nativeClasses) do
        if BotApi.Scene:IsSquadTagged(squad, tag) then
            if old then cancel(old); assignments[squad] = nil end
            return BotApi.Commands:CaptureFlag(squad, target)
        end
    end
    if old and old.plan.target == target then
        cancel(old)
        old.issued = true
        return BotApi.Commands:CaptureFlag(squad, target)
    end
    if old then cancel(old) end
    local plan = plans[target]
    if not plan or #plan.members >= 3 then
        if planCount >= MAX_PLANS then return BotApi.Commands:CaptureFlag(squad, target) end
        plan = {target=target, members={}}
        planCount = planCount + 1
        plans[target] = plan
        plan.expiry = BotApi.Events:SetQuantTimer(function()
            if stopped then return end
            if plans[target] == plan then plans[target] = nil end
            for _, member in ipairs(plan.members) do
                if assignments[member.squad] == member then cancel(member); assignments[member.squad] = nil end
            end
            planCount = planCount - 1
            live[plan] = nil
        end, PLAN_LIFE)
        live[plan] = true
    end
    local index = #plan.members + 1
    local state = {squad=squad, plan=plan, role=roles[index], remaining=delays[index]}
    plan.members[index], assignments[squad] = state, state
    local function issue()
        if stopped or assignments[squad] ~= state then return end
        state.timer = nil
        if not BotApi.Scene:IsSquadExists(squad) then assignments[squad] = nil; return end
        if ShouldStopNormalSquadOrders and ShouldStopNormalSquadOrders() then assignments[squad] = nil; return end
        if protected(squad) then assignments[squad] = nil; return resume(squad) end
        state.issued = true
        return BotApi.Commands:CaptureFlag(squad, target)
    end
    local function step()
        if stopped or assignments[squad] ~= state then return end
        state.timer = nil
        if not BotApi.Scene:IsSquadExists(squad) then assignments[squad] = nil; return end
        local lead = plan.members[1].squad
        local urgent = assignments[lead] ~= plan.members[1]
            or not BotApi.Scene:IsSquadExists(lead)
            or BotApi.Scene:IsSquadTagged(lead, "_ufb_recent_hit")
            or BotApi.Scene:IsSquadTagged(lead, "_ai_suppressed_by_mg")
        state.remaining = state.remaining - STEP
        if urgent or state.remaining <= 0 then return issue() end
        state.timer = BotApi.Events:SetQuantTimer(step, STEP)
    end
    if state.remaining == 0 then return issue() end
    state.timer = BotApi.Events:SetQuantTimer(step, STEP)
end

function Tactics.Role(squad)
    return assignments[squad] and assignments[squad].role
end

function Tactics.Stop()
    stopped = true
    for _, state in pairs(assignments) do cancel(state) end
    -- All cohort expiries must also be retired, including a filled predecessor of a target.
    for plan in pairs(live) do BotApi.Events:KillQuantTimer(plan.expiry) end
    plans, assignments, live, planCount = {}, {}, {}, 0
end

return Tactics
