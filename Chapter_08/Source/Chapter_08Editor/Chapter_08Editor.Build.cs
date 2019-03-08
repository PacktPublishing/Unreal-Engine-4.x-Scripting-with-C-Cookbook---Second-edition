// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Chapter_08Editor : ModuleRules
{
    public Chapter_08Editor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "ShaderCore", "MainFrame", "AssetTools", "AppFramework", "PropertyEditor" });

        PublicDependencyModuleNames.Add("Chapter_08");

        PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "Slate", "SlateCore", "EditorStyle", "GraphEditor", "BlueprintGraph" });

    }
}
