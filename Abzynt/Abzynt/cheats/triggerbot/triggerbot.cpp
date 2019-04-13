#include "triggerbot.hpp"
std::unique_ptr<c_triggerbot> g_ptriggerbot = std::make_unique<c_triggerbot>();

void c_triggerbot::think()
{
	if (g_config.settings.triggerbot && GetAsyncKeyState(g_config.settings.triggerbot_key))
	{
		if (local.m_iCrosshairId >= 1 && local.m_iCrosshairId <= 64) // We're checking if entity's id is between 1 and 64 because in csgo players are on fist 64 positions.
		{
			if (local.m_iTeamNum != player[local.m_iCrosshairId].m_iTeamNum) // We're checking for team to not shot our team mates.
			{
				g_pclient->shot();
			}
		}
	}
}