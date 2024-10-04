// Fill out your copyright notice in the Description page of Project Settings.


#include "NewCakeFightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCake.h"
#include "EnemyCakeOne.h"
#include "CakeFightPlayerController.h"

void ANewCakeFightGameMode::ActorDied(AActor* DeadActor)
{
    if (DeadActor == PlayerCake)
    {
        PlayerCake->HandleDestruction();
        if (CakeFightPlayerController)
        {
            CakeFightPlayerController->SetPlayerEnabledState(false);
        }
    }
    else if(AEnemyCakeOne* DestroyedCake = Cast<AEnemyCakeOne>(DeadActor))
    {
            DestroyedCake->HandleDestruction();
    }
             
    
}

void ANewCakeFightGameMode::BeginPlay()
{
    Super::BeginPlay();

    HandleGameStart();
}

void ANewCakeFightGameMode::HandleGameStart()
{
    PlayerCake = Cast<APlayerCake>(UGameplayStatics::GetPlayerPawn(this, 0));
    CakeFightPlayerController = Cast<ACakeFightPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    StartGame();

    if(CakeFightPlayerController)
    {
        CakeFightPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerEnableTimeHandle; 
        FTimerDelegate PlayerEnableTimeDelegate = FTimerDelegate::CreateUObject(CakeFightPlayerController, &ACakeFightPlayerController::SetPlayerEnabledState, true);

        GetWorldTimerManager().SetTimer(PlayerEnableTimeHandle,
                                        PlayerEnableTimeDelegate,
                                        StartDelay,
                                        false);
    }
}

