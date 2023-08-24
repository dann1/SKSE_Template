# SKSE_Template

SKSE base template for building projects with [CommonLibSSE](https://github.com/dann1/CommonLibSSE/tree/dev) and [ClibUtil](https://github.com/powerof3/CLibUtil). Created using snippets of code from other po3 repositories.

Loads configuration from `SKSE/Plugins/SKSE_Template.ini` and prints the value of the `Mark` key under the section `Logging`. Prints to the console if `bConsole` is set to `true`. Prints to `SKSE_Template.log` if `bFile` is set to true.

## Requirements

* [CMake](https://cmake.org/)
* [Vcpkg](https://github.com/microsoft/vcpkg)
* [Visual Studio Community Preview 2022](https://visualstudio.microsoft.com/): Install desktop development with C++ extension
* [CommonLibSSE](https://github.com/dann1/CommonLibSSE/tree/dev): This is already included as git submodle
* **Environmental Variables**:
  * Add the cmake executable to your `PATH` environmental variable
  * Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
  * Optionally set the `SkyrimModsPath` environment variable to the Mod staging folder. If set, when building the project, the plugin will be copied to `$SkyrimModsPath/SKSE_Template`

## Register Visual Studio as a Generator

* Open `x64 Native Tools Command Prompt`
* Run `cmake`
* Close the cmd window

## Building

```pwsh
git clone https://github.com/dann1/SKSE_Template.git
cd SKSE_Template
cmake -B build -S . # debug
cmake --build build --config Release # release
```
