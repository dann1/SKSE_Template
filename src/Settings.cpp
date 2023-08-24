#include "Settings.h"

void Settings::LoadSettings()
{
	CSimpleIniA ini;

	constexpr auto path = L"Data/SKSE/Plugins/SKSE_Template.ini";
	ini.SetUnicode();

	SI_Error rc = ini.LoadFile(path);
	if (rc < 0) {
		logger::warn("Settings file not found, using default values");
	}

	const char* section = "Logging";

	console = ini.GetBoolValue(section, "bConsole", true);
	file = ini.GetBoolValue(section, "bFile", true);
	mark = ini.GetValue(section, "Mark", "Hello World");
}
