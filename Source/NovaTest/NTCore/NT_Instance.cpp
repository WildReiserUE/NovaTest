// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_Instance.h"

#include "Engine/DataTable.h"
#include "Kismet/KismetSystemLibrary.h"


UNT_Instance::UNT_Instance()
{
	Table1 = ConstructorHelpers::FObjectFinder<UDataTable>
		(TEXT("Datatable'/Game/NovaTest/Data/Table1.Table1'")).Object;
	Table2 = ConstructorHelpers::FObjectFinder<UDataTable>
		(TEXT("Datatable'/Game/NovaTest/Data/Table2.Table2'")).Object;
	Table3 = ConstructorHelpers::FObjectFinder<UDataTable>
		(TEXT("Datatable'/Game/NovaTest/Data/Table3.Table3'")).Object;
	Table4 = ConstructorHelpers::FObjectFinder<UDataTable>
		(TEXT("Datatable'/Game/NovaTest/Data/Table4.Table4'")).Object;
}

TArray<FName> UNT_Instance::CollectAllParts(UDataTable* Table)
{
	ArrParts = Table->GetRowNames();
	UE_LOG(LogTemp,Warning,TEXT("Parts COUNT = %i"), ArrParts.Num());
	return ArrParts;
}

TArray<UDataTable*> UNT_Instance::CollectTables()
{
	if(Table1)
	{
		ArrTables.Add(Table1);
	}
	if(Table2)
	{
		ArrTables.Add(Table2);
	}
	if(Table3)
	{
		ArrTables.Add(Table3);
	}
	if(Table4)
	{
		ArrTables.Add(Table4);
	}
	return ArrTables;
}

void UNT_Instance::Init()
{
	Super::Init();
	CollectTables();
	UKismetSystemLibrary::ExecuteConsoleCommand(this,"t.MaxFPS 60");
}
