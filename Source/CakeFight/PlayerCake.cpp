// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCake.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Set default values
APlayerCake::APlayerCake()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

}