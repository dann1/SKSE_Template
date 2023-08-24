#include "Settings.h"

// Plugin specific functionality called by the main.cpp file
namespace Manager
{
	void Logic()
	{
		// Load plugin configuration
		const auto settings = Settings::GetSingleton();

		if (settings->file) {
			// File logging
			logger::info("--> {}", settings->mark);
		}

		if (settings->console) {
			// Console Logging
			auto clogger = RE::ConsoleLog::GetSingleton();

			clogger->Print("=================================");
			clogger->Print("--> %s", settings->mark.c_str());
			clogger->Print("=================================");
		}
	}
}
