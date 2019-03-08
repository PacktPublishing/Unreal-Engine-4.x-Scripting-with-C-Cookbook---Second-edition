

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "CustomButton.h"
#include "SlateDelegates.h"
#include "CustomButtonWidget.generated.h"

DECLARE_DYNAMIC_DELEGATE_RetVal(FString, FGetString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonClicked);
UCLASS()
class CHAPTER_09_API UCustomButtonWidget : public UWidget
{
    GENERATED_BODY()
    
protected:
    TSharedPtr<SCustomButton> MyButton;

    virtual TSharedRef<SWidget> RebuildWidget() override;

public:
    UCustomButtonWidget();
    //multicast
    UPROPERTY(BlueprintAssignable)
    FButtonClicked ButtonClicked;

    FReply OnButtonClicked();

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        FString Label;

    //MUST be of the form varnameDelegate
    UPROPERTY()
        FGetString LabelDelegate;

    virtual void SynchronizeProperties() override;
};
