#pragma once
#include "ParticleEmitterInstances.h"
#include "ExtendParticleTypeData/DZParticleMDT_Check.h"

struct DZPARTICLESTUDIO_API FDZCParticleEmitInstance_Check : public FParticleEmitterInstance
{
public:
	/** Constructor	*/
	FDZCParticleEmitInstance_Check();

	/** Destructor	*/
	virtual ~FDZCParticleEmitInstance_Check();

	/**
	 *	Retrieves the dynamic data for the emitter
	 */
	virtual FDynamicEmitterDataBase* GetDynamicData(bool bSelected, ERHIFeatureLevel::Type InFeatureLevel) override;

	/**
	 *	Retrieves replay data for the emitter
	 *
	 *	@return	The replay data, or NULL on failure
	 */
	virtual FDynamicEmitterReplayDataBase* GetReplayData() override;

	/**
	 *	Retrieve the allocated size of this instance.
	 *
	 *	@param	OutNum			The size of this instance
	 *	@param	OutMax			The maximum size of this instance
	 */
	virtual void GetAllocatedSize(int32& OutNum, int32& OutMax) override;

	/**
	 * Returns the size of the object/ resource for display to artists/ LDs in the Editor.
	 *
	 * @param	Mode	Specifies which resource size should be displayed. ( see EResourceSizeMode::Type )
	 * @return  Size of resource as to be displayed to artists/ LDs in the Editor.
	 */
	virtual void GetResourceSizeEx(FResourceSizeEx& CumulativeResourceSize) override;

protected:

	/**
	 * Captures dynamic replay data for this particle system.
	 *
	 * @param	OutData		[Out] Data will be copied here
	 *
	 * @return Returns true if successful
	 */
	virtual bool FillReplayData(FDynamicEmitterReplayDataBase& OutData) override;
};