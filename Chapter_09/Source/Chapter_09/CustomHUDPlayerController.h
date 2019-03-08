

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomHUDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_09_API ACustomHUDPlayerController : public APlayerController
{
    GENERATED_BODY()
    
public:
    virtual void BeginPlay() override;

};
