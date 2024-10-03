// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCake.h"
#include "EnemyCakeOne.generated.h"

/**
 * 
 */
UCLASS()
class CAKEFIGHT_API AEnemyCakeOne : public ABaseCake
{
	GENERATED_BODY()

	public:

		virtual void Tick(float DeltaTime) override;
	
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	private:
	
		class APlayerCake* PlayerCake;

		UPROPERTY(EditDefaultsOnly, Category = "Combat")
		float FireRange = 300.f;

		FTimerHandle FireRateTimerHandle;
		float FireRate = 2.f;
		void CheckFireCondition();
		bool InFireRange(); 

	
};
