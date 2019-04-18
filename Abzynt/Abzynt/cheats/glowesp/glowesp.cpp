#include "glowesp.hpp"
std::unique_ptr<c_glowesp> g_pglowesp = std::make_unique<c_glowesp>();

void c_glowesp::think()
{
	if (g_config.settings.glowesp)
	{
		const auto glow_object_manager = g_pmemory->read<uint32_t>(offsets.client_dll + offsets.glow_object_manager);

		for (auto i = 1; i <= 64; i++)
		{
			auto glow = g_pmemory->read<glow_t>(glow_object_manager + player[i].m_iGlowIndex * 0x38);

			glow.red = local.m_iTeamNum == player[i].m_iTeamNum ? g_config.settings.glow_team_colors[0] : g_config.settings.glow_enemy_colors[0];
			glow.green = local.m_iTeamNum == player[i].m_iTeamNum ? g_config.settings.glow_team_colors[1] : g_config.settings.glow_enemy_colors[1];
			glow.blue = local.m_iTeamNum == player[i].m_iTeamNum ? g_config.settings.glow_team_colors[2] : g_config.settings.glow_enemy_colors[2];
			glow.alpha = 155.f;
			glow.render_when_occluded = true;
			glow.render_when_unoccluded = false;
			glow.glow_style = 0;

			g_pmemory->write<glow_t>(glow_object_manager + player[i].m_iGlowIndex * 0x38, glow);
		}
	}
}