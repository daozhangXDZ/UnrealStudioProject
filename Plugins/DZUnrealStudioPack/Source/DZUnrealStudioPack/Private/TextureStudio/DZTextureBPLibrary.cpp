// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DZTextureBPLibrary.h"
#include "DZUnrealStudioPack.h"
#include "UObject/Package.h"
#include "Engine/Texture2D.h"
#include "Misc/PackageName.h"
#include "AssetRegistryModule.h"

#include "RHI.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "Serialization/BufferArchive.h"
#include "EngineGlobals.h"
#include "RenderingThread.h"
#include "Engine/Engine.h"
#include "CanvasTypes.h"
#include "Engine/Canvas.h"
#include "Misc/App.h"
#include "TextureResource.h"
#include "SceneUtils.h"
#include "Logging/MessageLog.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ImageUtils.h"
#include "OneColorShader.h"
#include "PipelineStateCache.h"
#include "ClearQuad.h"
#include "Engine/Texture2D.h"
//#include "Runtime/Renderer/Private/PostProcess/SceneRenderTargets.h"

UDZUnrealTextureBPLibrary::UDZUnrealTextureBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UDZUnrealTextureBPLibrary::RandomArrayHUDTexureDraw(UTexture* pTexture, AHUD* rHUD, int randomCount, int textureWidth, int textureHeight, int sizeY, int sizeX, float scale, bool isScalePos)
{
	for (int i = 0; i < randomCount; i++)
	{
		float vScreenX = FMath::RandRange(0, sizeX - (int)(textureWidth* scale));
		float vScreenY = FMath::RandRange(0, sizeY - (int)(textureHeight* scale));
		rHUD->DrawTextureSimple(pTexture, vScreenX, vScreenY, scale, isScalePos);
	}
}

UTexture2D* UDZUnrealTextureBPLibrary::CreateTexture2DwithData(const int32 width, const int32 Height, const TArray<FColor>& Pixels)
{
	if ((Pixels.Num() <= 0) || (width <= 0) || (Height <= 0))
	{
		return NULL;
	}

	UTexture2D* LoadedT2D = UTexture2D::CreateTransient(width, Height, EPixelFormat::PF_B8G8R8A8);
	if (LoadedT2D == nullptr)
	{
		return NULL;
	}

	void* TextureData = LoadedT2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureData, &Pixels[0], Pixels.Num() * sizeof(FColor));
	LoadedT2D->PlatformData->Mips[0].BulkData.Unlock();

	LoadedT2D->UpdateResource();
	return LoadedT2D;
}

UTexture2D* UDZUnrealTextureBPLibrary::CreateEnableSaveTexture2DwithData(const int32 width, const int32 Height, const TArray<FColor>& Pixels, FString vSavePath, FString TextureName)
{
	FString PackageName = FString::Printf(TEXT("/Game/%s/%s"), *vSavePath, *TextureName);
	UPackage* Package = CreatePackage(NULL, *PackageName);
	Package->FullyLoad();
	UTexture2D* NewTexture = NewObject<UTexture2D>(Package, *TextureName, RF_Public | RF_Standalone | RF_MarkAsRootSet);
	NewTexture->AddToRoot();				// This line prevents garbage collection of the texture
	NewTexture->PlatformData = new FTexturePlatformData();	// Then we initialize the PlatformData
	NewTexture->PlatformData->SizeX = width;
	NewTexture->PlatformData->SizeY = Height;
	NewTexture->PlatformData->NumSlices = 1;
	NewTexture->PlatformData->PixelFormat = EPixelFormat::PF_B8G8R8A8;
	
	uint8* vPixelsData = new uint8[width * Height * 4];
	for (int32 y = 0; y < Height; y++)
	{
		for (int32 x = 0; x < width; x++)
		{
			int32 curPixelIndex = ((y * width) + x);
			vPixelsData[4 * curPixelIndex] = Pixels[curPixelIndex].B;
			vPixelsData[4 * curPixelIndex + 1] = Pixels[curPixelIndex].G;
			vPixelsData[4 * curPixelIndex + 2] = Pixels[curPixelIndex].R;
			vPixelsData[4 * curPixelIndex + 3] = Pixels[curPixelIndex].A;
		}
	}
	
	FTexture2DMipMap* Mip = new(NewTexture->PlatformData->Mips) FTexture2DMipMap();
	Mip->SizeX = width;
	Mip->SizeY = Height;
	// Lock the texture so it can be modified
	Mip->BulkData.Lock(LOCK_READ_WRITE);
	uint8* TextureData = (uint8*)Mip->BulkData.Realloc(width * Height * 4);
	FMemory::Memcpy(TextureData, vPixelsData, sizeof(uint8) * Height * width * 4);
	Mip->BulkData.Unlock();


	NewTexture->Source.Init(width, Height, 1, 1, ETextureSourceFormat::TSF_BGRA8, vPixelsData);
	NewTexture->UpdateResource();
	Package->MarkPackageDirty();
	FAssetRegistryModule::AssetCreated(NewTexture);
	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
	bool bSaved = UPackage::SavePackage(Package, NewTexture, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);
	delete[] vPixelsData;	// Don't forget to free the memory here
	return NewTexture;
}

void UDZUnrealTextureBPLibrary::UpdateTexture2DWithData(const float u0, const float u1, const float u2, const float u3, const TArray<FColor>& Pixels)
{

}

void UDZUnrealTextureBPLibrary::GetCurrSceneDepthBuffToTexture(UObject* WorldContextObject,UTexture2D* pTarget)
{
	//UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	//ENQUEUE_RENDER_COMMAND(CaptureCommand)(
	//	[pTarget](FRHICommandListImmediate& RHICmdList)
	//{
	//	//FSceneRenderTargets& SceneContext = FSceneRenderTargets::Get(RHICmdList);
	//	//SceneContext.SceneDepthZ->GetRenderTargetItem().ShaderResourceTexture->
	//	//pTarget->UpdateResource();
	//}
	//);
}