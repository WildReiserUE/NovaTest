// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "NT_CompletePart.generated.h"

UCLASS()
class NOVATEST_API ANT_CompletePart : public AActor
{
	GENERATED_BODY()

public:
	ANT_CompletePart();
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	USphereComponent* RotationSphere;

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void SetHighlightOn(UPrimitiveComponent* Component);
	UFUNCTION()
	void SetHighlightOff(UPrimitiveComponent* Component);

public:
	virtual void Tick(float DeltaTime) override;

};
