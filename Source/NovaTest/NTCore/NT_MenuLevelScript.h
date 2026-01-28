// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "NT_MenuLevelScript.generated.h"

UCLASS()
class NOVATEST_API ANT_MenuLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ANT_MenuLevelScript();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
