#include "DZParticleModule_SetRot.h"

UDZParticleModule_SetRot::UDZParticleModule_SetRot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bSpawnModule = true;
	bUpdateModule = true;
}

//    uint8 LockAxisFlags;
//    FVector LockAxis;
void UDZParticleModule_SetRot::Spawn(FParticleEmitterInstance* Owner, int32 Offset, float SpawnTime, FBaseParticle* ParticleBase)
{
}

void UDZParticleModule_SetRot::Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime)
{
}

#if WITH_EDITOR
void UDZParticleModule_SetRot::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	//UObject* OuterObj = GetOuter();
	//check(OuterObj);
	//UParticleLODLevel* LODLevel = Cast<UParticleLODLevel>(OuterObj);
	//if (LODLevel)
	//{
	//	// The outer is incorrect - warn the user and handle it
	//	/*UE_LOG(LogParticles, Warning, TEXT("UParticleModuleOrientationAxisLock has an incorrect outer... run FixupEmitters on package %s"),
	//		*(OuterObj->GetOutermost()->GetPathName()));*/
	//	OuterObj = LODLevel->GetOuter();
	//	UParticleEmitter* Emitter = Cast<UParticleEmitter>(OuterObj);
	//	check(Emitter);
	//	OuterObj = Emitter->GetOuter();
	//}
	//UParticleSystem* PartSys = PartSys = CastChecked<UParticleSystem>(OuterObj);

	//UProperty* PropertyThatChanged = PropertyChangedEvent.Property;
	//if (PropertyThatChanged)
	//{
	//	if (PropertyThatChanged->GetFName() == FName(TEXT("LockAxisFlags")))
	//	{
	//		PartSys->PostEditChangeProperty(PropertyChangedEvent);
	//	}
	//}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR

//void UDZParticleModule_SetRot::SetLockAxis(EParticleAxisLock eLockFlags)
//{
//	LockAxisFlags = eLockFlags;
//}