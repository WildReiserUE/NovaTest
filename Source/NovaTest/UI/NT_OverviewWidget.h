// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NT_CompletePart.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "NT_OverviewWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSendInfo, UStaticMeshComponent*, Component);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSingleInfo, UStaticMeshComponent*, Component);

UCLASS()
class NOVATEST_API UNT_OverviewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY()
	UButton* ButtonComplect = nullptr; 
	UPROPERTY()
	UButton* ButtonBack;
	UPROPERTY()
	UScrollBox* PartsList;
	UPROPERTY()
	FOnSendInfo OnSendInfo;
	UPROPERTY()
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
	virtual void NativeOnInitialized() override;
};
