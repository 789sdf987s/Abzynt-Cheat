#include "client.hpp"
std::unique_ptr<c_client> g_pclient = std::make_unique<c_client>();

std::unique_ptr<c_player> c_client::get_player(const int i) 
{
	return std::make_unique<c_player>(g_pmemory->read<uint32_t>(offsets.client_dll + offsets.entity_list +(i - 1) * 0x10));
}

std::unique_ptr<c_player> c_client::get_local_player()
{
	std::unique_ptr<c_player> test = std::make_unique<c_player>(g_pmemory->read<uint32_t>(offsets.client_dll + offsets.local_player));
	return std::move(test);
}

void c_client::shot()
{
	g_pmemory->write<int>(offsets.client_dll + offsets.force_attack, 6);
}