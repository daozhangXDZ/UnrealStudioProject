#include "DZAnimNode_ScaleBone.h"
#include "DZAnimStudioPrivatePCH.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"

//FDZAnimNode_ScaleBone::FDZAnimNode_ScaleBone()
//{
//
//}

void FDZAnimNode_ScaleBone::GatherDebugData(FNodeDebugData& DebugData)
{
	
}
/************************************************************************/
/* 白袍小道 骨骼节点缩放                                                */
/************************************************************************/
#if ENGINE_MINOR_VERSION >= 16
void FDZAnimNode_ScaleBone::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext & Output, TArray<FBoneTransform>& OutBoneTransforms)
{
	const FBoneContainer& BoneContainer = Output.Pose.GetPose().GetBoneContainer();
#else
void FDZAnimNode_ScaleBone::EvaluateBoneTransforms(USkeletalMeshComponent * SkelComp, FCSPose<FCompactPose>& MeshBases, TArray<FBoneTransform>& OutBoneTransforms)
{
	const FBoneContainer& BoneContainer = MeshBases.GetPose().GetBoneContainer();
#endif
	for (int i = 0; i < this->mEdBoneList.Num(); i++)
	{
		FCompactPoseBoneIndex CompactPoseBoneToModify = this->mEdBoneList[i].mEd_Bone.GetCompactPoseIndex(BoneContainer);
		FTransform NewBoneTM = Output.Pose.GetComponentSpaceTransform(CompactPoseBoneToModify);
		FTransform ComponentTransform = Output.AnimInstanceProxy->GetComponentTransform();
		if (this->mEdBoneList[i].ScaleMode != DZBMM_Ignore)
		{
			// Convert to Bone Space.
			FAnimationRuntime::ConvertCSTransformToBoneSpace(ComponentTransform, Output.Pose, NewBoneTM, CompactPoseBoneToModify, this->mEdBoneList[i].ScaleSpace);

			if (this->mEdBoneList[i].ScaleMode == DZBMM_Additive)
			{
				NewBoneTM.SetScale3D(NewBoneTM.GetScale3D() * this->mEdBoneList[i].Scale);
			}
			else
			{
				NewBoneTM.SetScale3D(this->mEdBoneList[i].Scale);
			}
			// Convert back to Component Space.
			FAnimationRuntime::ConvertBoneSpaceTransformToCS(ComponentTransform, Output.Pose, NewBoneTM, CompactPoseBoneToModify, this->mEdBoneList[i].ScaleSpace);
		}

		OutBoneTransforms.Add(FBoneTransform(this->mEdBoneList[i].mEd_Bone.GetCompactPoseIndex(BoneContainer), NewBoneTM));
	}
}

bool FDZAnimNode_ScaleBone::IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones)
{
	for (int i = 0; i < this->mEdBoneList.Num(); i++)
	{
		if (!this->mEdBoneList[i].mEd_Bone.IsValidToEvaluate(RequiredBones)) {
			return false;
		}
	}
	// if both bones are valid
	return true;
}

void FDZAnimNode_ScaleBone::InitializeBoneReferences(const FBoneContainer& RequiredBones)
{
	for (int i = 0; i < this->mEdBoneList.Num(); i++)
	{
		this->mEdBoneList[i].mEd_Bone.Initialize(RequiredBones);
	}
	
}
