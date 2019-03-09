// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "DZNStu_ACNetBasePropCheck.generated.h"

UCLASS()
class DZNETSTUDIO_API ADZNStu_ACNetBasePropCheck : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADZNStu_ACNetBasePropCheck();

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* showInfoCom;

	//Sync REPD
	UPROPERTY(replicated)
	float mSyncReplicated;

	UPROPERTY()
	FTimerHandle mCampluteSyncRep_TH;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CampluteRandom();

	UFUNCTION(Reliable, Server, WithValidation)
	void SyncCampluteRandomResult();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps)  const;
};
