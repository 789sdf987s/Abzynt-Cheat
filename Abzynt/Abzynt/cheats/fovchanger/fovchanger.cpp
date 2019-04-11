#include "fovchanger.hpp"
std::unique_ptr<c_fovchanger> g_pfovchanger = std::make_unique<c_fovchanger>();

void c_fovchanger::think()
{
	const auto local_player = g_pclient->get_local_player(); // We're getting local player's address.
	const auto local_fov = local_player->get_fov(); // We're getting local player's fov.
	const auto is_scoped = local_player->is_scoped(); // We're getting information about scope.
	const auto zoom_level = local_player->get_weapon()->get_zoom_level(); // We're getting our zoom level.

	if (!is_scoped) // We're checking for scope, so we write bigger fov when we aren't scoping.
	{
		if (local_fov != 115) // We're checking for current fov, so we will decrease amounts of wpms when fov is 90.
		{
			g_pmemory->write<int>(local_player->get_base() + offsets.fov, 115); // We're writting our desired fov.
		}
	}
	else if(zoom_level == 1 && local_fov != 40) // We're checking for zoom level, so we can use normaly sg or aug.
	{
		g_pmemory->write<int>(local_player->get_base() + offsets.fov, 40);
	}
	else if (zoom_level == 2 && local_fov != 10) // We're checking for zoom level, so we can use normaly awp or scout.
	{
		g_pmemory->write<int>(local_player->get_base() + offsets.fov, 10);
	}
}