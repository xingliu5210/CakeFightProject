// Copyright Epic Games, Inc. All Rights Reserved.

#include "CakeFightPlayerController.h"

ACakeFightPlayerController::ACakeFightPlayerController()
{

}

void ACakeFightPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;
}