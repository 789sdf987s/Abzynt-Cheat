#include "autopistol.hpp"
std::unique_ptr<c_autopistol> g_pautopistol = std::make_unique<c_autopistol>();

void c_autopistol::think()
{
	if (g_pconfig->settings.autopistol)
	{
		const auto local_player = g_pclient->get_local_player(); // We're getting local player's address.
		const auto is_auto = local_player->get_weapon()->is_auto(); // We're getting information about our weapon.

		if (GetAsyncKeyState(1)) // We're checking for mouse1 clicked so w're shooting.
		{
			if (is_auto) // We're checking if weapon is pistol.
			{
				g_pclient->shot();
			}
		}
	}
}