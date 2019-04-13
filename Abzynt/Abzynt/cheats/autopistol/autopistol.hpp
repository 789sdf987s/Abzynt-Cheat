#pragma once
#include "../../sdk/sdk.hpp"

class c_autopistol 
{
public:
	void think();
};
extern std::unique_ptr<c_autopistol> g_pautopistol;