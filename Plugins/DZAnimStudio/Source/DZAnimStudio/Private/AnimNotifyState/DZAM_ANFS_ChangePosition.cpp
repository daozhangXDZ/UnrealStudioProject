#include "DZAM_ANFS_ChangePosition.h"
#include "Animation/AnimInstance.h"

//#define LOCTEXT_NAMESPACE "DZAnimNotifyState_ChangePosition"
//
//DEFINE_LOG_CATEGORY(DZAM_ANFS_ChangePosition);

FVector UDZAM_ANFS_ChangePosition::GetCurvePosition(USkeletalMeshComponent * MeshComp) const
{
	UAnimInstance* vAnimIns = MeshComp->GetAnimInstance();
	FVector vCurvyPos = FVector(0,0,0);
	if (vAnimIns != NULL)
	{
		if (ChangePosCurvyX_Name != NAME_None)
		{
			if (!vAnimIns->GetCurveValue(ChangePosCurvyX_Name, vCurvyPos.X))
			{
				vCurvyPos.X = 0;
			}
		}
		if (ChangePosCurvyY_Name != NAME_None)
		{
			if (!vAnimIns->GetCurveValue(ChangePosCurvyY_Name, vCurvyPos.Y))
			{
				vCurvyPos.Y = 0;
			}
		}
		if (ChangePosCurvyZ_Name != NAME_None)
		{
			if (!vAnimIns->GetCurveValue(ChangePosCurvyZ_Name, vCurvyPos.Z))
			{
				vCurvyPos.Z = 0;
			}
		}
	}
	return vCurvyPos;
}

UDZAM_ANFS_ChangePosition::UDZAM_ANFS_ChangePosition(const FObjectInitializer &objectins)
	:Super(objectins)
	, mBeginPosition(FVector(0, 0, 0))
{
	ChangePosCurvyX_Name = NAME_None;
	ChangePosCurvyZ_Name = NAME_None;
	ChangePosCurvyY_Name = NAME_None;
}

void UDZAM_ANFS_ChangePosition::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	/*UE_LOG(DZAM_ANFS_ChangePosition, Warning, TEXT("DZChangePos Notify In anim: %s,ChangePose=%s"),
		*GetPathNameSafe(Animation),
		*(GetCurvePosition(MeshComp).ToString())
	);*/
	if (MeshComp == NULL)
		return;
	mBeginPosition = MeshComp->GetOwner()->GetActorLocation();
	mBeginirection = MeshComp->GetComponentRotation();
	mCurrChange = FVector(0, 0, 0);
	/*FString LogContent = GetPathNameSafe(Animation) + " ->DZANFS_ChangePos BeginPos=" + (mBeginPosition.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *LogContent));*/
}

void UDZAM_ANFS_ChangePosition::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (MeshComp == NULL)
		return;
	FVector PosOffsetOnBegin = GetCurvePosition(MeshComp);
	/*FString LogContent = GetPathNameSafe(Animation) + " ->DZANFS_ChangePos offsetPos=" + (PosOffsetOnBegin.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *LogContent));*/
	if (DZ_ChangePosType == DZANFS_ChangePosHandleType::Replace_POS)
	{
		PosOffsetOnBegin = mBeginirection.RotateVector(PosOffsetOnBegin);
		MeshComp->GetOwner()->SetActorLocation(PosOffsetOnBegin + mBeginPosition);
	}
	else
	{
		FVector PosOffsetChange= PosOffsetOnBegin - mCurrChange;
		PosOffsetChange = mBeginirection.RotateVector(PosOffsetChange);
		MeshComp->GetOwner()->AddActorLocalOffset(PosOffsetChange);
		mCurrChange = PosOffsetOnBegin;
	}
	
}

void UDZAM_ANFS_ChangePosition::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp == NULL)
		return;
	if (IsResetOnFinish)
	{
		MeshComp->GetOwner()->SetActorLocation(mBeginPosition);
	}
	else
	{
		mCurrChange = FVector(0, 0, 0);
	}
}


