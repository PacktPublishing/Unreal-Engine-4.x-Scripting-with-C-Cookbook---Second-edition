

#include "CustomButtonWidget.h"
#include "Chapter_09.h"

TSharedRef<SWidget> UCustomButtonWidget::RebuildWidget()
{
    MyButton = SNew(SCustomButton)
        .ButtonClicked(BIND_UOBJECT_DELEGATE(FOnClicked, OnButtonClicked));
    return MyButton.ToSharedRef();
}

UCustomButtonWidget::UCustomButtonWidget()
    :Label(TEXT("Default Value"))
{

}

FReply UCustomButtonWidget::OnButtonClicked()
{
    ButtonClicked.Broadcast();
    return FReply::Handled();
}


void UCustomButtonWidget::SynchronizeProperties()
{
    Super::SynchronizeProperties();
    TAttribute<FString> LabelBinding = OPTIONAL_BINDING(FString, Label);
    MyButton->Label = LabelBinding;
}
