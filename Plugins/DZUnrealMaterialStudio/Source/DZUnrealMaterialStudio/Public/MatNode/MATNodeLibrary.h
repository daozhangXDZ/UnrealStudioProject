// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/Texture.h"
#include "MATNodeLibrary.generated.h"

UENUM(BlueprintType)
enum EMATNodePreNodeType
{
	E_BaseColor = 0,
	E_Met = 1,
	E_Spec = 2,
	E_Rou = 3,
	E_Opacity = 4,
	E_OpacityMask = 5,
	E_Ao = 6
};
/**
 * @author:BaiPaoXD 
 * this is Studio And SomeNodeLib On MateriaNode
 */
UCLASS()
class DZUNREALMATERIALSTUDIO_API UMATNodeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category= "MaterialStudio|MatNodeLib")
	static UMaterial* QuickPreviewTextureOnMaterialBNode(const UTexture* pTexture,const UMaterial* pMaterial, EMATNodePreNodeType pPreviewType);
	
	
};
