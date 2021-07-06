// Battlecat Game. All Rights Reserved.

using UnrealBuildTool;

public class Battlecat : ModuleRules
{
    public Battlecat(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] 
        { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore",
            "Niagara",
            "PhysicsCore",
            "GameplayTasks",
            "NavigationSystem"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[]
        {
            "Battlecat/Public/Player",
            "Battlecat/Public/Components",
            "Battlecat/Public/Dev",
            "Battlecat/Public/Weapon",
            "Battlecat/Public/UI",
            "Battlecat/Public/Animations",
            "Battlecat/Public/Pickups",
            "Battlecat/Public/Weapon/Components",
            "Battlecat/Public/AI",
            "Battlecat/Public/AI/Tasks",
            "Battlecat/Public/AI/Services",
            "Battlecat/Public/AI/EQS",
            "Battlecat/Public/AI/Decorators",
            "Battlecat/Public/Menu",
            "Battlecat/Public/Menu/UI"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
