

#include "ScalingUIPlayerController.h"
#include "SlateBasics.h"

void AScalingUIPlayerController::BeginPlay()
{
    Super::BeginPlay();
    TSharedRef<SVerticalBox> widget = SNew(SVerticalBox)
        + SVerticalBox::Slot()

        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        [
            SNew(SButton)
            .Content()
        [
            SNew(STextBlock)
            .Text(FText::FromString(TEXT("Test button")))
        ]
        ];
    GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), widget, 1);
}
