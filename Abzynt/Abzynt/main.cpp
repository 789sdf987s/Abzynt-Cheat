#include "sdk/sdk.hpp"

c_offsets offsets;
int main()
{
	SetConsoleTitle("Abzynt");

	std::cout << "Abzynt - External Multihack" << std::endl;

	const auto got_id = g_pmemory->get_process_id("csgo.exe"); // We're getting the process id of our game, we need this to get handle.

	if (!got_id)
	{
		return 0;
	}

	const auto got_handle = g_pmemory->get_handle("csgo.exe"); // Getting handle to csgo.

	if (!got_handle)
	{
		return 0;
	}

	offsets.client_dll = g_pmemory->get_module("client_panorama.dll"); // Getting module address.

	std::cout << "Cheat is ready!" << std::endl;

	g_config.load();

	std::cout << "Features:" << std::endl;
	std::cout << " - Triggerbot = " << (g_config.settings.triggerbot ? "True" : "False") << std::endl;
	std::cout << " - Triggerbot Key = " << g_config.settings.triggerbot_key << std::endl;
	std::cout << " - Autopistol = " << (g_config.settings.autopistol ? "True" : "False") << std::endl;
	std::cout << " - Radarhack = " << (g_config.settings.radarhack ? "True" : "False") << std::endl;
	std::cout << " - FovChanger = " << (g_config.settings.fovchanger ? "True" : "False") << std::endl;
	std::cout << " - FovChanger Amount = " << g_config.settings.fovchanger_amount << std::endl;
	std::cout << " - GlowESP = " << (g_config.settings.glowesp ? "True" : "False") << std::endl; 
	std::cout << " - Team Color = " << g_config.settings.team_colors[0] << "/" << g_config.settings.team_colors[1] << "/" << g_config.settings.team_colors[2] << std::endl;
	std::cout << " - Enemy Color = " << g_config.settings.enemy_colors[0] << "/" << g_config.settings.enemy_colors[1] << "/" << g_config.settings.enemy_colors[2] << std::endl;

	do 
	{
		g_players.update();
		g_ptriggerbot->think();
		g_pradarhack->think();
		g_pfovchanger->think();
		g_pautopistol->think();
		g_pglowesp->think();

		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Sleeping for 1ms to lower cpu usage.
	} while (true);
}
