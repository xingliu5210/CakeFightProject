// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCakeTwo.h"
#include "PlayerCake.h"
#include "Kismet/GameplayStatics.h"

void AEnemyCakeTwo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the playercake    
    if (InFireRange())
    {
        RotateTop(PlayerCake->GetActorLocation());
    }
    
}

void AEnemyCakeTwo::BeginPlay()
{
    Super::BeginPlay();

    PlayerCake = Cast<APlayerCake>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemyCakeTwo::CheckFireCondition, FireRate, true);
}

void AEnemyCakeTwo::CheckFireCondition()
{
    if (InFireRange())
    {
        Fire();
    }
    
}

bool AEnemyCakeTwo::InFireRange()
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

void AEnemyCakeTwo::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}