// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Test_txtGameMode.h"
#include "Test_txtCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATest_txtGameMode::ATest_txtGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
