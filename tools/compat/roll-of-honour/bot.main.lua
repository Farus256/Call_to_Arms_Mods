-- Roll of Honour bootstrap. GEM's require searches Lua resources;
-- load the Workshop DLL explicitly before starting the native game-mode AI.
local function startFallenMemorial()
    if package.loaded.fallen_memorial then
        return
    end

    local binariesPath = string.match(
        tostring(package.cpath or ""),
        "([^;]-[\\/]binaries[\\/]x64)[\\/]%?%.dll"
    )
    local steamappsPath = binariesPath and string.match(
        binariesPath,
        "^(.-[\\/]steamapps)"
    )
    if not steamappsPath then
        print("[FALLEN MEMORIAL] ERROR: Could not derive the Steam library from package.cpath")
        return
    end

    local dllPath = steamappsPath .. [[\workshop\content\400750\3791314577\fallen_memorial.dll]]
    if type(package.loadlib) ~= "function" then
        print("[FALLEN MEMORIAL] ERROR: package.loadlib is unavailable")
        return
    end

    local loaded, loader, loadError = pcall(package.loadlib, dllPath, "luaopen_fallen_memorial")
    if not loaded or type(loader) ~= "function" then
        print("[FALLEN MEMORIAL] DLL load FAILED: " .. tostring(loaded and loadError or loader))
        return
    end

    local started, startError = pcall(loader)
    if not started then
        print("[FALLEN MEMORIAL] DLL initialization FAILED: " .. tostring(startError))
        return
    end
    package.loaded.fallen_memorial = true
    print("[FALLEN MEMORIAL] DLL entry point executed: " .. dllPath)
end

startFallenMemorial()

-- Original GEM2 bot.main.lua behaviour.
-- Function to require and initialize the appropriate game mode .lua file
local function initializeBotAI()
    local gameModeMap = {
        campaign_capture_the_flag = "conquest",
        battle_zones = "battlezones",
        ammunition = "battlezones", -- ammuntion aka "domination"
        evacuation = "laststand",
        frontlines = "frontlines",
    }

    local gameModeScriptPath = "resource/script/multiplayer/modes/" .. gameModeMap[BotApi.Instance.gameMode]
    require(gameModeScriptPath)
    if initialize then
        initialize()
    end
end

initializeBotAI()
