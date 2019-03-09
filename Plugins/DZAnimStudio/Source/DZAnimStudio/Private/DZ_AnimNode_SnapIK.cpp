#include "DZ_AnimNode_SnapIK.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"

void FDZ_AnimNode_SnapIK::GatherDebugData(FNodeDebugData& DebugData)
{

}

void FDZ_AnimNode_SnapIK::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{

}

bool FDZ_AnimNode_SnapIK::IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones)
{
	return false;
}

void FDZ_AnimNode_SnapIK::InitializeBoneReferences(const FBoneContainer& RequiredBones)
{

}
