#include "sdk/sdk.hpp"

c_offsets offsets;

int main()
{
	SetConsoleTitle("Abzynt");

	std::cout << "Abzynt - External Multihack" << std::endl;

	const auto got_id = g_pmemory->get_process_id("csgo.exe");

	if (!got_id)
		return 0;

	const auto got_handle = g_pmemory->get_handle("csgo.exe");

	if (!got_handle)
		return 0;

	offsets.client_dll = g_pmemory->get_module("client_panorama.dll");

	std::cout << "Cheat is ready!" << std::endl;

	do {
		g_ptriggerbot->think();
	} while (true);
}
