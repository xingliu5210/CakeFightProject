// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCakeOne.h"
#include "PlayerCake.h"
#include "Kismet/GameplayStatics.h"

void AEnemyCakeOne::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the playercake
    if(PlayerCake)
    {
        float Distance = FVector::Dist(GetActorLocation(), PlayerCake->GetActorLocation());

        // Check to see if the playercake is in range
        if (Distance <= FireRange)
        {
            // If in range, rotate top part toward the playercake
            RotateTop(PlayerCake->GetActorLocation());
        }
        
    }
}

void AEnemyCakeOne::BeginPlay()
{
    Super::BeginPlay();

    PlayerCake = Cast<APlayerCake>(UGameplayStatics::GetPlayerPawn(this, 0));

}

