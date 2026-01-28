// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_MenuLevelScript.h"

#include "GameMapsSettings.h"
#include "NT_MenuGameMode.h"


ANT_MenuLevelScript::ANT_MenuLevelScript()
{
	FGameModeName GameSettings;
	GameSettings.GameMode = ANT_MenuGameMode::StaticClass(); 
}

void ANT_MenuLevelScript::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANT_MenuLevelScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

