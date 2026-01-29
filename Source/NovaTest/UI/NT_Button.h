// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "NT_Button.generated.h"

class UTextBlock;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBUIOnClickedSignature, int, Index);
/**
 * 
 */
UCLASS()
class NOVATEST_API UNT_Button : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
	int Index = 0;
	FBUIOnClickedSignature OnClickedDelegate;

	UFUNCTION()
	void UpdateName(FString Value);
protected:
	UPROPERTY()
	UTextBlock* Text;
	virtual void NativeOnInitialized() override;
	UFUNCTION()
	void OnButtonClicked();
};
