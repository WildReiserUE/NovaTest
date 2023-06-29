// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_Instance.h"
#include "Engine/DataTable.h"


TArray<FName> UNT_Instance::CollectAllParts()
{
	if(CollectionTable)
	{
		PlanetarParts = CollectionTable->GetRowNames();
		return PlanetarParts;
	}
	return PlanetarParts;
}

void UNT_Instance::Init()
{
	Super::Init();
	CollectAllParts();
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
