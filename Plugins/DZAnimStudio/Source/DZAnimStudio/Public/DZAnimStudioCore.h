#pragma once
#include "Misc/CoreMisc.h"
#include "Stats/Stats.h"
#include "Engine/EngineTypes.h"
#include "EngineDefines.h"
#include "AnimNode_SkeletalControlBase.h"
#include "Runtime/Launch/Resources/Version.h"
#include "DZAnimStudioCore.generated.h"

UENUM()
enum EDZBoneModificationMode
{
	/** The modifier ignores this channel (keeps the existing bone translation, rotation, or scale). */
	DZBMM_Ignore UMETA(DisplayName = "Ignore"),

	/** The modifier replaces the existing translation, rotation, or scale. */
	DZBMM_Replace UMETA(DisplayName = "Replace Existing"),

	/** The modifier adds to the existing translation, rotation, or scale. */
	DZBMM_Additive UMETA(DisplayName = "Add to Existing")
};

/************************************************************************/
/*    *Editer Bone Item Config Data
*@Author: BaiPaoXD                                                     * /
/************************************************************************/
USTRUCT(BlueprintType)
struct FDZScaleBoneData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, Category = EDITBOBE)
		FBoneReference mEd_Bone;
	UPROPERTY(EditAnywhere, Category = EDITBOBE)
		TEnumAsByte<EDZBoneModificationMode> ScaleMode;
	UPROPERTY(EditAnywhere, Category = EDITBOBE)
		TEnumAsByte<enum EBoneControlSpace> ScaleSpace;
	/** New Scale of bone to apply. This is only worldspace. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EDITBOBE, meta = (PinShownByDefault))
		FVector Scale;
};

USTRUCT()
struct FDZAnimStudioBoneTransform
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		int32 BoneIndex;

	UPROPERTY()
		FTransform Transform;
};

struct DZANIMSTUDIO_API FDZAnimStudioCore
{
	static FVector GetCurrentLocation(FCSPose<FCompactPose>& MeshBases, const FCompactPoseBoneIndex& BoneIndex);
};
