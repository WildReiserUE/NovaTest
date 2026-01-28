// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "NT_MenuWidget.generated.h"


UCLASS()
class NOVATEST_API UNT_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY()
	UButton* ButtonStart;
	UPROPERTY()
	UButton* ButtonExit;

protected:
	virtual void NativeOnInitialized() override;
};
