

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateBasics.h"
#include "ClickEventGameMode.generated.h"

UCLASS()
class CHAPTER_09_API AClickEventGameMode : public AGameModeBase
{
    GENERATED_BODY()
    
private:
    TSharedPtr<SVerticalBox> widget;
    TSharedPtr<STextBlock> ButtonLabel;

public:
    virtual void BeginPlay() override;
    FReply ButtonClicked();
};
