#include "ScalingUIGameMode.h"
#include "CustomHUDPlayerController.h"

AScalingUIGameMode::AScalingUIGameMode() : AGameModeBase()
{
    PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}