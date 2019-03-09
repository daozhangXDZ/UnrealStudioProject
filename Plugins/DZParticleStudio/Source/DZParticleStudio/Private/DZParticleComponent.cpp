// Fill out your copyright notice in the Description page of Project Settings.

#include "DZParticleComponent.h"
#include "ParticleEmitterInstances.h"
#include "Particles/ParticleSystem.h"
#include "Particles/Emitter.h"
#include "ParticleHelper.h"
#include "Particles/ParticleEmitter.h"

UDZParticleComponent::UDZParticleComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UDZParticleComponent::OnRegister()
{
	Super::OnRegister();
}

void UDZParticleComponent::OnUnregister()
{
	Super::OnUnregister();
}

FBoxSphereBounds UDZParticleComponent::CalcBounds(const FTransform & LocalToWorld) const
{
	return FBoxSphereBounds();
}

FPrimitiveSceneProxy * UDZParticleComponent::CreateSceneProxy()
{
	return nullptr;
}

void UDZParticleComponent::Activate(bool bReset)
{
	Super::Activate(bReset);
}

void UDZParticleComponent::Deactivate()
{
	Super::Deactivate();
}

void UDZParticleComponent::IncressAndCombatTemplate(UParticleSystem * NewTemplate)
{
}
