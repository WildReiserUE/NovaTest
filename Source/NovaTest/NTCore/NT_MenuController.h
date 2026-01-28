// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NT_Instance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "NT_MenuController.generated.h"

class UNT_MenuWidget;

UCLASS()
class NOVATEST_API ANT_MenuController : public APlayerController
{
  GENERATED_BODY()

public:
  ANT_MenuController();
  UFUNCTION()
  void QuitProgram();
  UFUNCTION()
  void OpenPreview();

protected:
  virtual void BeginPlay() override;
  UPROPERTY()
  UNT_MenuWidget* MenuWidget = nullptr;
  UFUNCTION()
  UNT_Instance* GetCurrentGameInstance() const {return GetGameInstance<UNT_Instance>();};

};