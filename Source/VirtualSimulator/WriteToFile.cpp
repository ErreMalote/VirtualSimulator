// Fill out your copyright notice in the Description page of Project Settings.


#include "VirtualSimulator.h"
#include "WriteToFile.h"

WriteToFile::WriteToFile()
{
}

WriteToFile::~WriteToFile()
{
}

UWriteToFile::UWriteToFile(const class FObjectInitializer& PCIP)
	:Super(PCIP)
{

}

bool UWriteToFile::FileIO__SaveStringTextToFile(FString SaveDirectory, FString fileName, FString SaveText, bool AllowOverWriting)
{
	FString path;
	path = FPaths::GameDir();
	path += "/my_data";

	if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*path))
	{
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*path);
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*path))
		{
			return false;
		}
	}

	path += "/";
	path += fileName;

	if (!AllowOverWriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
		{
			return false;
		}
	}

	return FFileHelper::SaveStringToFile(SaveText, *path);
}