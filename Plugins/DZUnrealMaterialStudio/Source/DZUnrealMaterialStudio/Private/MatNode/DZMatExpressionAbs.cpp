#include "DZMatExpressionAbs.h"
#include "MaterialCompiler.h"

#define LOCTEXT_NAMESPACE "DZMaterialExpression"

UDZMatExpressionAbs::UDZMatExpressionAbs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		FText NAME_Math;
		FConstructorStatics()
			: NAME_Math(LOCTEXT("Math", "Math"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

#if WITH_EDITORONLY_DATA
	MenuCategories.Add(ConstructorStatics.NAME_Math);
#endif
}

#if WITH_EDITOR
int32 UDZMatExpressionAbs::Compile(FMaterialCompiler * Compiler, int32 OutputIndex)
{
	int32 Result = INDEX_NONE;

	if (!Input.GetTracedInput().Expression)
	{
		// an input expression must exist
		Result = Compiler->Errorf(TEXT("Missing DZAbs input"));
	}
	else
	{
		// evaluate the input expression first and use that as
		// the parameter for the Abs expression
		Result = Compiler->Abs(Input.Compile(Compiler));
	}

	return Result;
}
#endif

void UDZMatExpressionAbs::GetCaption(TArray<FString>& OutCaptions) const
{
	OutCaptions.Add(TEXT("DZ_Abs"));
}
#undef LOCTEXT_NAMESPACE
