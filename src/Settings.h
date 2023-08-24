#pragma once

class Settings
{
public:
	bool console;
	bool file;
	std::string mark;

	void LoadSettings();

    [[nodiscard]] static Settings* GetSingleton()
	{
		static Settings singleton;
		singleton.LoadSettings();
		return std::addressof(singleton);
	}

};
