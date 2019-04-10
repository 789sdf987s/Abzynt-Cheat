#pragma once
#include "../../sdk.hpp"

class c_player;

class c_client {
public:
	std::unique_ptr<c_player> get_player(const int i);
	std::unique_ptr<c_player> get_local_player();
	void shot();
};
extern std::unique_ptr<c_client> g_pclient;