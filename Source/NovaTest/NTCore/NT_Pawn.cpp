// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_Pawn.h"


ANT_Pawn::ANT_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	SetRootComponent(CameraComponent);
}

void ANT_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANT_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
