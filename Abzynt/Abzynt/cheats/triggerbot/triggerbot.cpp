#include "triggerbot.hpp"
std::unique_ptr<c_triggerbot> g_ptriggerbot = std::make_unique<c_triggerbot>();

void c_triggerbot::think()
{
	const auto local_player = g_pclient->get_local_player();
	const auto in_cross_id = local_player->get_crosshair_id();
	const auto team = local_player->get_team();
	if (in_cross_id >= 1 && in_cross_id <= 64)
	{
		const auto player = g_pclient->get_player(in_cross_id);
		if (player->get_team() != local_player->get_team())
		{
			g_pclient->shot();
		}
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}