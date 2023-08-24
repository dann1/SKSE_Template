#include "SEVersion.h"
#include "Init.h"

/// @brief Sets up the DLL log file and logging verbosity.  Logs DLL build information.
/// @param skse_version
void InitializeLog(std::string skse_version)
{
	auto path = logger::log_directory();
	if (!path) {
		stl::report_and_fail("Failed to find standard logging directory"sv);
	}

	*path /= fmt::format(FMT_STRING("{}.log"), Version::PROJECT);
	auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);

	auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));

#ifdef _DEBUG
	log->set_level(spdlog::level::debug);
	log->flush_on(spdlog::level::debug);
#else
	log->set_level(spdlog::level::info);
	log->flush_on(spdlog::level::info);
#endif

	spdlog::set_default_logger(std::move(log));
	spdlog::set_pattern("[%l] %v"s);

	logger::info(FMT_STRING("{} v{}"), Version::PROJECT, Version::NAME);
	logger::info("Game version : {}", skse_version);
#ifdef _DEBUG
	logger::info("Using Debug build");
#endif
}


void InitializeSKSE(const SKSE::LoadInterface* a_skse)
{
	std::string skse_version = a_skse->RuntimeVersion().string();
	InitializeLog(skse_version);
	SKSE::Init(a_skse);

}
