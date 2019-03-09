// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Curves/CurveVector.h"
#include "DZAM_ANFS_ChangePosition.generated.h"

UENUM()
enum DZANFS_ChangePosHandleType
{
	Additive_POS UMETA(DisplayName = "add"),

	Replace_POS UMETA(DisplayName = "replace")
};
//DECLARE_LOG_CATEGORY_EXTERN(DZAM_ANFS_ChangePosition, Log, All);
/**
 * 
 */
UCLASS(editinlinenew, Blueprintable, const, hidecategories = Object, collapsecategories, meta = (ShowWorldContextPin, DisplayName = "Position"))
class DZANIMSTUDIO_API UDZAM_ANFS_ChangePosition : public UAnimNotifyState
{
	GENERATED_UCLASS_BODY()
private:
	UPROPERTY()
	FVector mBeginPosition;
	UPROPERTY()
	FRotator mBeginirection;
	UPROPERTY()
	FVector mCurrChange;
protected:
	FVector GetCurvePosition(USkeletalMeshComponent* MeshComp) const;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pos)
		FName ChangePosCurvyX_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pos)
		FName ChangePosCurvyY_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pos)
		FName ChangePosCurvyZ_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pos)
		TEnumAsByte<DZANFS_ChangePosHandleType> DZ_ChangePosType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pos)
		bool IsResetOnFinish;
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};

