#include "DZAnimBaseNodeEditMode.h"
#include "DZAnimStudioEditorPrivatePCH.h"
#include "EditorViewportClient.h"
#include "IPersonaPreviewScene.h"
#include "Animation/DebugSkelMeshComponent.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "EngineUtils.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AssetEditorModeManager.h"

const FEditorModeID DZAnimNodeEditModes::ScaleBone("AnimGraph.SkeletalControl.ScaleBone");
const FEditorModeID DZAnimNodeEditModes::SplineIKBone("AnimGraph.SkeletalControl.SplineIKBone");

#define LOCTEXT_NAMESPACE "DZAnimBaseNodeEditMode"

FDZAnimBaseNodeEditMode::FDZAnimBaseNodeEditMode()
{

}

bool FDZAnimBaseNodeEditMode::GetCameraTarget(FSphere& OutTarget) const
{

	return true;
}

IPersonaPreviewScene& FDZAnimBaseNodeEditMode::GetAnimPreviewScene() const
{
	return *static_cast<IPersonaPreviewScene*>(static_cast<FAssetEditorModeManager*>(Owner)->GetPreviewScene());
}

void FDZAnimBaseNodeEditMode::GetOnScreenDebugInfo(TArray<FText>& OutDebugInfo) const
{

}

ECoordSystem FDZAnimBaseNodeEditMode::GetWidgetCoordinateSystem() const
{
	return ECoordSystem::COORD_None;
}

FWidget::EWidgetMode FDZAnimBaseNodeEditMode::GetWidgetMode() const
{
	return FWidget::EWidgetMode::WM_None;
}

FWidget::EWidgetMode FDZAnimBaseNodeEditMode::ChangeToNextWidgetMode(FWidget::EWidgetMode CurWidgetMode)
{
	return FWidget::EWidgetMode::WM_None;
}

bool FDZAnimBaseNodeEditMode::SetWidgetMode(FWidget::EWidgetMode InWidgetMode)
{
	return false;
}

FName FDZAnimBaseNodeEditMode::GetSelectedBone() const
{
	return NAME_None;
}

void FDZAnimBaseNodeEditMode::EnterMode(UAnimGraphNode_Base* InEditorNode, FAnimNode_Base* InRuntimeNode)
{
	
}

void FDZAnimBaseNodeEditMode::ExitMode()
{
	
}

void FDZAnimBaseNodeEditMode::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{

}

void FDZAnimBaseNodeEditMode::DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	
}

bool FDZAnimBaseNodeEditMode::HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	return false;
}

FVector FDZAnimBaseNodeEditMode::GetWidgetLocation() const
{
	return FVector::ZeroVector;
}

bool FDZAnimBaseNodeEditMode::StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
	return true;
}

bool FDZAnimBaseNodeEditMode::EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
	return true;
}

bool FDZAnimBaseNodeEditMode::InputKey(FEditorViewportClient* InViewportClient, FViewport* InViewport, FKey InKey, EInputEvent InEvent)
{
	bool bHandled = false;

	return bHandled;
}

bool FDZAnimBaseNodeEditMode::InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale)
{
	
	bool bHandled = false;

	

	return bHandled;
}

bool FDZAnimBaseNodeEditMode::GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData)
{

	return false;
}

bool FDZAnimBaseNodeEditMode::GetCustomInputCoordinateSystem(FMatrix& InMatrix, void* InData)
{
	return GetCustomDrawingCoordinateSystem(InMatrix, InData);
}

bool FDZAnimBaseNodeEditMode::ShouldDrawWidget() const
{
	return true;
}

void FDZAnimBaseNodeEditMode::DoTranslation(FVector& InTranslation)
{

}

void FDZAnimBaseNodeEditMode::DoRotation(FRotator& InRotation)
{

}

void FDZAnimBaseNodeEditMode::DoScale(FVector& InScale)
{

}

void FDZAnimBaseNodeEditMode::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{

}

void FDZAnimBaseNodeEditMode::ConvertToComponentSpaceTransform(const USkeletalMeshComponent* SkelComp, const FTransform & InTransform, FTransform & OutCSTransform, int32 BoneIndex, EBoneControlSpace Space)
{
	
}


void FDZAnimBaseNodeEditMode::ConvertToBoneSpaceTransform(const USkeletalMeshComponent* SkelComp, const FTransform & InCSTransform, FTransform & OutBSTransform, int32 BoneIndex, EBoneControlSpace Space)
{
	
}

FVector FDZAnimBaseNodeEditMode::ConvertCSVectorToBoneSpace(const USkeletalMeshComponent* SkelComp, FVector& InCSVector, FCSPose<FCompactHeapPose>& MeshBases, const FName& BoneName, const EBoneControlSpace Space)
{
	FVector OutVector = InCSVector;


	return OutVector;
}

FQuat FDZAnimBaseNodeEditMode::ConvertCSRotationToBoneSpace(const USkeletalMeshComponent* SkelComp, FRotator& InCSRotator, FCSPose<FCompactHeapPose>& MeshBases, const FName& BoneName, const EBoneControlSpace Space)
{
	FQuat OutQuat = FQuat::Identity;

	
	return OutQuat;
}

FVector FDZAnimBaseNodeEditMode::ConvertWidgetLocation(const USkeletalMeshComponent* SkelComp, FCSPose<FCompactHeapPose>& MeshBases, const FName& BoneName, const FVector& Location, const EBoneControlSpace Space)
{
	FVector WidgetLoc = FVector::ZeroVector;
	return WidgetLoc;
}

#undef LOCTEXT_NAMESPACE
