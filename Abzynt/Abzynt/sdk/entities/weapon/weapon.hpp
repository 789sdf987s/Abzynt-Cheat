#pragma once
#include "../../sdk.hpp"

struct weapon_t
{
	 char _0x0[12202];
	 short m_iItemDefinitionIndex;
	 char _0x2FAB[994];
	 int m_zoomLevel;
	 bool is_auto();
};
extern weapon_t local_weapon;
