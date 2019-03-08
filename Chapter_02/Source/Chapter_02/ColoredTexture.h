#pragma once 

#include "ObjectMacros.h"
#include "ColoredTexture.generated.h"
 
USTRUCT(Blueprintable) 
struct CHAPTER_02_API FColoredTexture 
{
	GENERATED_USTRUCT_BODY()

public: 
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category =  HUD ) 
	UTexture* Texture; 

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = HUD ) 
	FLinearColor Color; 
}; 
