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
   *   �����Զ��� ParticleEmitterInstance��
   *
   *   @param  InEmitterParent           UParticleEmitter ���Ծ������ TypeData ģ�͡�
   *   @param  InComponent               UParticleSystemComponent ���ԡ�ӵ�С����ڽ��д����ķ�����ʵ����
   *   @return FParticleEmitterInstance* ����������ʵ����
   */
	virtual FParticleEmitterInstance*   CreateInstance(UParticleEmitter* InEmitterParent, UParticleSystemComponent* InComponent);
};