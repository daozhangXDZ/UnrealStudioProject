#include "DynamicAccessGBufferRenderTarget.h"
#include "private/PostProcess/SceneRenderTargets.h"
#include "Engine.h"
#include "RHICommandList.h"




UDynamicAccessGBufferRenderTarget::UDynamicAccessGBufferRenderTarget()
{

}

UDynamicAccessGBufferRenderTarget::~UDynamicAccessGBufferRenderTarget()
{
	
}

void UDynamicAccessGBufferRenderTarget::InitializeTexture(UTextureRenderTarget2D* pTextureTarget, EDZShowGbuffer pEShowBuff, EDZCOPYGbufferType pECOPYBuffType)
{
	if (mTextureTarget != pTextureTarget || EShowBuff != pEShowBuff || ECOPYBuffType != pECOPYBuffType)
	{
		mTextureTarget = pTextureTarget;
		EShowBuff = pEShowBuff;
		ECOPYBuffType = pECOPYBuffType;
		isRebulidRenderTargetSuccess = false;
	}
	
}

void UDynamicAccessGBufferRenderTarget::ClearTexture()
{

}


void UDynamicAccessGBufferRenderTarget::CaputerGBuffer()
{
	if (!CatchRenderData.isGetGBufferData)
	{
		isRebulidRenderTargetSuccess = false;
		CatchRenderData.EShowBuff = EShowBuff;
		CatchRenderData.ECOPYBuffType = ECOPYBuffType;
		CatchRenderData.mTextureTarget = mTextureTarget;
		ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
			DZRenderSutioBP_AccessGBufferRenderTarget_init,
			FCommitRenderData*, RenderData, &CatchRenderData,
			{
				UDynamicAccessGBufferRenderTarget::CaputerGBufer_Rebuild_RenderThread(RenderData);
			}
		);
	}
	else
	{
		if (!isRebulidRenderTargetSuccess)
		{
			if (IsInGameThread())
			{
				mTextureTarget->InitCustomFormat(CatchRenderData.canvasWidth, CatchRenderData.canvasHeight, CatchRenderData.format, false);
				mTextureTarget->ForceRebuildPlatformData();
			}
			isRebulidRenderTargetSuccess = true;
		}
		else
		{
			CatchRenderData.EShowBuff = EShowBuff;
			CatchRenderData.ECOPYBuffType = ECOPYBuffType;
			CatchRenderData.mTextureTarget = mTextureTarget;
			ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
				DZRenderSutioBP_InterceptSceneGBufferToRenderTarget,
				FCommitRenderData*, RenderData, &CatchRenderData,
				{
					UDynamicAccessGBufferRenderTarget::CaputerGBuffer_RenderThread(RenderData);
				}
			);
		}
	}
	
}

void UDynamicAccessGBufferRenderTarget::CaputerGBufer_Rebuild_RenderThread(FCommitRenderData* pRenderData)
{
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();
	//������һ����Render��ɺ�ֱ�������GBuffer,������һ֡�����
	FSceneRenderTargets::Get(RHICmdList).AdjustGBufferRefCount(RHICmdList, 1);
	FSceneRenderTargets& SceneContext = FSceneRenderTargets::Get(RHICmdList);
	if (SceneContext.GBufferA)
	{
		FTexture2DRHIRef vTextTarget;
		switch (pRenderData->EShowBuff)
		{
		case EDZShowGbuffer::VE_GDZSHOWBUFFERA:
			vTextTarget = SceneContext.GetGBufferATexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERB:
			vTextTarget = SceneContext.GetGBufferBTexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERC:
			vTextTarget = SceneContext.GetGBufferCTexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERD:
			vTextTarget = SceneContext.GetGBufferDTexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERE:
			vTextTarget = SceneContext.GetGBufferETexture();
			break;
		default:
			vTextTarget = SceneContext.GetGBufferATexture();
			break;
		}
	 
		pRenderData->format = vTextTarget->GetFormat();
		pRenderData->canvasWidth = vTextTarget->GetSizeX();
		pRenderData->canvasHeight = vTextTarget->GetSizeY();
		pRenderData->isGetGBufferData = true;
	}
	FSceneRenderTargets::Get(RHICmdList).AdjustGBufferRefCount(RHICmdList, -1);
}

void UDynamicAccessGBufferRenderTarget::CaputerGBuffer_RenderThread(FCommitRenderData* pRenderData)
{
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();
	//������һ����Render��ɺ�ֱ�������GBuffer,������һ֡�����
	FSceneRenderTargets::Get(RHICmdList).AdjustGBufferRefCount(RHICmdList, 1);
	FSceneRenderTargets& SceneContext = FSceneRenderTargets::Get(RHICmdList);
	if (SceneContext.GBufferA && pRenderData->mTextureTarget != nullptr)
	{
		FTexture2DRHIRef vTextTarget;
		switch (pRenderData->EShowBuff)
		{
		case EDZShowGbuffer::VE_GDZSHOWBUFFERA:
			vTextTarget = SceneContext.GetGBufferATexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERB:
			vTextTarget = SceneContext.GetGBufferBTexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERC:
			vTextTarget = SceneContext.GetGBufferCTexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERD:
			vTextTarget = SceneContext.GetGBufferDTexture();
			break;
		case EDZShowGbuffer::VE_GDZSHOWBUFFERE:
			vTextTarget = SceneContext.GetGBufferETexture();
			break;
			break;
		default:
			vTextTarget = SceneContext.GetGBufferATexture();
			break;
		}
		pRenderData->format = vTextTarget->GetFormat();
		if (pRenderData->canvasWidth != vTextTarget->GetSizeX())
		{
			pRenderData->isGetGBufferData = false;
			return;
		}
		FTextureReferenceRHIRef vTexRHIRef = pRenderData->mTextureTarget->TextureReference.TextureReferenceRHI;
		FRHITexture* vRTTexture = vTexRHIRef->GetTextureReference()->GetReferencedTexture();
		FRHITexture2D* vtex = (FRHITexture2D*)vRTTexture;
		if (vtex == nullptr)
		{
			return;
		}
		switch (pRenderData->ECOPYBuffType)
		{
		case EDZCOPYGbufferType::VE_GDZSHOWGBUFFER_COPYMIP:
			UDynamicAccessGBufferRenderTarget::Copy_TextureRHI(RHICmdList,vtex, vTextTarget);
			break;
		case EDZCOPYGbufferType::VE_GDZSHOWBUFFERR_COPYMEMO:
			UDynamicAccessGBufferRenderTarget::Copy_MemoryRHI(RHICmdList, vtex, vTextTarget);
			break;
		case EDZCOPYGbufferType::VE_GDZSHOWBUFFERC_CPUARRAY:
			UDynamicAccessGBufferRenderTarget::Copy_CPUArrayRHI();
			break;
		default:
			break;
		}
		RHICmdList.CopySharedMips(vtex, vTextTarget);
	}
	//�Ƴ�
	FSceneRenderTargets::Get(RHICmdList).AdjustGBufferRefCount(RHICmdList, -1);
}

//����SharedMip�Ĺ���ʽ��������һЩ
//��չ��ʽ
void UDynamicAccessGBufferRenderTarget::Copy_TextureRHI(FRHICommandListImmediate& RHICmdList,FRHITexture2D* pDesc,FRHITexture2D* pSrc)
{
	RHICmdList.CopySharedMips(pDesc, pSrc);
}

//�ڴ�CPY������Ҫ��ס�������ͻ����������Ⱦ���ܷ��ʣ�����ɵ�֡�ʡ�
void UDynamicAccessGBufferRenderTarget::Copy_MemoryRHI(FRHICommandListImmediate& RHICmdList, FRHITexture2D* pDesc, FRHITexture2D* pSrc)
{
	uint32 Lolstrid = 0;
	void * UAVRenderTargetData = RHILockTexture2D(pDesc, 0, RLM_WriteOnly, Lolstrid, true);
	void * UAVCSData = RHILockTexture2D(pSrc, 0, RLM_ReadOnly, Lolstrid, true);
	FMemory::Memcpy(UAVRenderTargetData, UAVCSData, GPixelFormats[pSrc->GetFormat()].BlockBytes * pSrc->GetSizeX() * pSrc->GetSizeY());
	RHICmdList.UnlockTexture2D(pDesc, 0, false);
	RHICmdList.UnlockTexture2D(pSrc, 0, false);
}

void UDynamicAccessGBufferRenderTarget::Copy_CPUArrayRHI()
{

}