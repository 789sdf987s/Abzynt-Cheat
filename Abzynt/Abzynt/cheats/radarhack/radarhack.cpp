#include "radarhack.hpp"
std::unique_ptr<c_radarhack> g_pradarhack = std::make_unique<c_radarhack>();

void c_radarhack::think()
{
	if (g_pconfig->settings.radarhack)
	{
		const auto local_player = g_pclient->get_local_player(); // We're getting local player's address

		for (auto i = 1; i <= 64; i++) { // Looping through 64 entities because in csgo players are on fist 64 positions.
			const auto player = g_pclient->get_player(i); // Getting player.

			if (player->get_team() != local_player->get_team()) // We're checking for team to not force bspotted for our team mates.
				g_pmemory->write<int>(player->get_base() + offsets.bspotted, 1); // Forcing bspotted to true, so we will see enemies on radar.
		}
	}
}