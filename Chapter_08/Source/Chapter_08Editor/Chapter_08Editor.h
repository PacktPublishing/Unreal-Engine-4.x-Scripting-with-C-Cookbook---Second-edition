#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "CookbookCommands.h"
#include "Editor/MainFrame/Public/Interfaces/IMainFrameModule.h"
#include "Developer/AssetTools/Public/IAssetTypeActions.h"
#include "MyCustomAssetPinFactory.h" // 08-14

 
class FChapter_08EditorModule: public IModuleInterface 
{ 
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;

    TSharedPtr<FExtender> ToolbarExtender;
    TSharedPtr<const FExtensionBase> Extension;

    // 08-13 - Creating new console commands
    IConsoleCommand* DisplayTestCommand;
    IConsoleCommand* DisplayUserSpecifiedWindow;
    //

    // 08-14 - Creating a new graph pin visualizer for Blueprint
    TSharedPtr<FMyCustomAssetPinFactory> PinFactory;
    //

    void MyButton_Clicked()
    {
        
        TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
            .Title(FText::FromString(TEXT("Cookbook Window")))
            .ClientSize(FVector2D(800, 400))
            .SupportsMaximize(false)
            .SupportsMinimize(false)
            [
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
            .HAlign(HAlign_Center)
            .VAlign(VAlign_Center)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("Hello from Slate")))
            ]
            ];

        IMainFrameModule& MainFrameModule =
            FModuleManager::LoadModuleChecked<IMainFrameModule>
            (TEXT("MainFrame"));

        if (MainFrameModule.GetParentWindow().IsValid())
        {
            FSlateApplication::Get().AddWindowAsNativeChild
            (CookbookWindow, MainFrameModule.GetParentWindow()
                .ToSharedRef());
        }
        else
        {
            FSlateApplication::Get().AddWindow(CookbookWindow);
        }
        
    };

    void AddToolbarExtension(FToolBarBuilder &builder)
    {
        
        FSlateIcon IconBrush =
            FSlateIcon(FEditorStyle::GetStyleSetName(),
                "LevelEditor.ViewOptions",
                "LevelEditor.ViewOptions.Small");  builder.AddToolBarButton(FCookbookCommands::Get()
                    .MyButton, NAME_None, FText::FromString("My Button"),
                    FText::FromString("Click me to display a message"),
                    IconBrush, NAME_None);
        
    };

    void AddMenuExtension(FMenuBuilder &builder)
    {
        FSlateIcon IconBrush =
            FSlateIcon(FEditorStyle::GetStyleSetName(),
                "LevelEditor.ViewOptions",
                "LevelEditor.ViewOptions.Small");

        builder.AddMenuEntry(FCookbookCommands::Get().MyButton);
    };

    void DisplayWindow(FString WindowTitle)
    {
        TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
            .Title(FText::FromString(WindowTitle))
            .ClientSize(FVector2D(800, 400))
            .SupportsMaximize(false)
            .SupportsMinimize(false);

        IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));

        if (MainFrameModule.GetParentWindow().IsValid())
        {
            FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef());
        }
        else
        {
            FSlateApplication::Get().AddWindow(CookbookWindow);
        }

    }
}; 