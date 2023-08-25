# SKSE Plugin Template

SKSE Plugin base template for building projects with po3's [CommonLibSSE](https://github.com/dann1/CommonLibSSE/tree/dev) and [ClibUtil](https://github.com/powerof3/CLibUtil).

Loads configuration from `SKSE/Plugins/SKSE_Template.ini`. Prints the value of the `Mark` key if `bConsole` is set to `true` and to `SKSE_Template.log` if `bFile` is set to true.

The plugin specific functionality has been carefully separated from generic boilerplate SKSE Plugin code located at `src/template/`. The result is a clean and easy to understand project layout with the logic at `src`, showcasing usage of functionality that you will most likely use in your plugins. Comments have been added explaining what the code does.

## Building

Unlike projects using [CommonLibSSE-NG](https://github.com/CharmedBaryon/CommonLibSSE-NG), a DLL needs be built for each supported game version. So you'll end up with several DLLs. This is a consequence of using [CommonLibSSE](https://github.com/powerof3/CommonLibSSE). This is quite easy to accomplish though.

This template uses [my own fork of CommonLibSSE](https://github.com/dann1/CommonLibSSE) as a git submodule since sometimes I create [functionality that fits into CommonLibSSE](https://github.com/powerof3/CommonLibSSE/pull/84). Since that can take a while to be accepted, I opt to use my fork instead of po3's.

I don't intend to create yet another fork, is just the way changes are pushed. I'll keep it synced. You can replace the submodule with po3's if you want. The build process will not differ.

### Requirements

- [CMake](https://cmake.org/)
- [Vcpkg](https://github.com/microsoft/vcpkg)
- [Visual Studio Community Preview 2022](https://visualstudio.microsoft.com/): Install desktop development with C++ extension
- [CommonLibSSE](https://github.com/dann1/CommonLibSSE/tree/dev): This is already included as git submodle
- **Environmental Variables**:
  - Add the cmake executable to your `PATH` environmental variable
  - Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg

### Register Visual Studio as a Generator

- Open `x64 Native Tools Command Prompt`
- Run `cmake`
- Close the cmd window

### Local builds

There is a configure preset you can select on the IDE to decide which Skyrim SE version the DLL should be built for

- SE **1.5.97** requires vs2022-windows-vcpkg-ae
- AE **1.6.629+** requires vs2022-windows-vcpkg-se

Open a terminal and issue the following commands

```pwsh
git clone --recursive https://github.com/dann1/SKSE_Template.git
cd SKSE_Template
cmake -B build -S . # debug
cmake --build build --config Release # release
```

Depending on the generated preset and depending on the build type, the DLL will be generated inside a directory at `./build/` for SE or `./buidae` for AE. Such directory is **Debug** or **Release** depending on the type of build.

For example

- a **debug** build with the **vs2022-windows-vcpkg-se** preset will be generated at `./build/Debug/`
- a **release** build with the **vs2022-windows-vcpkg-ae** preset will be generated at `./buildae/Release/`

#### Automatic DLL placement

After the DLL is built, you need to import it with your mod manager or manually place it on the Skyrim Data folder. You can automate this behavior by setting environmental variables.

You can set the `SkyrimModsPath` environment variable to the Mod staging folder. If set, after the build is completed, the DLL will be copied to `$SkyrimModsPath/SKSE_Template/SKSE/Plugins`. Alternatively, you can place the DLL directly on the `<Data/Overwrite>/SKSE/Plugins` folder by setting the environmental variable `SkyrimPath`. The `SkyrimModsPath` variable has higher priority.

The provided INI file is not copied to the DLL destination nor the build directory.

### Automatic FOMOD packaging

When releasing a mod with sensitive installation options (like choosing the right DLL) to the Nexus, it is very convenient to create a [FOMOD](https://www.nexusmods.com/fallout4/mods/6821). You can automatically generate it without even installing the FOMOD tool thanks to the [pack-skse-mod](https://github.com/adya/pack-skse-mod) utility.

Enable github actions on the repository configuration to get automatic FOMOD generations. The [fomod](./images/fomod.png) will automatically select the proper DLL based on your game version. The FOMOD build will be triggered whenever a new commit is pushed to the master branch. This behavior is defined in [main.yml](.github/workflows/main.yml). After the build is [completed](./images/gh_actions.png) you can download the FOMOD installer from the Artifacts section.
