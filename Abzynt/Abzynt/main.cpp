#include "sdk/sdk.hpp"

c_offsets offsets;

int main()
{
	SetConsoleTitle("Abzynt");

	std::cout << "Abzynt - External Multihack" << std::endl;

	const auto got_id = g_pmemory->get_process_id("csgo.exe"); // We're getting the process id of our game, we need this to get handle.

	if (!got_id)
		return 0;

	const auto got_handle = g_pmemory->get_handle("csgo.exe"); // Getting handle to csgo.

	if (!got_handle)
		return 0;

	offsets.client_dll = g_pmemory->get_module("client_panorama.dll"); // Getting module address.

	std::cout << "Cheat is ready!" << std::endl;

	do {
		g_ptriggerbot->think();
		g_pradarhack->think();
		g_pfovchanger->think();
		g_pautopistol->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Sleeping for 1ms to lower cpu usage.
	} while (true);
}
