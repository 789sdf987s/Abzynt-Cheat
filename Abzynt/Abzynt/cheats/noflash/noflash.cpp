#include "noflash.hpp"
std::unique_ptr<c_noflash> g_pnoflash = std::make_unique<c_noflash>();

void c_noflash::think()
{
	if (g_config.settings.noflash)
	{
		if (local.m_flFlashMaxAlpha != 0)
		{
			g_pmemory->write<float>(local.base + offsets.flash_max_alpha, 0);
		}
	}
}