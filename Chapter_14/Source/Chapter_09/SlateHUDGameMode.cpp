

#include "SlateHUDGameMode.h"
#include "CustomHUDPlayerController.h"

ASlateHUDGameMode::ASlateHUDGameMode() : Super()
{
    PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}
