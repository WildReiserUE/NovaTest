// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_MenuController.h"

#include "NT_Instance.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NovaTest/UI/NT_MenuWidget.h"

ANT_MenuController::ANT_MenuController()
{
	bEnableClickEvents = true;
}

void ANT_MenuController::BeginPlay()
{
	Super::BeginPlay();
	if(!MenuWidget)
		MenuWidget = CreateWidget<UNT_MenuWidget>(this, UNT_MenuWidget::StaticClass());
	if(!MenuWidget->IsInViewport())
	{
		MenuWidget->AddToViewport(0);
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(this, MenuWidget);
		if(!MenuWidget->ButtonExit->OnClicked.IsBound())
			MenuWidget->ButtonExit->OnClicked.AddDynamic(this,&ANT_MenuController::QuitProgram);
		if(!MenuWidget->ButtonStart->OnClicked.IsBound())
			MenuWidget->ButtonStart->OnClicked.AddDynamic(this,&ANT_MenuController::OpenPreview);
	}
}

void ANT_MenuController::QuitProgram()
{
	UKismetSystemLibrary::QuitGame(this,this,EQuitPreference::Quit,false);
}

void ANT_MenuController::OpenPreview()
{
	if(GetCurrentGameInstance())
	{
		UGameplayStatics::OpenLevel(this,"L_Overview",true);
	}
}