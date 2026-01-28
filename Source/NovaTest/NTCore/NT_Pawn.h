// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "NT_Pawn.generated.h"

UCLASS()
class NOVATEST_API ANT_Pawn : public APawn
{
	GENERATED_BODY()

public:
	ANT_Pawn();

protected:
	virtual void BeginPlay() override;
	UPROPERTY()
	UCameraComponent* CameraComponent = nullptr;

public:
	virtual void Tick(float DeltaTime) override;
};
