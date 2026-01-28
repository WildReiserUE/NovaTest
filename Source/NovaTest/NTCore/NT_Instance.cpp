// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_Instance.h"

#include "NT_Object_Struct.h"
#include "Engine/DataTable.h"
#include "Kismet/KismetSystemLibrary.h"


TArray<FName> UNT_Instance::CollectAllParts()
{
	if(CollectionTable)
	{
		UE_LOG(LogTemp,Warning,TEXT("Collect Parts"));
		PlanetarParts = CollectionTable->GetRowNames();
	}
	UE_LOG(LogTemp,Warning,TEXT("Parts COUNT = %i"), PlanetarParts.Num());
	return PlanetarParts;
}

void UNT_Instance::Init()
{
	Super::Init();
	CollectAllParts();
	UKismetSystemLibrary::ExecuteConsoleCommand(this,"t.MaxFPS 60");
}

UStaticMesh* UNT_Instance::GetMeshFromTable(FName PartNames)
{
	if(PartNames != FName("None"))
	{
		FNT_Object_Struct* MeshPreset = CollectionTable->FindRow<FNT_Object_Struct>(PartNames, "",true);
		return MeshPreset->ItemPreviewMesh;
	}
	return nullptr;
}
