// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCake.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"

// Sets default values
ABaseCake::ABaseCake()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TopMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top Mesh"));
	TopMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TopMesh);

}

// Called every frame
void ABaseCake::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCake::RotateTop(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TopMesh->GetComponentLocation();

	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TopMesh->SetWorldRotation(FMath::RInterpTo(TopMesh->GetComponentRotation(),
							  LookAtRotation,
							  UGameplayStatics::GetWorldDeltaSeconds(this),
							  25.f));
}

// Called to bind functionality to input
void ABaseCake::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCake::Fire()
{
    FVector Location = ProjectileSpawnPoint->GetComponentLocation();
    FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

    AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	Projectile->SetOwner(this);
}

void ABaseCake::HandleDestruction()
{
	if(DeathParticles && DeathSound)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}

	if (DeathCameraShake)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShake);
	}
}
