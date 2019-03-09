#include "Misc/CoreMisc.h"
#include "Stats/Stats.h"
#include "Engine/EngineTypes.h"
#include "EngineDefines.h"
#include "AnimNode_SkeletalControlBase.h"
#include "DZ_AnimNode_SnapIK.generated.h"


USTRUCT(BlueprintInternalUseOnly)
struct DZANIMSTUDIO_API FDZ_AnimNode_SnapIK : public FAnimNode_SkeletalControlBase
{
	GENERATED_USTRUCT_BODY()

	// Called to gather on-screen debug data. This is called on the game thread.
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;

	// Evaluate the new component-space transforms for the affected bones.
	virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;

	// Return true if it is valid to Evaluate
	virtual bool IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones) override;

private:
	// Initialize any bone references you have
	virtual void InitializeBoneReferences(const FBoneContainer& RequiredBones) override;

};
