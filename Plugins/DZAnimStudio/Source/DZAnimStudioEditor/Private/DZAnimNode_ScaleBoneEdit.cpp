#include "DZAnimNode_ScaleBoneEdit.h"
#include "DZAnimStudioEditorPrivatePCH.h"
#include "EditMode/DZAnimNode_ScaleBoneEditMode.h"

#define LOCTEXT_NAMESPACE "DZAnimBaseNodeEditMode"
UDZAnimNode_ScaleBoneEdit::UDZAnimNode_ScaleBoneEdit(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


FText UDZAnimNode_ScaleBoneEdit::GetTooltipText() const
{
	return LOCTEXT("AnimGraphNode_DZAnNo_ScaleBodyBone_Tooltip", "The DZAnNode ScaleBodyBone");
}

void UDZAnimNode_ScaleBoneEdit::CopyNodeDataToPreviewNode(FAnimNode_Base* AnimNode)
{

}


FText UDZAnimNode_ScaleBoneEdit::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return GetControllerDescription();
}

FEditorModeID UDZAnimNode_ScaleBoneEdit::GetEditorMode() const
{
	return DZAnimNodeEditModes::ScaleBone;
}

void UDZAnimNode_ScaleBoneEdit::Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent * PreviewSkelMeshComp) const
{

}

void UDZAnimNode_ScaleBoneEdit::SetDefaultValue(const FString& InDefaultValueName, const FTransform& InValue)
{

}
FText UDZAnimNode_ScaleBoneEdit::GetControllerDescription() const
{
	return LOCTEXT("DZAnimNode_ScaleBodyBone", "DZAnimNode ScaleBodyBone");
}
