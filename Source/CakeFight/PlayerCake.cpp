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

void APlayerCake::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent); 

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCake::Move);
}

void APlayerCake::Move(float Value)
{
    FVector DeltaLocation = FVector::ZeroVector;
    // X = Value * DeltaTime * Speed
    DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * speed;
    AddActorLocalOffset(DeltaLocation);
}