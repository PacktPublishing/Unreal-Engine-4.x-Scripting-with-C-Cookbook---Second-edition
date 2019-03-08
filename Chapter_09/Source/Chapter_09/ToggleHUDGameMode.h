

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateBasics.h"
#include "ToggleHUDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_09_API AToggleHUDGameMode : public AGameModeBase
{
    GENERATED_BODY()
    
public:
    UPROPERTY()
    FTimerHandle HUDToggleTimer;

    TSharedPtr<SVerticalBox> widget;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
