#pragma once 
#include "DZParticleModule_PosMove.h"
#include "Distributions/DistributionVector.h"
#include "DZParticleModule_PosMoveBySpline.generated.h"


class UParticleEmitter;
class UParticleLODLevel;
struct FParticleEmitterInstance;
/**
 * 小道粒子扩展: 产生粒子的位置基于纹理
 */
UCLASS(editinlinenew, hidecategories = Object, meta = (DisplayName = "DZPosMoveBySpline"))
class DZPARTICLESTUDIO_API UDZParticleModule_PosMoveBySpline : public UDZParticleModule_PosMove
{
	GENERATED_UCLASS_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = DZParticleModulePosCurvy)
	struct FRawDistributionVector PosCurvy;

	/** Ignored */
	UPROPERTY(EditAnywhere, Category = ParticleModuleSizeScale)
		uint32 EnableX : 1;

	/** Ignored */
	UPROPERTY(EditAnywhere, Category = ParticleModuleSizeScale)
		uint32 EnableY : 1;

	/** Ignored */
	UPROPERTY(EditAnywhere, Category = ParticleModuleSizeScale)
		uint32 EnableZ : 1;

	/** Initializes the default values for this property */
	void InitializeDefaults();

	//Begin UObject Interface
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
	virtual void PostInitProperties() override;
	//~ End UObject Interface

	//~ Begin UParticleModule Interface
	virtual void CompileModule(struct FParticleEmitterBuildInfo& EmitterInfo) override;
	//~ End UObject Interface

	//~ Begin UParticleModule Interface
	virtual void	Spawn(FParticleEmitterInstance* Owner, int32 Offset, float SpawnTime, FBaseParticle* ParticleBase) override;
	virtual void	Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime);
	virtual void	Render3DPreview(FParticleEmitterInstance* Owner, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;

	virtual bool	IsValidForLODLevel(UParticleLODLevel* LODLevel, FString& OutErrorString);
};
