using UnrealBuildTool;

public class Chapter_10Editor : ModuleRules
{
    public Chapter_10Editor(ReadOnlyTargetRules Target) : 
    base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", 
        "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", 
        "ShaderCore", "MainFrame", "AssetTools", "AppFramework", 
        "PropertyEditor"});
    
       PublicDependencyModuleNames.Add("Chapter_10");

        PrivateDependencyModuleNames.AddRange(new string[] { 
        "UnrealEd", "Slate", "SlateCore", "EditorStyle", 
        "GraphEditor", "BlueprintGraph" });

    }
}