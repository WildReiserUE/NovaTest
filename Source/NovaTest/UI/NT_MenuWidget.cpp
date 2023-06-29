// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_MenuWidget.h"

void UNT_MenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonStart->OnClicked.Broadcast();
	ButtonExit->OnClicked.Broadcast();
}
