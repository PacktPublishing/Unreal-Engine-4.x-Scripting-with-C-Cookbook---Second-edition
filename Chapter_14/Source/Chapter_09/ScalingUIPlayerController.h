

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ScalingUIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_09_API AScalingUIPlayerController : public APlayerController
{
    GENERATED_BODY()
    
public:
    virtual void BeginPlay() override;
};
