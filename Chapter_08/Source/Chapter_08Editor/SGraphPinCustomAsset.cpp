#include "SGraphPinCustomAsset.h"
#include "Chapter_08Editor.h"
#include "SColorPicker.h"
#include "MyCustomAsset.h"

void SGraphPinCustomAsset::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InPin);
}

TSharedRef<SWidget> SGraphPinCustomAsset::GetDefaultValueWidget()
{
	return SNew(SColorPicker)
		.OnColorCommitted(this, &SGraphPinCustomAsset::ColorPicked);

}

void SGraphPinCustomAsset::ColorPicked(FLinearColor SelectedColor)
{
	UMyCustomAsset* NewValue = NewObject<UMyCustomAsset>();
	NewValue->ColorName = SelectedColor.ToFColor(false).ToHex();
	GraphPinObj->GetSchema()->TrySetDefaultObject(*GraphPinObj, NewValue);
}