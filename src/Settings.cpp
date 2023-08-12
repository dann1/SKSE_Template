#include "Settings.h"

Settings::Settings() {
    CSimpleIniA ini;
    ini.SetUnicode();

	SI_Error rc = ini.LoadFile("SKSE_Template.ini");
	if (rc < 0) {
        return nullptr;
    }

    bConsole = ini.GetBoolValue("Logging", "bConsole", true);
    bFile = ini.GetBoolValue("Logging", "bFile", true);
    mark = ini.GetValue("Logging", "Mark", "Hello World");
}

Settings& Settings::GetSingleton() {
    static Settings instance;
    return instance;
}
