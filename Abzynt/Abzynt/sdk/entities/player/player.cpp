#include "player.hpp"
c_player::c_player(const uint32_t address)
{
	base = address;
}

uint32_t c_player::get_base()
{
	return base;
}

int c_player::get_team()
{
	return g_pmemory->read<int>(base + offsets.team_id);
}

int c_player::get_crosshair_id()
{
	return g_pmemory->read<int>(base + offsets.crosshair_id);

}
