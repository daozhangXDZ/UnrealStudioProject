// Fill out your copyright notice in the Description page of Project Settings.

#include "MATNodeLibrary.h"
#include "Materials/MaterialExpressionTextureSample.h"

UMaterial* UMATNodeLibrary::QuickPreviewTextureOnMaterialBNode(const UTexture* pTexture, const UMaterial* pMaterial, EMATNodePreNodeType pPreviewType)
{
	
	UMaterial* NewMaterial = NewObject<UMaterial>(const_cast<UMaterial*>(pMaterial));

	if (pTexture != nullptr)
	{
		// An initial texture was specified, add it and assign it to the BaseColor
		UMaterialExpressionTextureSample* TextureSampler = NewObject<UMaterialExpressionTextureSample>(NewMaterial);
		{
			TextureSampler->MaterialExpressionEditorX = -250;
			TextureSampler->Texture = const_cast<UTexture*>(pTexture);
			TextureSampler->AutoSetSampleType();
		}

		NewMaterial->Expressions.Add(TextureSampler);

		FExpressionOutput& Output = TextureSampler->GetOutputs()[0];

		FExpressionInput& Input = (FExpressionInput&)NewMaterial->BaseColor;
		if (TextureSampler->SamplerType == SAMPLERTYPE_Normal)
		{
			Input = (FExpressionInput&)NewMaterial->Normal;
		}
		switch (pPreviewType)
		{
			case E_Met:
				Input = (FExpressionInput&)NewMaterial->Metallic;
				break;

			case E_Spec:
				Input = (FExpressionInput&)NewMaterial->Specular;
				break;

			case E_Rou:
				Input = (FExpressionInput&)NewMaterial->Roughness;
				break;

			case E_Opacity:
				Input = (FExpressionInput&)NewMaterial->Opacity;
				break;

			case E_OpacityMask:
				Input = (FExpressionInput&)NewMaterial->OpacityMask;
				break;

			case E_Ao:
				Input = (FExpressionInput&)NewMaterial->AmbientOcclusion;
				break;

			default:
				Input = (FExpressionInput&)NewMaterial->BaseColor;
				break;
		}
		Input.Expression = TextureSampler;
		Input.Mask = Output.Mask;
		Input.MaskR = Output.MaskR;
		Input.MaskG = Output.MaskG;
		Input.MaskB = Output.MaskB;
		Input.MaskA = Output.MaskA;

		NewMaterial->PostEditChange();
	}

	return NewMaterial;
}

