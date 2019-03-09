// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/Color/ParticleModuleColorBase.h"
#include "ParticleDefinitions.h"
#include "DZParticleModule_ColorOnVel.generated.h"

/**
 * 
 */
UCLASS(editinlinenew, hidecategories = Object, meta = (DisplayName = "DZ PColor On Vel"))
class DZPARTICLESTUDIO_API UDZParticleModule_ColorOnVel : public UParticleModuleColorBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Velocity)
	FRawDistributionVector ScaleVelocity;

	UPROPERTY(EditAnywhere, Category = Color)
	UTexture2D* ColorChangeTexture;

	virtual void Spawn(FParticleEmitterInstance* Owner, int32 Offset, float SpawnTime, FBaseParticle* ParticleBase) override;
	virtual void Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime) override;
};
