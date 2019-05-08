// VR IK Body Component
// (c) Yuri N Kalinin, 2017, ykasczc@gmail.com. All right reserved.

using UnrealBuildTool;
using System.IO;

public class VRIKBodyRuntime : ModuleRules
{
    public VRIKBodyRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Public")
            }
        );

        PublicIncludePaths.AddRange(
            new string[] {
                "Runtime/AnimGraphRuntime/Public/BoneControllers",
                "Runtime/Engine/Public/Animation"
            }
        );

        PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"HeadMountedDisplay",
				"AnimGraphRuntime"
			}
		);

	    PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
