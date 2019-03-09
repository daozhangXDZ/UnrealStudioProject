#pragma once
#include "AnimGraphNode_SkeletalControlBase.h"
#include "DZAnimNode_SplineIK.h"
#include "EdGraph/EdGraphNodeUtils.h" 
#include "DZAnimNode_SpineIKEdit.generated.h"

UCLASS(MinimalAPI)
class UDZAnimNode_SpineIKEdit : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Settings)
	FDZAnimNode_SplineIK Node;

public:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FEditorModeID GetEditorMode() const override;
	virtual void Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent * PreviewSkelMeshComp) const override;
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override
	{
		return &Node;
	}
protected:
	virtual FText GetControllerDescription() const override;

private:
	/** Constructing FText strings can be costly, so we cache the node's title */
	FNodeTitleTextTable CachedNodeTitles;
};