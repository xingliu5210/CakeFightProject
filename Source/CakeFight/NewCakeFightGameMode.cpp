// Fill out your copyright notice in the Description page of Project Settings.


#include "NewCakeFightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCake.h"
#include "EnemyCakeOne.h"

void ANewCakeFightGameMode::ActorDied(AActor* DeadActor)
{
    if (DeadActor == PlayerCake)
    {
        PlayerCake->HandleDestruction();
        /*
        if (PlayerCake->PlayerCakeController)
        {
            PlayerCake->DisableInput(PlayerCake->PlayerCakeController);
            PlayerCake->PlayerCakeController->bShowMouseCursor = false;
        }
        else if(AEnymeCakeOne* DestroyedCake == Cast<AEnemyCakeOne>(DeadActor))
        {
            DestroyedCake->HandleDestruction();
        }
        */

        
    }
    
}

void ANewCakeFightGameMode::BeginPlay()
{
    Super::BeginPlay();

    PlayerCake = Cast<APlayerCake>(UGameplayStatics::GetPlayerPawn(this, 0));
}