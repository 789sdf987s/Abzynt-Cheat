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
	const uint32_t bspotted = 0x93D;
	const uint32_t item_definition_index = 0x2FAA;
	const uint32_t active_weapon = 0x2EF8;
	const uint32_t fov = 0x31E4;
	const uint32_t is_scoped = 0x390A;
	const uint32_t zoom_level = 0x3390;
	const uint32_t glow_object_manager = 0x5223730;
	const uint32_t glow_index = 0xA3F8;
};
extern c_offsets offsets;