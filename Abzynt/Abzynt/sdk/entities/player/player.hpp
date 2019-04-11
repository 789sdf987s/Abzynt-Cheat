#pragma once
#include "../../sdk.hpp"

class c_weapon;

class c_player {
public:
	c_player(const uint32_t base);
	uint32_t get_base();
	int get_team();
	int get_crosshair_id();
	int get_fov();
	bool is_scoped();
	std::unique_ptr<c_weapon> get_weapon();
private:
	uint32_t base;
};