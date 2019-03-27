#include "Chapter_08Editor.h" 
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "LevelEditor.h" 
#include "SlateBasics.h" 
#include "MultiBoxExtender.h" 
#include "CookbookCommands.h" 
#include "AssetToolsModule.h"        // 08-12
#include "MyCustomAssetActions.h"    // 08-12
#include "PropertyEditorModule.h"    // 08-15
#include "MyCustomAssetDetailsCustomization.h" // 08-15
#include "MyCustomAssetPinFactory.h" // 08-15

#include "Developer/AssetTools/Public/IAssetTools.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"

IMPLEMENT_GAME_MODULE(FChapter_08EditorModule, Chapter_08Editor)

void FChapter_08EditorModule::StartupModule()
{
    
    FCookbookCommands::Register();
   
    TSharedPtr<FUICommandList> CommandList = MakeShareable(new FUICommandList());
    
    CommandList->MapAction(FCookbookCommands::Get().MyButton, FExecuteAction::CreateRaw(this, &FChapter_08EditorModule::MyButton_Clicked), FCanExecuteAction());
    
    
    ToolbarExtender = MakeShareable(new FExtender());

    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

    // 08-10 - Creating new toolbar buttons
    //Extension = ToolbarExtender->AddToolBarExtension("Compile", EExtensionHook::Before, CommandList, FToolBarExtensionDelegate::CreateRaw(this, &FChapter_08EditorModule::AddToolbarExtension));  
    //LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
    
    
    // 08-11 - Creating new menu entries
    //Extension = ToolbarExtender->AddMenuExtension("LevelEditor", EExtensionHook::Before, CommandList, FMenuExtensionDelegate::CreateRaw(this,&FChapter_08EditorModule::AddMenuExtension)); 
    //LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarExtender);

    // 08-12 - Creating custom context menu entries for Assets
    //IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

    //auto Actions = MakeShareable(new FMyCustomAssetActions);
    //AssetTools.RegisterAssetTypeActions(Actions);
    //CreatedAssetTypeActions.Add(Actions);

    // 08-13 - Creating new console commands
    /*
    DisplayTestCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayTestCommandWindow"), TEXT("test"), FConsoleCommandDelegate::CreateRaw(this, &FChapter_08EditorModule::DisplayWindow, FString(TEXT("Test Command Window"))), ECVF_Default);

    DisplayUserSpecifiedWindow = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayWindow"), TEXT("test"), FConsoleCommandWithArgsDelegate::CreateLambda(
        [&](const TArray< FString >& Args)
    {
        FString WindowTitle;
        for (FString Arg : Args)
        {
            WindowTitle += Arg;
            WindowTitle.AppendChar(' ');
        }
        this->DisplayWindow(WindowTitle);
    }

    ), ECVF_Default);
    */
    // End 08-13

    // 08-14 - Creating a new graph pin visualizer for Blueprint
    //PinFactory = MakeShareable(new FMyCustomAssetPinFactory());
    //FEdGraphUtilities::RegisterVisualPinFactory(PinFactory);
    // End 08-14

    // 08-15 - Inspecting types with custom Details panels
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    PropertyModule.RegisterCustomClassLayout(UMyCustomAsset::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FMyCustomAssetDetailsCustomization::MakeInstance));
    PropertyModule.RegisterCustomPropertyTypeLayout(UMyCustomAsset::StaticClass()->GetFName(), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMyCustomAssetPropertyDetails::MakeInstance));
    //
    
}


void FChapter_08EditorModule::ShutdownModule()
{
    
    ToolbarExtender->RemoveExtension(Extension.ToSharedRef());
    
    Extension.Reset();
    ToolbarExtender.Reset();

    // 08-12
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("Asset Tools").Get(); 

    for (auto Action : CreatedAssetTypeActions)
    {
        AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
    }
    //

    // 08-13 - Creating new console commands
    if(DisplayTestCommand)
    {
        IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
        DisplayTestCommand = nullptr;
    }

    if(DisplayUserSpecifiedWindow)
    {
        IConsoleManager::Get().UnregisterConsoleObject(DisplayUserSpecifiedWindow);
        DisplayUserSpecifiedWindow = nullptr;
    }
    //
    
    // 08-14 - Creating a new graph pin visualizer for Blueprint
    FEdGraphUtilities::UnregisterVisualPinFactory(PinFactory);
    PinFactory.Reset();
    // End 08-14

    // 08-15 - Inspecting types with custom Details panels
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    PropertyModule.UnregisterCustomClassLayout(UMyCustomAsset::StaticClass()->GetFName());
    //
}