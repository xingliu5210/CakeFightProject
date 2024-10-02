// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCake.h"
#include "PlayerCake.generated.h"

/**
 * 
 */
UCLASS()
class CAKEFIGHT_API APlayerCake : public ABaseCake
{
	GENERATED_BODY()

public: 
	// Set default values for this cake's properties
	APlayerCake();

private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;
	
};
