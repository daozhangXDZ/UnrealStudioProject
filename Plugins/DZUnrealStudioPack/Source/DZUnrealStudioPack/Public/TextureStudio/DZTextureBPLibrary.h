#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFrameWork/HUD.h"
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "DZTextureBPLibrary.generated.h"

/*
*	Function library class.SceneRenderTargets
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UDZUnrealTextureBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable ,meta = (DisplayName = "Execute RandomArrayHUDTexureDraw", Keywords = "DZUnrealStudioPack RandomArrayHUDTexureDraw"), Category = "DZUnrealStudioPack|DZTextureBPLibrary")
	static void RandomArrayHUDTexureDraw(UTexture* pTexture, AHUD* rHUD, int randomCount, int textureWidth, int textureHeight, int sizeY, int sizeX, float scale, bool isScalePos);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute CreateTexture2DwithData", Keywords = "DZUnrealStudioPack CreateTexture2DwithData"), Category = "DZUnrealStudioPack|DZTextureBPLibrary")
	static UTexture2D* CreateTexture2DwithData(const int32 width, const int32 Height, const TArray<FColor>& Pixels);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute CreateEnableSaveTexture2DwithData", Keywords = "DZUnrealStudioPack CreateEnableSaveTexture2DwithData"), Category = "DZUnrealStudioPack|DZTextureBPLibrary")
	static UTexture2D* CreateEnableSaveTexture2DwithData(const int32 width, const int32 Height, const TArray<FColor>& Pixels, FString vSavePath, FString TextureName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute UpdateTexture2DWithData", Keywords = "DZUnrealStudioPack UpdateTexture2DWithData"), Category = "DZUnrealStudioPack|DZTextureBPLibrary")
	static void UpdateTexture2DWithData(const float u0,const float u1, const float u2, const float u3, const TArray<FColor>& Pixels);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute GetCurrSceneDepthBuffToTexture", Keywords = "DZUnrealStudioPack GetCurrSceneDepthBuffToTexture"), Category = "DZUnrealStudioPack|DZTextureBPLibrary")
	static void GetCurrSceneDepthBuffToTexture(UObject* WorldContextObject,UTexture2D* pTarget);
};
