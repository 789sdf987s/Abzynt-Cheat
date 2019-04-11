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

int c_player::get_fov()
{
	return g_pmemory->read<int>(base + offsets.fov);
}

bool c_player::is_scoped()
{
	return g_pmemory->read<bool>(base + offsets.is_scoped);
}

std::unique_ptr<c_weapon> c_player::get_weapon()
{
	const uint32_t active_weapon = g_pmemory->read<uint32_t>(base + offsets.active_weapon) & 0xFFF;
	return std::make_unique<c_weapon>(g_pmemory->read<uint32_t>(offsets.client_dll + offsets.entity_list + (active_weapon - 1) * 0x10));
}
