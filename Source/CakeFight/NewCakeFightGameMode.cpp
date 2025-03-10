// Fill out your copyright notice in the Description page of Project Settings.


#include "NewCakeFightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCake.h"
#include "EnemyCakeOne.h"
#include "EnemyCakeTwo.h"
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
        GameOver(false);
    }
    else if (AEnemyCakeOne* EnemyCakeOne = Cast<AEnemyCakeOne>(DeadActor))
    {
        // Handle destruction specific to AEnemyCakeOne
        EnemyCakeOne->HandleDestruction();
        TargetCakes--;
        if (TargetCakes == 0)
        {
            GameOver(true);
        }
    }
    else if (AEnemyCakeTwo* EnemyCakeTwo = Cast<AEnemyCakeTwo>(DeadActor))
    {
        // Handle destruction specific to AEnemyCakeTwo
        EnemyCakeTwo->HandleDestruction();
        TargetCakes--;
        if (TargetCakes == 0)
        {
            GameOver(true);
        }
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
    TargetCakes = GetTargetCakeCount();

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

int32 ANewCakeFightGameMode::GetTargetCakeCount()
{
    TArray<AActor*> CakesOne;
    TArray<AActor*> CakesTwo;
    int32 TotalNum = 0;
    UGameplayStatics::GetAllActorsOfClass(this, AEnemyCakeOne::StaticClass(), CakesOne);
    UGameplayStatics::GetAllActorsOfClass(this, AEnemyCakeTwo::StaticClass(), CakesTwo);
    TotalNum = CakesOne.Num() + CakesTwo.Num();
    return TotalNum;
}