#include "player.hpp"

player_t local, player[65];
c_players g_players;

void c_players::update()
{
	const auto plocal = g_pmemory->read<uintptr_t>(offsets.client_dll + offsets.local_player);
	local = g_pmemory->read<player_t>(plocal);
	local.base = plocal; 
	const uint32_t active_weapon = g_pmemory->read<uint32_t>(local.base + offsets.active_weapon) & 0xFFF;
	const auto pweapon = g_pmemory->read<uint32_t>(offsets.client_dll + offsets.entity_list + (active_weapon - 1) * 0x10);
	local_weapon = g_pmemory->read<weapon_t>(pweapon);

	for (auto i = 1; i <= 64; i++)
	{
		const auto pplayer = g_pmemory->read<uintptr_t>(offsets.client_dll + offsets.entity_list + (i - 1) * 0x10);
		player[i] = g_pmemory->read<player_t>(pplayer);
		player[i].base = pplayer;
	}
}