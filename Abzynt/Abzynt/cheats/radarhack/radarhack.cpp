#include "radarhack.hpp"
std::unique_ptr<c_radarhack> g_pradarhack = std::make_unique<c_radarhack>();

void c_radarhack::think()
{
	if (g_config.settings.radarhack)
	{
		for (auto i = 1; i <= 64; i++)  // Looping through 64 entities because in csgo players are on fist 64 positions.
		{
			if (local.m_iTeamNum != player[i].m_iTeamNum) // We're checking for team to not force bspotted for our team mates.
			{
				g_pmemory->write<bool>(player[i].base + offsets.bspotted, 1); // Forcing bspotted to true, so we will see enemies on radar.
			}
		}
	}
}