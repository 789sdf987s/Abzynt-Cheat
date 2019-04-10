#pragma once
#include "../../sdk.hpp"

class c_player {
public:
	c_player(const uint32_t base);
	uint32_t get_base();
	int get_team();
	int get_crosshair_id();
private:
	uint32_t base;
};