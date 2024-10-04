// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCake.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Set default values
APlayerCake::APlayerCake()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void APlayerCake::BeginPlay()
{
	Super::BeginPlay();
    
    PlayerCakeController = Cast<APlayerController>(GetController());
}

// Call every frame
void APlayerCake::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (PlayerCakeController)
    {
        FHitResult HitResult;
        PlayerCakeController->GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility,
            false,
            HitResult
        );

        RotateTop(HitResult.ImpactPoint);
    }
    
}

void APlayerCake::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent); 

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCake::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCake::Turn);

    PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerCake::Fire);
}

void APlayerCake::Move(float Value)
{
    FVector DeltaLocation = FVector::ZeroVector;
    // X = Value * DeltaTime * Speed
    DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
    AddActorLocalOffset(DeltaLocation, true);
}

void APlayerCake::Turn(float Value)
{
    FRotator DeltaRotation = FRotator::ZeroRotator;
    // Yaw = Value * DeltaTime * TurnRate
    DeltaRotation.Yaw = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;
    AddActorLocalRotation(DeltaRotation, true);
}

void APlayerCake::HandleDestruction()
{
    Super::HandleDestruction();
    SetActorHiddenInGame(true);
    SetActorTickEnabled(false);
}