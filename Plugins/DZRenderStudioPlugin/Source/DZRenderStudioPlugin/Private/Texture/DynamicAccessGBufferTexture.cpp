#include "DynamicAccessGBufferTexture.h"
#include "private/PostProcess/SceneRenderTargets.h"
#include "Engine.h"
#include "RHICommandList.h"

UDynamicAccessGBufferTexture::UDynamicAccessGBufferTexture()
{

}

UDynamicAccessGBufferTexture::~UDynamicAccessGBufferTexture()
{
	canvasPixelData.release();
	canvasPixelData = nullptr;
}


void UDynamicAccessGBufferTexture::InitializeTexture(const int32 pixelsH, const int32 pixelsV, FColor pFillColor)
{
	//dynamic texture initialization
	canvasWidth = pixelsH;
	canvasHeight = pixelsV;

	mTexture = UTexture2D::CreateTransient(canvasWidth, canvasHeight);
#if WITH_EDITORONLY_DATA
	mTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
#endif
	mTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	mTexture->SRGB = 1;
	mTexture->AddToRoot();
	mTexture->Filter = TextureFilter::TF_Nearest;
	mTexture->UpdateResource();

	echoUpdateTextureRegion = std::unique_ptr<FUpdateTextureRegion2D>(new FUpdateTextureRegion2D(0, 0, 0, 0, canvasWidth, canvasHeight));


	// buffers initialization
	bytesPerPixel = 4; // r g b a
	bufferPitch = canvasWidth * bytesPerPixel;
	bufferSize = canvasWidth * canvasHeight * bytesPerPixel;
	canvasPixelData = std::unique_ptr<uint8[]>(new uint8[bufferSize]);

	mFillColor.R = pFillColor.R;
	mFillColor.G = pFillColor.G;
	mFillColor.B = pFillColor.B;
	mFillColor.A = pFillColor.A;
	ClearTexture();
}

void UDynamicAccessGBufferTexture::CaputerGBuffer()
{
	if (mTexture == nullptr)
	{
		return;
	}
	ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
		DZRenderSutioBP_InterceptSceneGBufferToRenderTarget,
		UDynamicAccessGBufferTexture*, DynamicTextureTarget, this,
		{
			DynamicTextureTarget->CaputerGBuffer_RenderThread();
		}
	);
}

void UDynamicAccessGBufferTexture::CaputerGBuffer_RenderThread()
{
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();
	//计数加一避免Render完成后直接清空了GBuffer,但会慢一帧，你猜
	FSceneRenderTargets::Get(RHICmdList).AdjustGBufferRefCount(RHICmdList, 1);
	FSceneRenderTargets& SceneContext = FSceneRenderTargets::Get(RHICmdList);
	if (SceneContext.GBufferA)
	{
		FTexture2DRHIRef vTextTarget = SceneContext.GetGBufferATexture();
		uint32 LolStride = 0;
		char* TextureDataPtr = (char*)RHICmdList.LockTexture2D(vTextTarget, 0, EResourceLockMode::RLM_ReadOnly, LolStride, false);
		uint8* Bitmap = new uint8[vTextTarget->GetSizeY() * vTextTarget->GetSizeX() * 4];
		for (uint32 Row = 0; Row < (uint32)vTextTarget->GetSizeY(); ++Row)
		{
			uint32* PixelPtr = (uint32*)TextureDataPtr;
			//Since we are using our custom UINT format, we need to unpack it here to access the actual colors
			for (uint32 Col = 0; Col < vTextTarget->GetSizeX(); ++Col)
			{
				uint32 EncodedPixel = *PixelPtr;
				Bitmap[Row * (uint32)vTextTarget->GetSizeX() + Col * 4 + 0] = (EncodedPixel & 0x000000FF);
				Bitmap[Row *(uint32)vTextTarget->GetSizeX() + Col * 4 + 1] = (EncodedPixel & 0x0000FF00) >> 8;
				Bitmap[Row * (uint32)vTextTarget->GetSizeX() + Col * 4 + 2] = (EncodedPixel & 0x00FF0000) >> 16;
				Bitmap[Row *(uint32)vTextTarget->GetSizeX() + Col * 4 + 3] = (EncodedPixel & 0xFF000000) >> 24;
				PixelPtr++;
			}
			TextureDataPtr += LolStride;
		}
		RHICmdList.UnlockTexture2D(vTextTarget, 0, false);
		overrideTexture(Bitmap, vTextTarget->GetSizeX(), vTextTarget->GetSizeY());
		delete[] Bitmap;
		Bitmap = nullptr;
	}
	//移除
	FSceneRenderTargets::Get(RHICmdList).AdjustGBufferRefCount(RHICmdList, -1);
}

void UDynamicAccessGBufferTexture::UpdateTexture()
{
	if (IsInGameThread())
	{
		if (echoUpdateTextureRegion)
		{
			mTexture->UpdateTextureRegions((int32)0, (uint32)1, echoUpdateTextureRegion.get(), (uint32)bufferPitch, (uint32)bytesPerPixel, canvasPixelData.get());
		}
	}
}


void UDynamicAccessGBufferTexture::ClearTexture()
{
	uint8* canvasPixelPtr = canvasPixelData.get();
	for (int i = 0; i < canvasWidth * canvasHeight; ++i)
	{
		setPixelColor(canvasPixelPtr, mFillColor.R, mFillColor.G, mFillColor.B, mFillColor.A); //white
		canvasPixelPtr += bytesPerPixel;
	}
	UpdateTexture();
}

void UDynamicAccessGBufferTexture::overrideTexture(uint8 * pixelsArr, int32 width, int32 height)
{
	uint8* canvasPixelPtr = canvasPixelData.get();
	int32 minWidth = width < canvasWidth ? width:canvasWidth;
	int32 minHeight = height < canvasHeight ? height : canvasHeight;
	int i = 0;
	for (; i < minHeight; ++i)
	{
		int j = 0;
		for (j = 0; j< minWidth; ++j)
		{
			setPixelColor(canvasPixelPtr, pixelsArr[i*width+j*4], pixelsArr[i*width + j * 4 + 1], pixelsArr[i*width + j * 4 + 2], pixelsArr[i*width + j * 4 + 3]); //white
			//setPixelColor(canvasPixelPtr, mFillColor.R, mFillColor.G, mFillColor.B, mFillColor.A); //white
			canvasPixelPtr += bytesPerPixel;
		}
		for (j = minWidth; j< canvasWidth; ++j)
		{
			setPixelColor(canvasPixelPtr, mFillColor.R, mFillColor.G, mFillColor.B, mFillColor.A); //white
			canvasPixelPtr += bytesPerPixel;
		}
	}
	for (; i < canvasHeight; ++i)
	{
		
		for (int j = 0; j < canvasWidth; ++j)
		{
			setPixelColor(canvasPixelPtr, mFillColor.R, mFillColor.G, mFillColor.B, mFillColor.A); //white
			canvasPixelPtr += bytesPerPixel;
		}
	}
	
}

void UDynamicAccessGBufferTexture::setPixelColor(uint8 *& pointer, uint8 red, uint8 green, uint8 blue, uint8 alpha)
{
	*pointer = blue; //b
	*(pointer + 1) = green; //g
	*(pointer + 2) = red; //r
	*(pointer + 3) = alpha; //a
}
