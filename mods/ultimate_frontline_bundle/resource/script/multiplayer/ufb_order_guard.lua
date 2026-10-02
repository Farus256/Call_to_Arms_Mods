-- Preserve native/Horten decision making, but never overwrite a specialist's job.
local Guard = {}
local waypointRetries = {}
local protectedTags = {
    "_lua_mi", "repairing", "tcrew", "ecrew", "ecrew_a", "ecrew_b",
    "bot_arty", "bot_aa_guard", "_ai_medic", "bot_medic",
    "_ufb_crew_safe", "_lua_ignore",
    "bleeding", "_bleeding", "wounded_animation_playing",
    "bot_inf_flank_in_progress",
    "_ai_ap_grenade", "_ai_at_grenade", "_ai_smoke_grenade",
    "ai_close_inf", "_ai_wirecutter_in_action",
}

function Guard.IsProtected(squad)
    if not BotApi.Scene:IsSquadExists(squad) then
        return true
    end
    for _, tag in ipairs(protectedTags) do
        if BotApi.Scene:IsSquadTagged(squad, tag) then
            return true
        end
    end
    return false
end

function Guard.Wrap(order, needsWaypoint)
    local wrapped
    wrapped = function(squad)
        if needsWaypoint and waypointRetries[squad] then
            BotApi.Events:KillQuantTimer(waypointRetries[squad])
            waypointRetries[squad] = nil
        end
        if ShouldStopNormalSquadOrders and ShouldStopNormalSquadOrders() then
            return
        end
        if Guard.IsProtected(squad) then
            -- Waypoint routes have no periodic SetSquadOrder timer. Retry when
            -- a temporary job ends, otherwise the route would never resume.
            if needsWaypoint and BotApi.Scene:IsSquadExists(squad)
                and #BotApi.Scene.Waypoints > 0 then
                waypointRetries[squad] = BotApi.Events:SetQuantTimer(function()
                    waypointRetries[squad] = nil
                    wrapped(squad)
                end, 5000)
            end
            return
        end
        if needsWaypoint and #BotApi.Scene.Waypoints == 0 then
            return
        end
        return order(squad)
    end
    return wrapped
end

BotApi.Events:Subscribe(BotApi.Events.GameEnd, function()
    for squad, timer in pairs(waypointRetries) do
        BotApi.Events:KillQuantTimer(timer)
        waypointRetries[squad] = nil
    end
end)

return Guard
