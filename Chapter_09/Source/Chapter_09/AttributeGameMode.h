

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SlateBasics.h"
#include "AttributeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_09_API AAttributeGameMode : public AGameModeBase
{
    GENERATED_BODY()

    TSharedPtr<SVerticalBox> Widget;
    FText GetButtonLabel() const;

public:
    virtual void BeginPlay() override;
    
};
