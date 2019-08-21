#include "clrrender.hpp"
std::unique_ptr<c_clrrender> g_pclrrender = std::make_unique<c_clrrender>();

void c_clrrender::think()
{
	if (g_config.settings.clrrender)
	{
		for (auto i = 1; i <= 64; i++)
		{
			clr_t clr;

			clr.red = local.m_iTeamNum == player[i].m_iTeamNum ? g_config.settings.clr_team_colors[0] : g_config.settings.clr_enemy_colors[0];
			clr.green = local.m_iTeamNum == player[i].m_iTeamNum ? g_config.settings.clr_team_colors[1] : g_config.settings.clr_enemy_colors[1];
			clr.blue = local.m_iTeamNum == player[i].m_iTeamNum ? g_config.settings.clr_team_colors[2] : g_config.settings.clr_enemy_colors[2];
			clr.alpha = 255;

			g_pmemory->write<clr_t>(player[i].base + offsets::m_clrrender, clr);
		}
	}
}
