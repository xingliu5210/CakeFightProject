// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCakeOne.h"
#include "PlayerCake.h"
#include "Kismet/GameplayStatics.h"

void AEnemyCakeOne::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the playercake    
    if (InFireRange())
    {
        RotateTop(PlayerCake->GetActorLocation());
    }
    
}

void AEnemyCakeOne::BeginPlay()
{
    Super::BeginPlay();

    PlayerCake = Cast<APlayerCake>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemyCakeOne::CheckFireCondition, FireRate, true);
}

void AEnemyCakeOne::CheckFireCondition()
{
    if (InFireRange() && PlayerCake->bAlive)
    {
        Fire();
    }
    
}

bool AEnemyCakeOne::InFireRange()
{
    if(PlayerCake)
    {
        float Distance = FVector::Dist(GetActorLocation(), PlayerCake->GetActorLocation());
        if (Distance <= FireRange)
        {
            return true;
        }
    }

    return false;
}

void AEnemyCakeOne::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

