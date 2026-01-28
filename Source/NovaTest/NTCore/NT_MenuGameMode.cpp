// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_MenuGameMode.h"

#include "NT_MenuController.h"
#include "NT_Pawn.h"


ANT_MenuGameMode::ANT_MenuGameMode()
{
	PlayerControllerClass = ANT_MenuController::StaticClass();
	DefaultPawnClass = ANT_Pawn::StaticClass();
}

void ANT_MenuGameMode::BeginPlay()
{
	Super::BeginPlay();

}

