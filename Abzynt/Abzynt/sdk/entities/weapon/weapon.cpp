#include "weapon.hpp"

c_weapon::c_weapon(const uint32_t address)
{
	base = address;
}

uint32_t c_weapon::get_base()
{
	return base;
}

short c_weapon::get_id()
{
	return g_pmemory->read<short>(base + offsets.item_definition_index);
}

int c_weapon::get_zoom_level()
{
	return g_pmemory->read<int>(base + offsets.zoom_level);
}

bool c_weapon::is_auto()
{
	switch (get_id()) 
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 30:
	case 32:
	case 36:
	case 61:
		return true;
		break;
	default:
		return false;
		break;
	}
}