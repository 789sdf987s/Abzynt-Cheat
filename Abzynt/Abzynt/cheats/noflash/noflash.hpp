#pragma once
#include "../../sdk/sdk.hpp"

class c_noflash
{
public:
	void think();
};
extern std::unique_ptr<c_noflash> g_pnoflash;