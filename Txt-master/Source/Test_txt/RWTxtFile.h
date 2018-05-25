// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "CoreMinimal.h"
#include "fstream"
#include "iostream"
#include "list"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RWTxtFile.generated.h"

using namespace std;

UCLASS()
class TEST_TXT_API URWTxtFile : public UBlueprintFunctionLibrary
{
	private:

	GENERATED_BODY() public:

	/*	UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadTxt"))
			static bool LoadTxt(FString FileNameA, FString& SaveTextA);
			
		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxt"))
			static bool SaveTxt(FString SaveTextB, FString FileNameB);

		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveArray"))
			static bool SaveArray(TArray<uint8> Array, FString FileNameC);
	
		UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadArray"))
			static bool LoadArray(FString& FileNameD,TArray<uint8> ArrayB);
	*/

		UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LerTexto"))
			static void LerTexto(FString FileNameE, FVector&VetorLegal);
		
		UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "EscreverTexto"))
			static FVector EscreverTexto(FString FileNameD, FVector Lugar);
		
};
