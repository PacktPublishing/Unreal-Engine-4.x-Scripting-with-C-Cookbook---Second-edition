// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_11GameModeBase.h"
#include "Chapter_11.h"
#include "MessageLog.h"
#include "Text.h"
#include "GameplayTagsModule.h"
#include "GameplayTags/Classes/GameplayTagsManager.h"

void AChapter_11GameModeBase::BeginPlay()
{
    // 11-01 - Core/Logging API - Defining a custom log category
    // Traditional Logging
    UE_LOG(LogTemp, Warning, TEXT("Message %d"), 1);

    // Our custom log type
    UE_LOG(LogCh11, Display, TEXT("A display message, log is working" ) ); // shows in gray 
    UE_LOG(LogCh11, Warning, TEXT("A warning message"));
    UE_LOG(LogCh11, Error, TEXT("An error message "));

    // 11-02 - Core/Logging API - FMessageLog to write messages to the Message Log
    CreateLog(LoggerName);

    // Retrieve the Log by using the LoggerName. 
    FMessageLog logger(LoggerName);
    logger.Warning(FTEXT("A warning message from gamemode ctor"));
    logger.Info(FTEXT("Info to log"));
    logger.Warning(FTEXT("Warning text to log"));
    logger.Error(FTEXT("Error text to log"));

    TestHttp();
}

void AChapter_11GameModeBase::TestHttp()
{
    // Create the IHttpRequest object from your FHttpModule singleton interface.
    TSharedRef<IHttpRequest> http = FHttpModule::Get().CreateRequest();

    // To see progress of http requests, attach to the OnRequestProgress() function.
    //    You may or may not want to see this.. this can be used to display your
    //    progressbar for longer http requests.
    http->OnRequestProgress().BindLambda(
        [this](FHttpRequestPtr request, int32 sentBytes, int32 receivedBytes)
        -> void
        {
            int32 contentLen = request->GetResponse()->GetContentLength();
            float percentComplete = 100.f * receivedBytes / contentLen;

            UE_LOG(LogTemp, Warning, TEXT("Progress sent=%d bytes / received=%d/%d bytes [%.0f%%]"), sentBytes, receivedBytes, contentLen, percentComplete);

        });


    // Attach to the OnProcessRequestComplete() function to do something
    // when the HTTP request completes. We demonstrate 7 ways of attaching
    // to the delegate below

    FHttpRequestCompleteDelegate& delegate = http->OnProcessRequestComplete();
    // 1. BindLambda():
    delegate.BindLambda(
        [](FHttpRequestPtr request, FHttpResponsePtr response, bool success) -> void 
    {
        UE_LOG(LogTemp, Warning, TEXT("Http response %d, %s"),
            response->GetResponseCode(), *response->GetContentAsString());
    });

    
    // 2. .BindRaw():
    PlainObject* p = new PlainObject();
    delegate.BindRaw(p, &PlainObject::httpHandler);
    // be sure to delete p later..!
    // But CANNOT delete p until callback completes.

    // 3. .BindSP():
    TSharedRef< PlainObject > sr(new PlainObject());
    delegate.BindSP(sr, &PlainObject::httpHandler);

    // 4. .BindThreadSafeSP():
    TSharedRef< SharedObject, ESPMode::ThreadSafe > tssr(new SharedObject());
    delegate.BindThreadSafeSP(tssr, &SharedObject::httpHandler);

    // 5. .BindStatic():
    delegate.BindStatic(&httpHandler);
    // 6. .BindUFunction(): Can't use for functions that have non-UCLASS, USTRUCT or UENUM type arguments (ie
    // no tsharedrefs.
    //.BindUFunction( this, &AChapter12GameMode::ufunctionHttpHandler );
    // 7. .BindUObject():
    delegate.BindUObject(this, &AChapter_11GameModeBase::HttpRequestComplete);
    

    // 4. Set the web address to open by setting the URL of the HttpRequest.
    http->SetURL(TEXT("http://unrealengine.com")); // Do an HTTP request to any site you'd like.

    http->ProcessRequest();
}

void AChapter_11GameModeBase::HttpRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success)
{
    // print the http response
    UE_LOG(LogTemp, Warning, TEXT("Http response %d, %s"),
        response->GetResponseCode(), *response->GetContentAsString());
}