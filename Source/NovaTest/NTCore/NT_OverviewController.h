// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NT_CompletePart.h"
#include "NT_MenuController.h"
#include "NT_OverviewController.generated.h"

UCLASS()
class NOVATEST_API ANT_OverviewController : public ANT_MenuController
{
	GENERATED_BODY()

public:
	ANT_OverviewController();

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	TSubclassOf<UUserWidget> OverviewWidget;

	UUserWidget* OvervievRef = nullptr;

	UPROPERTY()
	ANT_CompletePart* SpawnedActor = nullptr;

	UPROPERTY()
	FRotator SpawnedRotation = FRotator(0);

	UPROPERTY()
	float SpawnedArmLenght = 0.f;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void BackToStartMap();

	UFUNCTION()
	void CreatePreviewActor();

};
