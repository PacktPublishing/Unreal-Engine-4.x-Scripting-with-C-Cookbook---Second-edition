#include "Chapter_10Editor.h" 
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "LevelEditor.h" 
#include "SlateBasics.h" 
#include "MultiBoxExtender.h" 
#include "CookbookCommands.h" 
#include "Developer/AssetTools/Public/IAssetTools.h"        // 10-6
#include "Developer/AssetTools/Public/AssetToolsModule.h"   // 10-6
#include "MyCustomAssetActions.h"                           // 10-6

#include "PropertyEditorModule.h"                           // 10-8
#include "MyCustomAssetDetailsCustomization.h"              // 10-8
#include "MyCustomAssetPinFactory.h"                        // 10-8


IMPLEMENT_GAME_MODULE(FChapter_10EditorModule, Chapter_10Editor)

void FChapter_10EditorModule::StartupModule()
{
    
    FCookbookCommands::Register();
   
    TSharedPtr<FUICommandList> CommandList = MakeShareable(new FUICommandList());
    
    CommandList->MapAction(FCookbookCommands::Get().MyButton, FExecuteAction::CreateRaw(this, &FChapter_10EditorModule::MyButton_Clicked), FCanExecuteAction());
    
    
    ToolbarExtender = MakeShareable(new FExtender());

    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>( "LevelEditor" );

    // 10-1 - Creating new toolbar buttons
    //Extension = ToolbarExtender->AddToolBarExtension("Compile", EExtensionHook::Before, CommandList, FToolBarExtensionDelegate::CreateRaw(this, &FChapter_10EditorModule::AddToolbarExtension)); 
    
    // 10-2 - Creating new menu entries
    //Extension = ToolbarExtender->AddMenuExtension("LevelEditor", EExtensionHook::Before, CommandList, FMenuExtensionDelegate::CreateRaw(this, &FChapter_10EditorModule::AddMenuExtension));

    //LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarExtender);
    //LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);

    // 10-5 - Creating custom context menu entries for Assets
    //IAssetTools& AssetTools =
    //    FModuleManager::LoadModuleChecked<FAssetToolsModule>
    //    ("AssetTools").Get();

    //auto Actions = MakeShareable(new FMyCustomAssetActions);
    //AssetTools.RegisterAssetTypeActions(Actions);
    //CreatedAssetTypeActions.Add(Actions);
    // End 10-5

    // 10-6 - Creating new console commands
    //DisplayTestCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayTestCommandWindow"), TEXT("test"), FConsoleCommandDelegate::CreateRaw(this, &FChapter_10EditorModule::DisplayWindow, FString(TEXT("Test Command Window"))), ECVF_Default);

    //DisplayUserSpecifiedWindow = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayWindow"), TEXT("test"), FConsoleCommandWithArgsDelegate::CreateLambda(
    //    [&](const TArray< FString >& Args)
    //{
    //    FString WindowTitle;
    //    for (FString Arg : Args)
    //    {
    //        WindowTitle += Arg;
    //        WindowTitle.AppendChar(' ');
    //    }
    //    this->DisplayWindow(WindowTitle);
    //}

    //), ECVF_Default);
    // End 10-6

    // 10-7 - Creating a new graph pin visualizer for Blueprint
    //PinFactory = MakeShareable(new FMyCustomAssetPinFactory());
    //FEdGraphUtilities::RegisterVisualPinFactory(PinFactory);
    //  End 10-7

    // 10-8 - Inspecting types with custom Details panels
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    PropertyModule.RegisterCustomClassLayout(UMyCustomAsset::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FMyCustomAssetDetailsCustomization::MakeInstance));
    PropertyModule.RegisterCustomPropertyTypeLayout(UMyCustomAsset::StaticClass()->GetFName(), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMyCustomAssetPropertyDetails::MakeInstance));
    // End 10-8
    
        
}

void FChapter_10EditorModule::ShutdownModule()
{
    
    ToolbarExtender->RemoveExtension(Extension.ToSharedRef());
    
    Extension.Reset();
    ToolbarExtender.Reset();
    
    // 10-5 - Creating custom context menu entries for Assets
    //IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("Asset Tools").Get();

    //for (auto Action : CreatedAssetTypeActions)
    //{
    //    AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
    //}
    // End 10-5

    // 10-6 - Creating new console commands
    //if (DisplayTestCommand)
    //{
    //    IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
    //    DisplayTestCommand = nullptr;
    //}

    //if (DisplayUserSpecifiedWindow)
    //{
    //    IConsoleManager::Get().UnregisterConsoleObject(DisplayUserSpecifiedWindow);
    //    DisplayUserSpecifiedWindow = nullptr;
    //}
    // End 10-6

    // 10-7 - Creating a new graph pin visualizer for Blueprint
    //FEdGraphUtilities::UnregisterVisualPinFactory(PinFactory); PinFactory.Reset();
    //  End 10-7

    // 10-8 - Inspecting types with custom Details panels
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    PropertyModule.UnregisterCustomClassLayout(UMyCustomAsset::StaticClass()->GetFName());
    // End 10-8

}