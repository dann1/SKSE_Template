#pragma once

#include <string>

class Settings {
public:
    static Settings& GetSingleton();

    bool IsConsoleLoggingEnabled() const { return bConsole; }
    bool IsFileLoggingEnabled() const { return bFile; }
    const std::string& GetMark() const { return mark; }

private:
    Settings();
    Settings(const Settings&) = delete;
    Settings& operator=(const Settings&) = delete;

    bool bConsole;
    bool bFile;
    std::string mark;
};
