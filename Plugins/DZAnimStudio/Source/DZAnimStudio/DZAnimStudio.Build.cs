using UnrealBuildTool;
using System.IO;
public class DZAnimStudio : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
    public DZAnimStudio(ReadOnlyTargetRules Target) : base(Target)
#else
	public DZAnimStudio(TargetInfo Target)
#endif
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
		PublicIncludePaths.Add(ModuleDirectory);
		PublicIncludePaths.AddRange(
			new string[] {
				"Runtime/Core/Public/Modules",
				"Runtime/AnimGraphRuntime/Public/BoneControllers",
				// ... add other public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				"DZAnimStudio/Private",
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
				// ... add other public dependencies that you statically link with here ...
			}
			);
	}
}