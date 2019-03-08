// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MessageLog.h"
// 10-11 - HTTP API - Web request
#include "Runtime/Online/HTTP/Public/HttpManager.h" 
#include "Runtime/Online/HTTP/Public/HttpModule.h" 
#include "Runtime/Online/HTTP/Public/HttpRetrySystem.h" 
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
using namespace FHttpRetrySystem;

#include "Chapter_11GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_11_API AChapter_11GameModeBase : public AGameModeBase
{
    GENERATED_BODY()
    
    void BeginPlay();

    void TestHttp();

    void HttpRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success);

};

class PlainObject
{
public:
    void httpHandler(FHttpRequestPtr request, FHttpResponsePtr response, bool success)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlainObject: Http req handled"));
    }
};

// Derive from TSharedFromThis to make THREADSAFE
class SharedObject : public TSharedFromThis<SharedObject, ESPMode::ThreadSafe>
{
public:
    void httpHandler(FHttpRequestPtr request, FHttpResponsePtr response, bool success)
    {
        UE_LOG(LogTemp, Warning, TEXT("SharedObject: Http req handled"));
    }
};

inline void httpHandler(FHttpRequestPtr request, FHttpResponsePtr response, bool success)
{
    UE_LOG(LogTemp, Warning, TEXT("static: Http req handled"));
}

