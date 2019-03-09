#pragma once
#include <memory>
#include "Engine/Texture2D.h"
#include "Object.h"
#include "DynamicAccessGBufferRenderTarget.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EDZShowGbuffer : uint8
{
	VE_GDZSHOWBUFFERA 	UMETA(DisplayName = "ShowGBuffA"),
	VE_GDZSHOWBUFFERB 	UMETA(DisplayName = "ShowGBuffB"),
	VE_GDZSHOWBUFFERC	UMETA(DisplayName = "ShowGBuffC"),
	VE_GDZSHOWBUFFERD	UMETA(DisplayName = "ShowGBuffD"),
	VE_GDZSHOWBUFFERE	UMETA(DisplayName = "ShowGBuffE"),
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EDZCOPYGbufferType : uint8
{
	VE_GDZSHOWGBUFFER_COPYMIP 	UMETA(DisplayName = "COPY_Mip"),
	VE_GDZSHOWBUFFERR_COPYMEMO 	UMETA(DisplayName = "COPY_Memory"),
	VE_GDZSHOWBUFFERC_CPUARRAY	UMETA(DisplayName = "COPY_MemoryForWhile"),
};

USTRUCT()
struct FCommitRenderData
{
	GENERATED_BODY()
public:
	EDZCOPYGbufferType ECOPYBuffType;
	EDZShowGbuffer EShowBuff;
	UTextureRenderTarget2D* mTextureTarget;
	EPixelFormat format;
	int32 canvasWidth = 512;
	int32 canvasHeight = 512;
	bool isGetGBufferData = false;
};

UCLASS(Blueprintable, BlueprintType)
class DZRENDERSTUDIOPLUGIN_API UDynamicAccessGBufferRenderTarget : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DynamicAccessGBufferRenderTarget)
	EDZCOPYGbufferType ECOPYBuffType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DynamicAccessGBufferRenderTarget)
	EDZShowGbuffer EShowBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DynamicAccessGBufferRenderTarget)
	UTextureRenderTarget2D* mTextureTarget;

	UFUNCTION(BlueprintCallable, Category = DynamicAccessGBufferRenderTarget)
	void InitializeTexture(UTextureRenderTarget2D* pTextureTarget,EDZShowGbuffer pEShowBuff, EDZCOPYGbufferType pECOPYBuffType);

	UFUNCTION(BlueprintCallable, Category = DynamicAccessGBufferRenderTarget)
		void CaputerGBuffer();

	UFUNCTION(BlueprintCallable, Category = DynamicAccessGBufferRenderTarget)
		void ClearTexture();

	UDynamicAccessGBufferRenderTarget();
	~UDynamicAccessGBufferRenderTarget();

	static void CaputerGBufer_Rebuild_RenderThread(FCommitRenderData* pRenderData);
	static void CaputerGBuffer_RenderThread(FCommitRenderData* pRenderData);

	static void Copy_TextureRHI(FRHICommandListImmediate& RHICmdList, FRHITexture2D* pDesc, FRHITexture2D* pSrc);
	static void Copy_MemoryRHI(FRHICommandListImmediate& RHICmdList, FRHITexture2D* pDesc, FRHITexture2D* pSrc);
	static void Copy_CPUArrayRHI();

private:
	EPixelFormat format;
	UPROPERTY()
	FCommitRenderData CatchRenderData;

	UPROPERTY()
	bool isRebulidRenderTargetSuccess = false;
};