// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_11.h"
#include "Modules/ModuleManager.h"
#include "MessageLog/Public/MessageLogModule.h"
#include "MessageLog.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Chapter_11, "Chapter_11" );

// 11-01 - Core / Logging API - Defining a custom log category
DEFINE_LOG_CATEGORY(LogCh11);

// 11 - 02 - Core / Logging API - FMessageLog to write messages to the Message Log
FName LoggerName("MessageLogChapter11");

void CreateLog(FName logName)
{
    FMessageLogModule& MessageLogModule = FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");
    FMessageLogInitializationOptions InitOptions;
    InitOptions.bShowPages = true;
    InitOptions.bShowFilters = true;
    FText LogListingName = FTEXT("Chapter 11's Log Listing");
    MessageLogModule.RegisterLogListing(logName, LogListingName, InitOptions);
}