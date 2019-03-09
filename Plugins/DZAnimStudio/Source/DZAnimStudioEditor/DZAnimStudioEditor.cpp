#include "DZAnimStudioEditor.h"
#include "DZAnimStudio.h"
#include "DZAnimStudioEditorPrivatePCH.h"
#include "EditMode/DZAnimNode_ScaleBoneEditMode.h"
#define LOCTEXT_NAMESPACE "FAnimGraphIKModule"

void FDZAnimStudioEditorModule::StartupModule()
{
	FEditorModeRegistry::Get().RegisterMode<FDZAnimNode_ScaleBoneEditMode>(DZAnimNodeEditModes::ScaleBone, LOCTEXT("DZAnimNode_ScaleBoneEditMode", "DZAnimNode_ScaleBone"), FSlateIcon(), false);
}

void FDZAnimStudioEditorModule::ShutdownModule()
{

	FEditorModeRegistry::Get().UnregisterMode(DZAnimNodeEditModes::ScaleBone);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDZAnimStudioEditorModule, DZAnimStudioEditor)