#pragma once
#include "AnimGraphNode_SkeletalControlBase.h"
#include "DZAnimNode_ScaleBone.h"
#include "EdGraph/EdGraphNodeUtils.h" 
#include "DZAnimNode_ScaleBoneEdit.generated.h"

UCLASS(MinimalAPI)
class UDZAnimNode_ScaleBoneEdit : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Settings)
	FDZAnimNode_ScaleBone Node;

public:

	virtual FText GetTooltipText() const override;

	virtual void CopyNodeDataToPreviewNode(FAnimNode_Base* AnimNode) override;


	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual FEditorModeID GetEditorMode() const override;
	virtual void Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent * PreviewSkelMeshComp) const override;

	void SetDefaultValue(const FString& InDefaultValueName, const FTransform& InValue);
protected:

	virtual FText GetControllerDescription() const override;
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override { return &Node; }


};