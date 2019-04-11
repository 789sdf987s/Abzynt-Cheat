#pragma once
#include "../../sdk/sdk.hpp"

class c_fovchanger {
public:
	void think();
};
extern std::unique_ptr<c_fovchanger> g_pfovchanger;