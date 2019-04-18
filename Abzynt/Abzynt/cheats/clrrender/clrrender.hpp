#pragma once
#include "../../sdk/sdk.hpp"

class c_clrrender
{
public:
	void think();
private:
	struct clr_t
	{
	public:
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	};
};
extern std::unique_ptr<c_clrrender> g_pclrrender;