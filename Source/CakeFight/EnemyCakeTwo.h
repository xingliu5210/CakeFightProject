// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCake.h"
#include "EnemyCakeTwo.generated.h"

/**
 * 
 */
UCLASS()
class CAKEFIGHT_API AEnemyCakeTwo : public ABaseCake
{
	GENERATED_BODY()

	public:

		virtual void Tick(float DeltaTime) override;

		void HandleDestruction();
	
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	private:
	
		class APlayerCake* PlayerCake;

		UPROPERTY(EditDefaultsOnly, Category = "Combat")
		float FireRange = 500.f;

		FTimerHandle FireRateTimerHandle;
		float FireRate = 1.f;
		void CheckFireCondition();
		bool InFireRange(); 

	
};
