-- Preserve native/Horten decision making, but never overwrite a specialist's job.
local Guard = {}
local waypointRetries = {}
local stopped = false
local protectedTags = {
    "_ufb_cover_active", "_ufb_combat_busy", "_ufb_job_reserved", "_ufb_healing_active",
    "_ai_do_not_disturb", -- HF 4 reserves animations and temporary native jobs.
    "_ai_suppressed_by_mg", "_ai_mgunner", "_ai_reloading", "_ufb_hf_cover_active",
    "_lua_mi", "repairing", "tcrew", "ecrew", "ecrew_a", "ecrew_b",
    "bot_arty", "bot_aa_guard", "_ai_medic", "bot_medic",
    "_ufb_crew_safe",
    "bleeding", "_bleeding", "wounded_animation_playing",
    "bot_inf_flank_in_progress",
    "_ai_ap_grenade", "_ai_at_grenade", "_ai_smoke_grenade",
    "_ufb_smoke_120m_actor", "_ufb_smoke_60m_actor", "_ufb_smoke_wirecutter_actor",
    "ai_close_inf", "_ai_wirecutter_in_action",
    "_ai_at_launcher_30", "_ai_at_launcher_40", "_ai_at_launcher_50",
    "_ai_at_launcher_60", "_ai_at_launcher_70", "_ai_at_launcher_80", "_ai_at_launcher_90",
    -- Only the active HF tank job owns orders; its cooldown does not hold the tank.
    "ai_start_finishing_off",
    "_ai_tank_range_120_alert", "_ai_tank_range_130_alert",
    "_ai_tank_range_140_alert", "_ai_tank_range_150_alert",
    "_ai_tank_range_160_alert", "_ai_tank_range_170_alert",
    "_ai_tank_range_180_alert", "_ai_tank_range_190_alert",
    "_ai_tank_range_200_alert", "_ai_tank_range_210_alert",
    "_ai_tank_range_220_alert",
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

local function HasTemporaryHFJob(squad)
    for _, tag in ipairs({"_ai_do_not_disturb", "_ai_suppressed_by_mg", "_ai_mgunner", "_ai_reloading", "_ufb_hf_cover_active", "_ufb_combat_busy", "_ufb_job_reserved", "_ufb_healing_active"}) do
        if BotApi.Scene:IsSquadTagged(squad, tag) then return true end
    end
    return false
end

function Guard.Wrap(order, needsWaypoint)
    local wrapped
    wrapped = function(squad)
        if stopped then return end
        if waypointRetries[squad] then
            BotApi.Events:KillQuantTimer(waypointRetries[squad].timer)
            waypointRetries[squad] = nil
        end
        if ShouldStopNormalSquadOrders and ShouldStopNormalSquadOrders() then
            return
        end
        -- _lua_ignore belongs to the native CaptureFlag decision, which can
        -- legitimately choose SeekAndDestroy. It only blocks waypoint movement.
        if Guard.IsProtected(squad) or (needsWaypoint and BotApi.Scene:IsSquadTagged(squad, "_lua_ignore")) then
            -- Resume temporary HF jobs with a fresh native target; do not wait
            -- for the 150 s capture rotation or create retries for permanent jobs.
            if BotApi.Scene:IsSquadExists(squad) and (needsWaypoint or HasTemporaryHFJob(squad))
                and (not needsWaypoint or #BotApi.Scene.Waypoints > 0) then
                -- Token identity also rejects a cancelled callback already queued
                -- by the engine, even if native timer IDs are later reused.
                local retry = {}
                waypointRetries[squad] = retry
                retry.timer = BotApi.Events:SetQuantTimer(function()
                    if stopped or waypointRetries[squad] ~= retry then return end
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

-- Called from OnGameStop in utility.lua. Do not Subscribe here: GEM keeps one
-- handler per event, so an extra GameStart/GameEnd subscription silently replaces
-- the mode's OnGameStart/OnGameStop (bots never initialise, then the game aborts).
function Guard.Stop()
    stopped = true
    for squad, retry in pairs(waypointRetries) do
        BotApi.Events:KillQuantTimer(retry.timer)
        waypointRetries[squad] = nil
    end
end

return Guard
