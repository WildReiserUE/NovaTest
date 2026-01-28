// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NT_MenuGameMode.generated.h"

UCLASS()
class NOVATEST_API ANT_MenuGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ANT_MenuGameMode();

protected:
	virtual void BeginPlay() override;

};
