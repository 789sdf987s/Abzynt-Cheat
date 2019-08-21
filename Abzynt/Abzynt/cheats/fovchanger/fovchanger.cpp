#include "fovchanger.hpp"
std::unique_ptr<c_fovchanger> g_pfovchanger = std::make_unique<c_fovchanger>();

void c_fovchanger::think()
{
	if (g_config.settings.fovchanger)
	{
		if (!local.m_bIsScoped) // We're checking for scope, so we write bigger fov when we aren't scoping.
		{
			if (local.m_iFOV != g_config.settings.fovchanger_amount) // We're checking for current fov, so we will decrease amounts of wpms when fov is 90.
			{
				g_pmemory->write<int>(local.base + offsets::m_ifov, g_config.settings.fovchanger_amount); // We're writting our desired fov.
			}
		}
		else if (local_weapon.m_zoomLevel == 1 && local.m_iFOV != 40) // We're checking for zoom level, so we can use normaly sg or aug.
		{
			g_pmemory->write<int>(local.base + offsets::m_ifov, 40);
		}
		else if (local_weapon.m_zoomLevel == 2 && local.m_iFOV != 10) // We're checking for zoom level, so we can use normaly awp or scout.
		{
			g_pmemory->write<int>(local.base + offsets::m_ifov, 10);
		}
	}
}