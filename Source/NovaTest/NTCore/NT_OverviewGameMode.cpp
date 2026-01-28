// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_OverviewGameMode.h"

#include "NT_OverviewController.h"
#include "NT_Pawn.h"

ANT_OverviewGameMode::ANT_OverviewGameMode()
{
	DefaultPawnClass = ANT_Pawn::StaticClass();
	PlayerControllerClass = ANT_OverviewController::StaticClass();
}
