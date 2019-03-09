// Fill out your copyright notice in the Description page of Project Settings.

#include "DZParticleModule_ColorOnVel.h"
#include "ConstructorHelpers.h"
#include "Distributions/DistributionVectorConstant.h"

UDZParticleModule_ColorOnVel::UDZParticleModule_ColorOnVel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bSpawnModule = true;
	bUpdateModule = true;
	
	/*UDistributionVectorConstant* DistributionScaleVelocity = ConstructorHelpers::FObjectFinder<UDistributionVectorConstant>(TEXT("/Game/Distributions/DistributionVectorConstant")).Object;
	DistributionScaleVelocity->Constant = FVector(1.0f, 1.0f, 1.0f);
	ScaleVelocity.Distribution = DistributionScaleVelocity;*/
}


void UDZParticleModule_ColorOnVel::Spawn(FParticleEmitterInstance* Owner, int32 Offset, float SpawnTime, FBaseParticle* ParticleBase)
{
	//SPAWN_INIT 是一个可以创建一个对正在产生的粒子的 FBaseParticle 引用的宏指令，
	//以及在访问粒子数据时常用的一些其他值，
	//例如，将跟踪偏移到粒子净荷中等等。要了解全部详细信息，
	//请参阅 //depot/UE4/Engine/Source/Runtime/Engine/Public/ParticleHelper.h。
	SPAWN_INIT;
	{
		FVector ColorScale = FVector(1.0f, 1.0f, 1.0f);
		Particle.Color = FLinearColor(
			Particle.BaseColor.R + Particle.BaseColor.R * Particle.Velocity.X * ColorScale.X,
			Particle.BaseColor.G + Particle.BaseColor.G * Particle.Velocity.Y * ColorScale.Y,
			Particle.BaseColor.B + Particle.BaseColor.B * Particle.Velocity.Z * ColorScale.Z
		);
	}
}

void UDZParticleModule_ColorOnVel::Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime)
{
	//BEGIN_UPDATE_LOOP/END_UPDATE_LOOP 是宏指令，
	//它会创建可以在所有活动的粒子中循环代码块并在每个粒子上执行在粒子之间包含的代码。
	//请参阅 UnParticleHelper.h 了解全部详细信息。
	BEGIN_UPDATE_LOOP;
	{
		FVector ColorScale = FVector(1.0f, 1.0f, 1.0f);
		Particle.Color = FLinearColor(
			Particle.BaseColor.R + Particle.BaseColor.R * Particle.Velocity.X * ColorScale.X,
			Particle.BaseColor.G + Particle.BaseColor.G * Particle.Velocity.Y * ColorScale.Y,
			Particle.BaseColor.B + Particle.BaseColor.B * Particle.Velocity.Z * ColorScale.Z
		);
	}
	END_UPDATE_LOOP;
}