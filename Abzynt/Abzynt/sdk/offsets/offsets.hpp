#pragma once
#include "../sdk.hpp"

class c_offsets {
public:
	uint32_t client_dll;
	const uint32_t entity_list = 0x4CE34DC;
	const uint32_t local_player = 0xCD2764;
	const uint32_t crosshair_id = 0xB394;
	const uint32_t team_id = 0xF4;
	const uint32_t force_attack = 0x3114BA4;
};
extern c_offsets offsets;