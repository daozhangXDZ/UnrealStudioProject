// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DZRenderStudioPluginBPLibrary.h"
#include "DZRenderStudioPlugin.h"
#include "private/PostProcess/SceneRenderTargets.h"
#include "Engine.h"
#include "RHICommandList.h"
#include "IImageWrapper.h"

#define LOCTEXT_NAMESPACE "TestShader"  

UDZRenderStudioPluginBPLibrary::UDZRenderStudioPluginBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}



void UDZRenderStudioPluginBPLibrary::InterceptAccessGBuff_Texture(UDynamicAccessGBufferTexture* DynamicTexture, EDZShowGbuffer pEShowBuff, EDZCOPYGbufferType pECopyBuffType)
{
	/*UGameViewportClient*  vGViewPort = GEngine->GetWorld()->GetGameViewport();
	vGViewPort->scene*/
	DynamicTexture->CaputerGBuffer();
}

void UDZRenderStudioPluginBPLibrary::InterceptAccessGBuff_RenderTarget(UDynamicAccessGBufferRenderTarget* DynamicRenderTarget, EDZShowGbuffer pEShowBuff, EDZCOPYGbufferType pECopyBuffType)
{
	DynamicRenderTarget->CaputerGBuffer();
}


UDynamicAccessGBufferTexture* UDZRenderStudioPluginBPLibrary::CreateAccessGBuffTexture(int32 width, int32 height,FColor pColor, EDZShowGbuffer pEShowBuff, EDZCOPYGbufferType pECopyBuffType)
{
	UDynamicAccessGBufferTexture* vDynamicTexture = NewObject<UDynamicAccessGBufferTexture>();
	vDynamicTexture->AddToRoot();
	vDynamicTexture->InitializeTexture(width, height, pColor);
	return vDynamicTexture;
}

UDynamicAccessGBufferRenderTarget* UDZRenderStudioPluginBPLibrary::CreateAccessGBuffRenderTarget(UTextureRenderTarget2D* RenderTarget, EDZShowGbuffer pEShowBuff, EDZCOPYGbufferType pECopyBuffType)
{
	UDynamicAccessGBufferRenderTarget* vDynamicTexture = NewObject<UDynamicAccessGBufferRenderTarget>();
	vDynamicTexture->AddToRoot();
	vDynamicTexture->InitializeTexture(RenderTarget, pEShowBuff, pECopyBuffType);
	return vDynamicTexture;
}

#undef LOCTEXT_NAMESPACE  
