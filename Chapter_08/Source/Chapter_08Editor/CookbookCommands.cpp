#include "CookbookCommands.h"
#include "Chapter_08Editor.h"
#include "Commands.h"


void FCookbookCommands::RegisterCommands()
{
#define LOCTEXT_NAMESPACE ""
	UI_COMMAND(MyButton, "Cookbook", "Demo Cookbook Toolbar Command", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(MyMenuButton, "Cookbook", "Demo Cookbook Toolbar Command", EUserInterfaceActionType::Button, FInputGesture());
#undef LOCTEXT_NAMESPACE
}

