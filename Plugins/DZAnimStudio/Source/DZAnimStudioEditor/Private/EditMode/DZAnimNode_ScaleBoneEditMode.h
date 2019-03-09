#pragma once
#include "CoreMinimal.h"
#include "UnrealWidget.h"
#include "AnimNodeEditMode.h"
#include "DZAnimNode_ScaleBoneEdit.h"
#include "DZAnimBaseNodeEditMode.h"
class FEditorViewportClient;
class FPrimitiveDrawInterface;
class USkeletalMeshComponent;
struct FViewportClick;

class FDZAnimNode_ScaleBoneEditMode : public FDZAnimBaseNodeEditMode
{
public:
	FDZAnimNode_ScaleBoneEditMode();
};
