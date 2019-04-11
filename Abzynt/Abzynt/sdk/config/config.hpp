#pragma once
#include "../sdk.hpp"

class c_config {
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
	} settings;
private:
	std::string path;
};
extern std::unique_ptr<c_config> g_pconfig;