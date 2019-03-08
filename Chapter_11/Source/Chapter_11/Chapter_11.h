// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// 11-01 - Core/Logging API - Defining a custom log category
DECLARE_LOG_CATEGORY_EXTERN(LogCh11, Log, All);

// 11 - 02 - Core / Logging API - FMessageLog to write messages to the Message Log
#define LOCTEXT_NAMESPACE "Chapter11Namespace"
#define FTEXT(x) LOCTEXT(x, x) 

extern FName LoggerName;

void CreateLog(FName logName);