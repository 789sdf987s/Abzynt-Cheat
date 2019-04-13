#pragma once
#include "../../sdk.hpp"

class c_player;

class c_client 
{
public:
	void shot();
};
extern std::unique_ptr<c_client> g_pclient;