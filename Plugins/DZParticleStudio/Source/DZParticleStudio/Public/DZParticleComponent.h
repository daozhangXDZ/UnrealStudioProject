// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Particles/ParticleSystemComponent.h"
#include "DZParticleComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Rendering, Common), hidecategories = Object, hidecategories = Physics, hidecategories = Collision, showcategories = Trigger, editinlinenew, meta = (BlueprintSpawnableComponent))
class DZPARTICLESTUDIO_API UDZParticleComponent : public UParticleSystemComponent
{
	GENERATED_UCLASS_BODY()

protected:
	virtual void OnRegister() override;
	virtual void OnUnregister()  override;

public:
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;
	
	/** Change the ParticleSystem used by this ParticleSystemComponent */
	UFUNCTION(BlueprintCallable, Category = "Effects|Components|DZParticleSystem")
	void IncressAndCombatTemplate(class UParticleSystem* NewTemplate);
};
