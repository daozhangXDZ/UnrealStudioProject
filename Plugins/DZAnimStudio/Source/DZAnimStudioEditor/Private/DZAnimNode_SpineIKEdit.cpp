#include "DZAnimNode_SpineIKEdit.h"
#include "DZAnimStudioEditorPrivatePCH.h"
#include "AnimNodeEditModes.h"
#include "Animation/AnimBlueprint.h"
#include "Animation/Skeleton.h"

#define LOCTEXT_NAMESPACE "DZAnimBaseNodeEditMode"
UDZAnimNode_SpineIKEdit::UDZAnimNode_SpineIKEdit(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}
void UDZAnimNode_SpineIKEdit::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(FBoneReference, BoneName) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FDZAnimNode_SplineIK, bAutoCalculateSpline) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FDZAnimNode_SplineIK, PointCount) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FDZAnimNode_SplineIK, BoneAxis))
	{
		USkeleton* Skeleton = GetAnimBlueprint()->TargetSkeleton;
		Node.GatherBoneReferences(Skeleton->GetReferenceSkeleton());

		ReconstructNode();
	}
}

FText UDZAnimNode_SpineIKEdit::GetTooltipText() const
{
	return LOCTEXT("AnimGraphNode_DZAnNo_SplineIKBone_Tooltip", "The DZAnNode SplineIKBone");
}

FText UDZAnimNode_SpineIKEdit::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (Node.StartBone.BoneName == NAME_None || Node.EndBone.BoneName == NAME_None)
	{
		return GetControllerDescription();
	}
	else
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ControllerDescription"), GetControllerDescription());
		Args.Add(TEXT("StartBoneName"), FText::FromName(Node.StartBone.BoneName));
		Args.Add(TEXT("EndBoneName"), FText::FromName(Node.EndBone.BoneName));

		// FText::Format() is slow, so we cache this to save on performance
		if (TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle)
		{
			CachedNodeTitles.SetCachedTitle(TitleType, FText::Format(LOCTEXT("AnimGraphNode_SplineIK_ListTitle", "{ControllerDescription} - {StartBoneName} - {EndBoneName}"), Args), this);
		}
		else
		{
			CachedNodeTitles.SetCachedTitle(TitleType, FText::Format(LOCTEXT("AnimGraphNode_SplineIK_Title", "{ControllerDescription}\nChain: {StartBoneName} - {EndBoneName}"), Args), this);
		}
	}
	return CachedNodeTitles[TitleType];
}

FEditorModeID UDZAnimNode_SpineIKEdit::GetEditorMode() const
{
	return DZAnimNodeEditModes::SplineIKBone;
}

void UDZAnimNode_SpineIKEdit::Draw(FPrimitiveDrawInterface * PDI, USkeletalMeshComponent * PreviewSkelMeshComp) const
{
}

FText UDZAnimNode_SpineIKEdit::GetControllerDescription() const
{
	return LOCTEXT("DZAnimNode_SplineIKBone", "DZAnimNode SplineIKBone");
}
