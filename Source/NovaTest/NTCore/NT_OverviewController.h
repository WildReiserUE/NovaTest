// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NT_CompletePart.h"
#include "NT_MenuController.h"
#include "NT_OverviewController.generated.h"

struct FInputActionValue;
class UNT_OverviewWidget;
class UInputMappingContext;
class UInputAction;

UCLASS()
class NOVATEST_API ANT_OverviewController : public ANT_MenuController
{
	GENERATED_BODY()

public:
	ANT_OverviewController();

	UPROPERTY()
	UNT_OverviewWidget* OverviewWidget = nullptr;
	UPROPERTY()
	ANT_CompletePart* SpawnedActor = nullptr;
	UPROPERTY()
	FRotator SpawnedRotation = FRotator(0);
	UPROPERTY()
	float SpawnedArmLenght = 0.f;

	UFUNCTION()
	void BackToStartMap();
	UFUNCTION()
	void CreatePreviewActor(int Value);

protected:
	UPROPERTY()
	UPrimitiveComponent* TempComponent = nullptr;
	UPROPERTY()
	AActor* SingleActor = nullptr;
	/** MappingContext */
	UPROPERTY()
	UInputMappingContext* MappingContext = nullptr;
	UPROPERTY()
	UInputAction* IA_LeftMB = nullptr;

	virtual void BeginPlay() override;
	UFUNCTION()
	void GetInfo(UStaticMeshComponent* Value);
	UFUNCTION()
	void SingleInfo(UStaticMeshComponent* Value);
	UFUNCTION()
	void SetHighlight(UPrimitiveComponent* Component);
	UFUNCTION()
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

	void ObjectRotationStart(const FInputActionValue& Value);
	void ObjectRotation(const FInputActionValue& Value);
	void ObjectRotationEnd(const FInputActionValue& Value);

};
