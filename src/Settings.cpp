#include "Settings.h"

/// @brief Loads the DLL configuration from an INI file. If the INI file is missing a warning will be logged. If an individual setting is missing, the default value will be used.
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

	// Load INI file keys from section and populate with default values if not found
	console = ini.GetBoolValue(section, "bConsole", true);
	file = ini.GetBoolValue(section, "bFile", true);
	mark = ini.GetValue(section, "Mark", "Hello World");
}
