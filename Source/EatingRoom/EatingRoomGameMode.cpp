// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "EatingRoomGameMode.h"
#include "EatingRoomHUD.h"
#include "EatingRoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEatingRoomGameMode::AEatingRoomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Character/PlayerCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AEatingRoomHUD::StaticClass();
}
