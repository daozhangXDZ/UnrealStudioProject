using UnrealBuildTool;
using System.IO;
public class DZAnimStudioEditor : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
    public DZAnimStudioEditor(ReadOnlyTargetRules Target) : base(Target)
#else
    public DZAnimStudioEditor(TargetInfo Target)
#endif

    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../DZAnimStudio/Public"));
        PublicIncludePaths.Add(ModuleDirectory);
        PublicIncludePaths.AddRange(
			new string[] {
                "Editor/AnimGraph/Public",
                "Editor/AdvancedPreviewScene/Public"
//                 "Editor/AnimGraph/Classes",
				// ... add public include paths required here ...
			}
            );
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"DZAnimStudioEditor/Private",
                "DZAnimStudio/Private"
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "AnimGraphRuntime",
                "BlueprintGraph",
                "DZAnimStudio",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "InputCore",
                "UnrealEd",
                "GraphEditor",
                "PropertyEditor",
                "EditorStyle",
                "AnimGraph",
				// ... add private dependencies that you statically link with here ...	
			}
			);
        PrivateIncludePathModuleNames.AddRange(
            new string[] {
                "Persona",
                "SkeletonEditor",
#if WITH_FORWARDED_MODULE_RULES_CTOR
                "AdvancedPreviewScene",
#endif
            }
        );
        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}