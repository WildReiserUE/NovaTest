// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "NT_Object_Struct.h"
#include "NT_Instance.generated.h"


UCLASS()
class NOVATEST_API UNT_Instance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	UDataTable* CollectionTable = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	TAssetPtr<UWorld> ZeroLevel = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	TAssetPtr<UWorld> OverviewLevel = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Usables")
	TArray<FName> PlanetarParts;

	UFUNCTION(BlueprintCallable)
	TArray<FName> CollectAllParts();

	UFUNCTION()
	virtual void Init() override;

	UFUNCTION()
	UStaticMesh* GetMeshFromTable(FName PartNames);
};
