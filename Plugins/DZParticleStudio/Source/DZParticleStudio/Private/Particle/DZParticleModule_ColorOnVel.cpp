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
	//SPAWN_INIT ��һ�����Դ���һ�������ڲ��������ӵ� FBaseParticle ���õĺ�ָ�
	//�Լ��ڷ�����������ʱ���õ�һЩ����ֵ��
	//���磬������ƫ�Ƶ����Ӿ����еȵȡ�Ҫ�˽�ȫ����ϸ��Ϣ��
	//����� //depot/UE4/Engine/Source/Runtime/Engine/Public/ParticleHelper.h��
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
	//BEGIN_UPDATE_LOOP/END_UPDATE_LOOP �Ǻ�ָ�
	//���ᴴ�����������л��������ѭ������鲢��ÿ��������ִ��������֮������Ĵ��롣
	//����� UnParticleHelper.h �˽�ȫ����ϸ��Ϣ��
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