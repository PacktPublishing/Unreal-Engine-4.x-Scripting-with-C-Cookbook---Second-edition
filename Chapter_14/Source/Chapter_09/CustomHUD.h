#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_09_API ACustomHUD : public AHUD
{
    GENERATED_BODY()
    
public:
    virtual void DrawHUD() override;

};
