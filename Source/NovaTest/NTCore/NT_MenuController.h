// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "NT_MenuController.generated.h"

UCLASS()
class NOVATEST_API ANT_MenuController : public APlayerController
{
  GENERATED_BODY()

public:

  ANT_MenuController();

protected:
  virtual void BeginPlay() override;

public:
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="Settings")
  TSubclassOf<UUserWidget> MenuWidget;

  UPROPERTY()
  UNT_Instance* CurrentInstance = nullptr;

  UFUNCTION()
  UNT_Instance* GetCurrentGameInstance();

  UFUNCTION()
  void QuitProgramm();

  UFUNCTION()
  void OpenPreview();
};