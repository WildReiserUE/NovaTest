// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "NT_OverviewWidget.generated.h"

class UNT_Button;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSendInfo, UStaticMeshComponent*, Component);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSingleInfo, UStaticMeshComponent*, Component);

UCLASS()
class NOVATEST_API UNT_OverviewWidget : public UUserWidget
{
	GENERATED_BODY()

public: 
	UPROPERTY()
	UButton* ButtonBack;
	UPROPERTY()
	TArray<UNT_Button*> ArrButtons = {};
	FOnSendInfo OnSendInfo;
	FOnSingleInfo OnSingleInfo;
	UFUNCTION()
	void AddToList(int Index, FString Name,UStaticMeshComponent* Component);
	UFUNCTION()
	void Hovered(UStaticMeshComponent* Component);
	UFUNCTION()
	void Single(UStaticMeshComponent* Component);
	UFUNCTION()
	void ClearList();

protected:
	UPROPERTY()
	UNT_Button* Button = nullptr;
	UPROPERTY()
	UScrollBox* PartsList;
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
};
