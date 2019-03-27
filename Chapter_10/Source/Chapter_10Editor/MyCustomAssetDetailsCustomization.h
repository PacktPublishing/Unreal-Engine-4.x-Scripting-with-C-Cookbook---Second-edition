#pragma once

#include "MyCustomAsset.h" 
#include "DetailLayoutBuilder.h" 
#include "IDetailCustomization.h" 
#include "IPropertyTypeCustomization.h"

class FMyCustomAssetDetailsCustomization : public IDetailCustomization
{

public:
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

    void ColorPicked(FLinearColor SelectedColor);

    static TSharedRef<IDetailCustomization> MakeInstance()
    {
        return MakeShareable(new FMyCustomAssetDetailsCustomization);
    }

    TWeakObjectPtr<class UMyCustomAsset> MyAsset;
};

class FMyCustomAssetPropertyDetails : public IPropertyTypeCustomization
{
public:
    void ColorPicked(FLinearColor SelectedColor);

    static TSharedRef<IPropertyTypeCustomization> MakeInstance()
    {
        return MakeShareable(new FMyCustomAssetPropertyDetails);
    }

    UMyCustomAsset* MyAsset;
    virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

    virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

};