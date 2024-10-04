// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "CakeFightPlayerController.generated.h"

UCLASS()
class ACakeFightPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACakeFightPlayerController();

	void SetPlayerEnabledState(bool bPlayerEnabled);
};


