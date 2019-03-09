#pragma once
#include <memory>
#include "Engine/Texture2D.h"
#include "Object.h"
#include "DynamicAccessGBufferTexture.generated.h"

UCLASS(Blueprintable, BlueprintType)
class DZRENDERSTUDIOPLUGIN_API UDynamicAccessGBufferTexture : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		UTexture2D* mTexture;

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void InitializeTexture(const int32 pixelsH, const int32 pixelsV,FColor pFillColor);

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void CaputerGBuffer();

		void CaputerGBuffer_RenderThread();

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void UpdateTexture();

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void ClearTexture();

	UDynamicAccessGBufferTexture();
	~UDynamicAccessGBufferTexture();
private:
	// canvas
	std::unique_ptr<uint8[]> canvasPixelData;
	int32 canvasWidth;
	int32 canvasHeight;
	int bytesPerPixel;
	int bufferPitch;
	int bufferSize;

	std::unique_ptr<FUpdateTextureRegion2D> echoUpdateTextureRegion;
	void setPixelColor(uint8*& pointer, uint8 red, uint8 green, uint8 blue, uint8 alpha);
	void overrideTexture(uint8* pixelsArr, int32 width, int32 height);
	FColor mFillColor;
};