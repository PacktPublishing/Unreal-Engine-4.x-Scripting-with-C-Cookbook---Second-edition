

#include "ToggleHUDGameMode.h"


void AToggleHUDGameMode::BeginPlay()
{
    Super::BeginPlay();
    widget = SNew(SVerticalBox)
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

    auto player = GetWorld()->GetFirstLocalPlayerFromController();

    GEngine->GameViewport->AddViewportWidgetForPlayer(player, widget.ToSharedRef(), 1);

    auto lambda = FTimerDelegate::CreateLambda
    ([this]
    {
        if (this->widget->GetVisibility().IsVisible())
        {
            this->widget->SetVisibility(EVisibility::Hidden);

        }
        else
        {
            this->widget->SetVisibility(EVisibility::Visible);
        }
    });

    GetWorld()->GetTimerManager().SetTimer(HUDToggleTimer, lambda, 5, true);
}

void AToggleHUDGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    GetWorld()->GetTimerManager().ClearTimer(HUDToggleTimer);
}
