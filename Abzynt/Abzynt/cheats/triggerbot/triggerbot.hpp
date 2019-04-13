#pragma once
#include "../../sdk/sdk.hpp"

class c_triggerbot 
{
public:
	void think();
};
extern std::unique_ptr<c_triggerbot> g_ptriggerbot;