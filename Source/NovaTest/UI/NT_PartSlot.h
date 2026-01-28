// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NT_PartSlot.generated.h"

class UTextBlock;
class UHorizontalBox;
class UButton;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHovered, UStaticMeshComponent*, MeshComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowSingle, UStaticMeshComponent*, MeshComponent);

/**
 * 
 */
UCLASS()
class NOVATEST_API UNT_PartSlot : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UButton* Button = nullptr;
	UPROPERTY()
	UTextBlock* PartBlock = nullptr;
	UPROPERTY()
	FOnHovered OnHovered;
	UPROPERTY()
	FOnShowSingle OnShowSingle;
	UPROPERTY()
	UStaticMeshComponent* Component = nullptr;
	UFUNCTION()
	void UpdatePartName(int Value, FString Name, UStaticMeshComponent* Mesh);
	UFUNCTION()
	void SendInfo();
	UFUNCTION()
	void ClearInfo();
	UFUNCTION()
	void ShowSingle();
protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
};
