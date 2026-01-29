// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "NT_Instance.generated.h"


UCLASS()
class NOVATEST_API UNT_Instance : public UGameInstance
{
	GENERATED_BODY()

	UNT_Instance();

public:
	UPROPERTY()
	UDataTable* Table1 = nullptr;
	UPROPERTY()
	UDataTable* Table2 = nullptr;
	UPROPERTY()
	UDataTable* Table3 = nullptr;
	UPROPERTY()
	UDataTable* Table4 = nullptr;
	TArray<FName> CollectAllParts(UDataTable* Table);
	UFUNCTION()
	TArray<UDataTable*> CollectTables();
	UFUNCTION()
	TArray<UDataTable*> GetAllTables() {return ArrTables;}

protected:
	UPROPERTY()
	TArray<UDataTable*> ArrTables = {};
	UPROPERTY()
	TArray<FName> ArrParts = {};
	UFUNCTION()
	virtual void Init() override;
};
