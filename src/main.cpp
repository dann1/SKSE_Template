#include "Template/Init.h"
#include "manager.h"

void MessageHandler(SKSE::MessagingInterface::Message* a_message)
{
	// Execute the following when receiving a message indicating that the game has been loaded
	if (a_message->type == SKSE::MessagingInterface::kPostLoad) {
		Manager::Logic();
	}
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse)
{
	InitializeSKSE(a_skse);

	const auto messaging = SKSE::GetMessagingInterface();
	messaging->RegisterListener(MessageHandler);

	return true;
}
