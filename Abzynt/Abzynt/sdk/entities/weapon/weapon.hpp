#pragma once
#include "../../sdk.hpp"

class c_weapon {
public:
	c_weapon(const uint32_t base);
	uint32_t get_base();
	short get_id();
	int get_zoom_level();
	bool is_auto();
private:
	uint32_t base;
};