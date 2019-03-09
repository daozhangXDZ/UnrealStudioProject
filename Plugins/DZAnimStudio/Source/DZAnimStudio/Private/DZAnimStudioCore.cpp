#include "DZAnimStudioCore.h"
#include "DZAnimStudioPrivatePCH.h"
#include "AnimationRuntime.h"
#include "Animation/AnimCompress.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimNotifies/AnimNotify.h"
FVector FDZAnimStudioCore::GetCurrentLocation(FCSPose<FCompactPose>& MeshBases, const FCompactPoseBoneIndex& BoneIndex)
{
	return MeshBases.GetComponentSpaceTransform(BoneIndex).GetLocation();
}
