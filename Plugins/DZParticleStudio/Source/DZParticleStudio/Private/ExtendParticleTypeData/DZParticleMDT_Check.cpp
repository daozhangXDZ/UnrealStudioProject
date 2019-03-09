#include "DZParticleMDT_Check.h"
#include "EmitterInstance/DZCParticleEmitInstance_Check.h"
#include "Distributions/DistributionVectorConstant.h"
#include "ConstructorHelpers.h"

UDZParticleMDT_Check::UDZParticleMDT_Check(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//UDistributionVectorConstant* DistributionSpin = ConstructorHelpers::FObjectFinder<UDistributionVectorConstant>(TEXT("DistributionSpin"))->FObjectFinder(this);
	//UDistributionVectorConstant* DistributionSpin = ConstructorHelpers::CreateDefaultSubobject<UDistributionVectorConstant>(this, TEXT("DistributionSpin"));
	/*DistributionSpin->Constant = FVector(0.0f, 0.0f, 0.0f);
	Spin.Distribution = DistributionSpin;*/
}


FParticleEmitterInstance* UDZParticleMDT_Check::CreateInstance(UParticleEmitter* InEmitterParent, UParticleSystemComponent* InComponent)
{
	FDZCParticleEmitInstance_Check* Checker_Inst = ::new FDZCParticleEmitInstance_Check();
	if (Checker_Inst)
	{
		// 初始化发射器的参数。
		Checker_Inst->InitParameters(InEmitterParent, InComponent);
		Checker_Inst->Init();
		return Checker_Inst;
	}
	return NULL;
}