#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "../DZParticleModule_NodeBase.h"
#include "DZParticleModule_SetRot.generated.h"

struct FParticleEmitterInstance;

UCLASS(editinlinenew, hidecategories = Object, MinimalAPI, meta = (DisplayName = "SetAndLockRot"))
class UDZParticleModule_SetRot : public UDZParticleModule_NodeBase
{
	GENERATED_UCLASS_BODY()

#if WITH_EDITOR
		virtual void	PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
	//~ End UObject Interface

	//~ Begin UParticleModule Interface
	virtual void	Spawn(FParticleEmitterInstance* Owner, int32 Offset, float SpawnTime, FBaseParticle* ParticleBase) override;
	virtual void	Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime) override;
	//~ End UParticleModule Interface

	//@todo document
	//virtual void	SetLockAxis(EParticleAxisLock eLockFlags);
};