#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <memory>
#include <fstream> 
#include <thread>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include "../json/json.hpp"
#include "../json/json-forwards.hpp"
#include "memory/memory.hpp"
#include "offsets/offsets.hpp"
#include "entities/player/player.hpp"
#include "entities/weapon/weapon.hpp"
#include "csgo/client/client.hpp"
#include "config/config.hpp"
#include "../cheats/triggerbot/triggerbot.hpp"
#include "../cheats/radarhack/radarhack.hpp"
#include "../cheats/fovchanger/fovchanger.hpp"
#include "../cheats/autopistol/autopistol.hpp"
