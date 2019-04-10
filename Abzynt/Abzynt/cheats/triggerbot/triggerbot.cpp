#include "triggerbot.hpp"
std::unique_ptr<c_triggerbot> g_ptriggerbot = std::make_unique<c_triggerbot>();

void c_triggerbot::think()
{
	const auto local_player = g_pclient->get_local_player(); // We're getting local player's address
	const auto in_cross_id = local_player->get_crosshair_id(); // Getting the id of entity from local player's crosshair
	const auto team = local_player->get_team(); // Getting local player's team

	if (in_cross_id >= 1 && in_cross_id <= 64) // We're checking if entity's id is between 1 and 64 because in csgo players are on fist 64 positions.
	{
		const auto player = g_pclient->get_player(in_cross_id); // We're getting a player from local player's crosshair.

		if (player->get_team() != local_player->get_team()) // We're checking for team to not shot our team mates.
		{
			g_pclient->shot(); 
		}
	}
}