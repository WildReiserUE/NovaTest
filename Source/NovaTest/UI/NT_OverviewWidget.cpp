// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_OverviewWidget.h"

void UNT_OverviewWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonBack->OnClicked.Broadcast();
}

void UNT_OverviewWidget::UpdateOverview(TArray<FName> Parts, ANT_CompletePart* Actor)
{
	UE_LOG(LogTemp,Log,TEXT("AAAAAAAAAAAAAAAA"));
}
