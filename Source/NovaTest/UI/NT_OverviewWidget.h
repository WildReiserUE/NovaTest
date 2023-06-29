// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NT_CompletePart.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "NT_OverviewWidget.generated.h"

UCLASS()
class NOVATEST_API UNT_OverviewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void UpdateOverview(TArray<FName> Parts, ANT_CompletePart* Actor);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonBack;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UScrollBox* PartsList;
};
