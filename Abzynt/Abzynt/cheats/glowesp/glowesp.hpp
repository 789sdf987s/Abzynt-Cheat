#pragma once
#include "../../sdk/sdk.hpp"

class c_glowesp 
{
public:
	void think();
private:
	struct glow_t
	{
	private:
		uint8_t padding1[4];
	public:
		float red;
		float green;
		float blue;
		float alpha;
	private:
		uint8_t padding2[16];
	public:
		bool render_when_occluded;
		bool render_when_unoccluded;
		bool full_bloom;
	private:
		uint8_t padding3[5];
	public:
		int glow_style;
	};
};
extern std::unique_ptr<c_glowesp> g_pglowesp;