#pragma once

#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NT_Object_Struct.generated.h"

USTRUCT(BlueprintType)
struct FNT_Object_Struct : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly)
	FString ItemNameUI = "";
	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* ItemPreviewMesh = nullptr;
};
