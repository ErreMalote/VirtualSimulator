// Fill out your copyright notice in the Description page of Project Settings.

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VirtualSimulator.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Paths.h"
#include "WriteToFile.generated.h"

/**
 * 
 */
class VIRTUALSIMULATOR_API WriteToFile
{
public:
	WriteToFile();
	~WriteToFile();
};

/**
*
*/
UCLASS()
class UWriteToFile : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", FriendlyName = "File-IO"), Category = "WriteToFile")
		static bool FileIO__SaveStringTextToFile(FString SaveDirectory, FString fileName, FString SaveText, bool AllowOverWriting);

};