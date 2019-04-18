#include "config.hpp"

c_config g_config("config.json");

c_config::c_config(const std::string config_path)
{
	char current_path[MAX_PATH] = "";
	GetModuleFileNameA(NULL, current_path, MAX_PATH);
	PathRemoveFileSpecA(current_path);
	PathAddBackslashA(current_path);
	path += config_path;
}

void c_config::save()
{
	std::ofstream out(path);

	if (!out.is_open())
	{
		return;
	}

	Json::Value save;

	save["Abzynt - Config"]["Triggerbot"] = settings.triggerbot;
	save["Abzynt - Config"]["GlowESP"] = settings.glowesp;
	save["Abzynt - Config"]["ClrRender"] = settings.clrrender;
	save["Abzynt - Config"]["Glow Enemy Colors"][0] = settings.glow_enemy_colors[0];
	save["Abzynt - Config"]["Glow Enemy Colors"][1] = settings.glow_enemy_colors[1];
	save["Abzynt - Config"]["Glow Enemy Colors"][2] = settings.glow_enemy_colors[2];
	save["Abzynt - Config"]["Glow Team Colors"][0] = settings.glow_team_colors[0];
	save["Abzynt - Config"]["Glow Team Colors"][1] = settings.glow_team_colors[1];
	save["Abzynt - Config"]["Glow Team Colors"][2] = settings.glow_team_colors[2];
	save["Abzynt - Config"]["Clr Enemy Colors"][0] = settings.clr_enemy_colors[0];
	save["Abzynt - Config"]["Clr Enemy Colors"][1] = settings.clr_enemy_colors[1];
	save["Abzynt - Config"]["Clr Enemy Colors"][2] = settings.clr_enemy_colors[2];
	save["Abzynt - Config"]["Clr Team Colors"][0] = settings.clr_team_colors[0];
	save["Abzynt - Config"]["Clr Team Colors"][1] = settings.clr_team_colors[1];
	save["Abzynt - Config"]["Clr Team Colors"][2] = settings.clr_team_colors[2];
	save["Abzynt - Config"]["Triggerbot Key"] = settings.triggerbot_key;
	save["Abzynt - Config"]["Autopistol"] = settings.autopistol;
	save["Abzynt - Config"]["Noflash"] = settings.noflash;
	save["Abzynt - Config"]["Fovchanger"] = settings.fovchanger;
	save["Abzynt - Config"]["Fovchanger Amount"] = settings.fovchanger_amount;
	save["Abzynt - Config"]["Radarhack"] = settings.radarhack;

	out << save;

	out.close();
}

void c_config::load()
{
	std::ifstream in(path);

	if (!in.good())
	{
		save();
	}

	if (!in.is_open())
	{
		return;
	}

	Json::Value load;

	in >> load;

	settings.triggerbot = load["Abzynt - Config"]["Triggerbot"].asBool();
	settings.glowesp = load["Abzynt - Config"]["GlowESP"].asBool();
	settings.clrrender = load["Abzynt - Config"]["ClrRender"].asBool();
	settings.glow_enemy_colors[0] = load["Abzynt - Config"]["Glow Enemy Colors"][0].asFloat();
	settings.glow_enemy_colors[1] = load["Abzynt - Config"]["Glow Enemy Colors"][1].asFloat();
	settings.glow_enemy_colors[2] = load["Abzynt - Config"]["Glow Enemy Colors"][2].asFloat();
	settings.glow_team_colors[0] = load["Abzynt - Config"]["Glow Team Colors"][0].asFloat();
	settings.glow_team_colors[1] = load["Abzynt - Config"]["Glow Team Colors"][1].asFloat();
	settings.glow_team_colors[2] = load["Abzynt - Config"]["Glow Team Colors"][2].asFloat();
	settings.clr_enemy_colors[0] = load["Abzynt - Config"]["Clr Enemy Colors"][0].asFloat();
	settings.clr_enemy_colors[1] = load["Abzynt - Config"]["Clr Enemy Colors"][1].asFloat();
	settings.clr_enemy_colors[2] = load["Abzynt - Config"]["Clr Enemy Colors"][2].asFloat();
	settings.clr_team_colors[0] = load["Abzynt - Config"]["Clr Team Colors"][0].asFloat();
	settings.clr_team_colors[1] = load["Abzynt - Config"]["Clr Team Colors"][1].asFloat();
	settings.clr_team_colors[2] = load["Abzynt - Config"]["Clr Team Colors"][2].asFloat();
	settings.triggerbot_key = load["Abzynt - Config"]["Triggerbot Key"].asInt();
	settings.autopistol = load["Abzynt - Config"]["Autopistol"].asBool();
	settings.fovchanger = load["Abzynt - Config"]["Fovchanger"].asBool();
	settings.noflash = load["Abzynt - Config"]["Noflash"].asBool();
	settings.fovchanger_amount = load["Abzynt - Config"]["Fovchanger Amount"].asInt();
	settings.radarhack = load["Abzynt - Config"]["Radarhack"].asBool();

	in.close();
}
