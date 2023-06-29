#pragma once

#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NT_Object_Struct.generated.h"

USTRUCT(BlueprintType)
struct FNT_Object_Struct : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemInfo")
	FName ItemName = "None";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemInfo")
	FString ItemNameUI = "";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemInfo")
	UStaticMesh* ItemPreviewMesh = nullptr;
};

USTRUCT(BlueprintType)
struct FNT_Object_Data
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DetailInfo")
	UStaticMeshComponent* DetailMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DetailInfo")
	bool bIsActive = false;
};

UCLASS()
class  NOVATEST_API UNovaTestStruct : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};
