// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_MenuController.h"

#include "NT_Instance.h"
#include "Blueprint/UserWidget.h"
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
	DisableInput(this);
	if(MenuWidget)
	{
		if(IsValid(MenuWidget))
		{
			const auto CreatedWidget = CreateWidget(this,MenuWidget);
			if(!CreatedWidget->IsInViewport())
			{
				CreatedWidget->AddToViewport(0);
				if(UNT_MenuWidget* AssignedWidget = Cast<UNT_MenuWidget>(CreatedWidget))
				{
					AssignedWidget->ButtonExit->OnClicked.AddDynamic(this,&ANT_MenuController::QuitProgramm);
					AssignedWidget->ButtonStart->OnClicked.AddDynamic(this,&ANT_MenuController::OpenPreview);
				}
			}
		}
		
	}
}

UNT_Instance* ANT_MenuController::GetCurrentGameInstance()
{
	CurrentInstance = GetGameInstance<UNT_Instance>();
	return CurrentInstance ? CurrentInstance : nullptr;
}

void ANT_MenuController::QuitProgramm()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),this,EQuitPreference::Quit,true);
}

void ANT_MenuController::OpenPreview()
{
	if(GetCurrentGameInstance())
	{
		UnPossess();
		UGameplayStatics::OpenLevelBySoftObjectPtr(this,CurrentInstance->OverviewLevel,true);
	}
}
//UE_LOG(LogTemp,Log,TEXT("CREATE WIDGET"))