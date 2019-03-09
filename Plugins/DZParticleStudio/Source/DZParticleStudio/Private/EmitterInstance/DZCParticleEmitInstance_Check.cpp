#include "DZCParticleEmitInstance_Check.h"
#include "Particles/ParticleLODLevel.h"
#include "ParticleHelper.h"
//#include "DZCParticleDynamicData.h"

FDZCParticleEmitInstance_Check::FDZCParticleEmitInstance_Check()
	:FParticleEmitterInstance()
{

}

FDZCParticleEmitInstance_Check::~FDZCParticleEmitInstance_Check()
{
}

FDynamicEmitterDataBase * FDZCParticleEmitInstance_Check::GetDynamicData(bool bSelected, ERHIFeatureLevel::Type InFeatureLevel)
{
	/*UParticleLODLevel* LODLevel = SpriteTemplate->GetCurrentLODLevel(this);
	if (IsDynamicDataRequired(LODLevel) == false || !bEnabled)
	{
		return NULL;
	}
	FDZDynamicSpriteEmitterData* NewEmitterData = new FDZDynamicSpriteEmitterData(LODLevel->RequiredModule);
	FDynamicEmitterReplayDataBase pa = NewEmitterData->GetSource();
	if (!FillReplayData(pa))
	{
		delete NewEmitterData;
		return NULL;*/
	//}
	//NewEmitterData->Init(bSelected);

	return NULL;
}

FDynamicEmitterReplayDataBase * FDZCParticleEmitInstance_Check::GetReplayData()
{
	return nullptr;
}

void FDZCParticleEmitInstance_Check::GetAllocatedSize(int32 & OutNum, int32 & OutMax)
{
}

void FDZCParticleEmitInstance_Check::GetResourceSizeEx(FResourceSizeEx & CumulativeResourceSize)
{
}

bool FDZCParticleEmitInstance_Check::FillReplayData(FDynamicEmitterReplayDataBase & OutData)
{
	return false;
}
