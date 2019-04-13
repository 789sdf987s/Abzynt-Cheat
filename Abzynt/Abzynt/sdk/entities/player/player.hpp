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
	char _0xF4[108];
	uint32_t m_clrRender;
	char _0x100[128];
	int m_iTeamNum;
	char _0x104[8];
	int m_iHealth;
	int m_fFlags;
	vec3 m_vecViewOffset;
	vec3 m_vecVelocity;
	char _0x25F[24];
	vec3 m_vecOrigin;
	char _0x93D[283];
	unsigned char m_lifeState;
	char _0x980[1757];
	bool m_bSpotted;
	char _0x26A8[66];
	bool m_bSpottedByMask;
	char _0x2EF8[7463];
	uint32_t m_dwBoneMatrix;
	char _0x2FAA[2124];
	int m_hActiveWeapon;
	char _0x31E4[174];
	short m_iItemDefinitionIndex;
	char _0x3218[568];
	int m_iFOV;
	char _0x3238[48];
	float m_flNextPrimaryAttack;
	char _0x390A[28];
	int m_iState;
	char _0x3914[1742];
	bool m_bIsScoped;
	char _0xA370[9];
	bool m_bIsDefusing;
	char _0xA3DC[27227];
	int m_iShotsFired;
	char _0xA3E0[104];
	float m_flFlashMaxAlpha;
	float m_flFlashDuration;
	char _0xB394[20];
	int m_iGlowIndex;
	char _0xE394[3992];
	int m_iCrosshairId;
};
extern player_t local, player[65];
