#include "client.hpp"
std::unique_ptr<c_client> g_pclient = std::make_unique<c_client>();

void c_client::shot()
{
	g_pmemory->write<int>(offsets::client_dll + offsets::dwforceattack, 6);
}