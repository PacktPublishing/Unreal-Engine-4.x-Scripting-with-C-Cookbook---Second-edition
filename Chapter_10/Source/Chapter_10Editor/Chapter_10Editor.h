#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "CookbookCommands.h"
#include "Editor/MainFrame/Public/Interfaces/IMainFrameModule.h"
#include "Developer/AssetTools/Public/IAssetTypeActions.h" // 10-5
#include "MyCustomAssetPinFactory.h" // 10-7
 
class FChapter_10EditorModule: public IModuleInterface 
{ 
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    // 10-5 - Creating custom context menu entries for Assets
    TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;

    TSharedPtr<FExtender> ToolbarExtender;
    TSharedPtr<const FExtensionBase> Extension;

    // 10-6 - Creating new console commands
    IConsoleCommand* DisplayTestCommand;
    IConsoleCommand* DisplayUserSpecifiedWindow;
    // End 10-6

    // 10-7 - Creating a new graph pin visualizer for Blueprint
    TSharedPtr<FMyCustomAssetPinFactory> PinFactory; 

    void MyButton_Clicked()
    {
        // 10-1  - Creating new toolbar buttons
        //TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
        //    .Title(FText::FromString(TEXT("Cookbook Window")))
        //    .ClientSize(FVector2D(800, 400))
        //    .SupportsMaximize(false)
        //    .SupportsMinimize(false);

        // 10-3 - Creating new editor window
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
                "LevelEditor.ViewOptions.Small"); builder.AddToolBarButton(FCookbookCommands::Get()
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

    //10 - 6 - Creating new console commands
    void DisplayWindow(FString WindowTitle)
    {
        TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
            .Title(FText::FromString(WindowTitle))
            .ClientSize(FVector2D(800, 400))
            .SupportsMaximize(false)
            .SupportsMinimize(false);
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
    }
    // End 10-6
}; 