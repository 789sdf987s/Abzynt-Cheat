#pragma once
#include "../../sdk.hpp"

class c_players {
public:
	void update();
};
extern c_players g_players;

struct weapon_t;

struct player_t 
{
	uint32_t base;
	std::byte pad1[108];
	uint32_t m_clrRender;
	std::byte pad2[offsets::m_iteamnum - offsets::m_clrrender - sizeof(uint32_t)];
	int m_iTeamNum;
	std::byte pad3[offsets::m_ihealth - offsets::m_iteamnum - sizeof(int)];
	int m_iHealth;
	int m_fFlags;
	vec3 m_vecViewOffset;
	vec3 m_vecVelocity;
	std::byte pad4[offsets::m_vecorigin - offsets::m_vecvelocity - sizeof(vec3)];
	vec3 m_vecOrigin;
	std::byte pad5[offsets::m_lifestate - offsets::m_vecorigin - sizeof(vec3)];
	unsigned char m_lifeState;
	std::byte pad212[offsets::m_bspotted - offsets::m_lifestate - sizeof(unsigned char)];
	bool m_bSpotted;
	std::byte pad6[offsets::m_bspottedbymask - offsets::m_bspotted - sizeof(bool)];
	bool m_bSpottedByMask;
	std::byte pad7[offsets::m_dwbonematrix - offsets::m_bspottedbymask - sizeof(bool)];
	uint32_t m_dwBoneMatrix;
	std::byte pad28[offsets::m_hactiveweapon - offsets::m_dwbonematrix - sizeof(uint32_t)];
	int m_hActiveWeapon;
	std::byte pad29[offsets::m_iitemdefinitionindex - offsets::m_hactiveweapon - sizeof(int)];
	short m_iItemDefinitionIndex;
	std::byte pad21[offsets::m_ifov - offsets::m_iitemdefinitionindex - sizeof(short)];
	int m_iFOV;
	std::byte pad22[offsets::m_flnextprimaryattack - offsets::m_ifov - sizeof(int)];
	float m_flNextPrimaryAttack;
	std::byte pad23[offsets::m_istate - offsets::m_flnextprimaryattack - sizeof(float)];
	int m_iState;
	std::byte pad42[offsets::m_bisscoped - offsets::m_istate - sizeof(int)];
	bool m_bIsScoped;
	std::byte pad25[offsets::m_bisdefusing - offsets::m_bisscoped - sizeof(bool)];
	bool m_bIsDefusing;
	std::byte pad62[offsets::m_ishotsfired - offsets::m_bisdefusing - sizeof(bool)];
	int m_iShotsFired;
	std::byte pad72[offsets::m_flflashmaxalpha - offsets::m_ishotsfired - sizeof(int)];
	float m_flFlashMaxAlpha;
	float m_flFlashDuration;
	std::byte pad82[offsets::m_iglowindex - offsets::m_flflashduration - sizeof(float)];
	int m_iGlowIndex;
	std::byte pad92[offsets::m_icrosshairid - offsets::m_iglowindex - sizeof(int)];
	int m_iCrosshairId;
};
extern player_t local, player[65];

