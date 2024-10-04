// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NewCakeFightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CAKEFIGHT_API ANewCakeFightGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public: 

		void ActorDied(AActor* DeadActor);
	
	protected:
		
		virtual void BeginPlay() override;

		UFUNCTION(BlueprintImplementableEvent)
		void StartGame();

		UFUNCTION(BlueprintImplementableEvent)
		void GameOver(bool bWonGame);
	
	private:

		class APlayerCake* PlayerCake;
		class ACakeFightPlayerController* CakeFightPlayerController;

		float StartDelay = 4.f;
		void HandleGameStart();

		int32 TargetCakes = 0;
		int32 GetTargetCakeCount();
	
};
