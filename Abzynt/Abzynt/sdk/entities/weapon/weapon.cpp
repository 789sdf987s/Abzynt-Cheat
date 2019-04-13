#include "weapon.hpp"

weapon_t local_weapon;

bool weapon_t::is_auto()
{
	switch (this->m_iItemDefinitionIndex)
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
