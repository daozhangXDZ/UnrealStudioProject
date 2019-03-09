#include "DZParticleModule_PosMoveBySpline.h"
#include "Distributions/DistributionVectorUniform.h"
#include "ParticleHelper.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/TypeData/ParticleModuleTypeDataGpu.h"
#include "Particles/ParticleLODLevel.h"
#include "Particles/ParticleModuleRequired.h"


UDZParticleModule_PosMoveBySpline::UDZParticleModule_PosMoveBySpline(const FObjectInitializer &obj)
	:Super(obj)
{
	bSpawnModule = true;
	bUpdateModule = true;
}

/** Initializes the default values for this property */
void UDZParticleModule_PosMoveBySpline::InitializeDefaults()
{
	if (!PosCurvy.IsCreated())
	{
		UDistributionVectorUniform* DistributionPosCurvy = NewObject<UDistributionVectorUniform>(this, TEXT("DistributionPosCurvy"));
		DistributionPosCurvy->Min = FVector(0.0f, 0.0f, 0.0f);
		DistributionPosCurvy->Max = FVector(1.0f, 1.0f, 1.0f);
		PosCurvy.Distribution = DistributionPosCurvy;
	}
}

//Begin UObject Interface
#if WITH_EDITOR
void UDZParticleModule_PosMoveBySpline::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	InitializeDefaults();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR
void UDZParticleModule_PosMoveBySpline::PostInitProperties()
{
	Super::PostInitProperties();
	if (!HasAnyFlags(RF_ClassDefaultObject | RF_NeedLoad))
	{
		InitializeDefaults();
	}
}
//~ End UObject Interface

//~ Begin UParticleModule Interface
void UDZParticleModule_PosMoveBySpline::CompileModule(struct FParticleEmitterBuildInfo& EmitterInfo)
{
	EmitterInfo.SpawnModules.Add(this);
}



void UDZParticleModule_PosMoveBySpline::Spawn(FParticleEmitterInstance * Owner, int32 Offset, float SpawnTime, FBaseParticle * ParticleBase)
{
	SPAWN_INIT;
	FVector LocationOffset= PosCurvy.GetValue(Particle.RelativeTime, Owner->Component);;
	LocationOffset = Owner->EmitterToSimulation.TransformVector(LocationOffset);
	Particle.Location = LocationOffset;

}

void UDZParticleModule_PosMoveBySpline::Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime)
{
	BEGIN_UPDATE_LOOP;
	FVector LocationOffset = PosCurvy.GetValue(Particle.RelativeTime, Owner->Component);;
	LocationOffset = Owner->EmitterToSimulation.TransformVector(LocationOffset);
	Particle.Location = LocationOffset;
	END_UPDATE_LOOP;
}



void UDZParticleModule_PosMoveBySpline::Render3DPreview(FParticleEmitterInstance * Owner, const FSceneView * View, FPrimitiveDrawInterface * PDI)
{

#if	WITH_EDITOR

#endif	//#if WITH_EDITOR
}

bool UDZParticleModule_PosMoveBySpline::IsValidForLODLevel(UParticleLODLevel* LODLevel, FString& OutErrorString)
{
	return true;
}