#pragma once
#include "ModuleManager.h"
class FDZAnimStudioEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};