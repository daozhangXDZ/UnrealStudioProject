//#pragma once
//#pragma once
//#include "CoreMinimal.h"
//#include "UObject/ObjectMacros.h"
//#include "Classes/Kismet/BlueprintFunctionLibrary.h"
//#include "Engine/Texture.h"
//#include "ComputerShader_BP_Lib.generated.h"
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////���ʱ�䣺https://github.com/daozhangXDZ/DZSmallEngine /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///**
// * ���ڸ���������ɫ����Shader�Ļ��ȥ���ݽṹ
// */
//USTRUCT(BlueprintType)
//struct FCheckComputerData
//{
//	GENERATED_USTRUCT_BODY()
//		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
//		FLinearColor ColorOne;
//	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
//		FLinearColor ColorTwo;
//	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
//		FLinearColor Colorthree;
//	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
//		FLinearColor ColorFour;
//	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
//		int32 ColorIndex;
//};
//
//
//UCLASS(MinimalAPI, meta = (ScriptName = "TestShaderLibary"))
//class UTestComputerShaderBlueprintLibrary : public UBlueprintFunctionLibrary
//{
//	GENERATED_UCLASS_BODY()
//		UFUNCTION(BlueprintCallable, Category = "TestComputerShader|Check01", meta = (WorldContext = "WorldContextObject"))
//		static void DrawTestShaderRenderTarget(
//			class UTextureRenderTarget2D* OutputRenderTarget,
//			AActor* Ac,
//			FLinearColor MyColor,
//			UTexture* MyTexture,
//			FCheckComputerData ShaderStructData
//		);
//	UFUNCTION(BlueprintCallable, Category = "TestComputerShader|Check01", meta = (WorldContext = "WorldContextObject"))
//		static void UseMyComputeShader(
//			class UTextureRenderTarget2D* OutputRenderTarget,
//			AActor* Ac,
//			FCheckComputerData ShaderStructData
//		);
//};
