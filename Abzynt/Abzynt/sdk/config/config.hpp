#pragma once
#include "../sdk.hpp"

class c_config 
{
public:
	c_config(const std::string config_path);
	void load();
	void save();

	struct {
		bool triggerbot = true;
		int triggerbot_key = 18;
		bool radarhack = true;
		bool autopistol = false;
		bool fovchanger = true;
		int fovchanger_amount = 115;
		bool glowesp = true;
		float enemy_colors[3] = { 255,0,0 };
		float team_colors[3] = { 0,255,0 };
	} settings;
private:
	std::string path;
};
extern c_config g_config;