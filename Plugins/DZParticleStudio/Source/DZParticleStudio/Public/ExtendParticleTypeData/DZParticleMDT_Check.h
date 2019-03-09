#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Particles/TypeData/ParticleModuleTypeDataBase.h"
#include "ParticleDefinitions.h"
#include "DZParticleMDT_Check.generated.h"

UCLASS(editinlinenew, collapsecategories, hidecategories = Object)
class DZPARTICLESTUDIO_API UDZParticleMDT_Check : public UParticleModuleTypeDataBase
{

	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Color)
	FRawDistributionVector Spin;



	/**
   *   创建自定义 ParticleEmitterInstance。
   *
   *   @param  InEmitterParent           UParticleEmitter 可以具有这个 TypeData 模型。
   *   @param  InComponent               UParticleSystemComponent 可以‘拥有’正在进行创建的发射器实例。
   *   @return FParticleEmitterInstance* 创建发射器实例。
   */
	virtual FParticleEmitterInstance*   CreateInstance(UParticleEmitter* InEmitterParent, UParticleSystemComponent* InComponent);
};