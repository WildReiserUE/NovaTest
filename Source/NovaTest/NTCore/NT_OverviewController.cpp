
#include "NT_OverviewController.h"

#include "NT_Instance.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "NT_OverviewWidget.h"

ANT_OverviewController::ANT_OverviewController()
{
	PrimaryActorTick.bCanEverTick = true;
	bEnableClickEvents = true;
	bShowMouseCursor= true;
}

void ANT_OverviewController::BeginPlay()
{
	Super::BeginPlay();
	

}

void ANT_OverviewController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANT_OverviewController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(GetCurrentGameInstance() && InPawn)
	{
		if(OverviewWidget)
		{
			if(IsValid(OverviewWidget))
			{
				OvervievRef = CreateWidget(this,OverviewWidget);
				if(!OvervievRef->IsInViewport())
				{
					OvervievRef->AddToViewport(0);
					if(UNT_OverviewWidget* AssignedWidget = Cast<UNT_OverviewWidget>(OvervievRef))
					{
						AssignedWidget->ButtonBack->OnClicked.AddDynamic(this,&ANT_OverviewController::BackToStartMap);
						UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(this,AssignedWidget,EMouseLockMode::DoNotLock,true);
						CreatePreviewActor();
					}
				}
			}
		}
	}
}

void ANT_OverviewController::BackToStartMap()
{
	if(GetCurrentGameInstance())
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(this,CurrentInstance->ZeroLevel,true);
	}
}

void ANT_OverviewController::CreatePreviewActor()
{
	if(CurrentInstance->PlanetarParts.Num() > 0)
	{
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = nullptr;
		SpawnParams.ObjectFlags = RF_Transient;
		SpawnParams.bDeferConstruction = true;

		FTransform SpawnTransform = FTransform(FRotator(90.f,0.f,150.f), FVector(270.f,0.f,220.f), FVector::OneVector);

		//SpawnedActor = GetWorld()->SpawnActor<ANT_CompletePart>(,SpawnTransform, SpawnParams); TODO SPAWN REWORK
		if(SpawnedActor)
		{
			UE_LOG(LogTemp,Log,TEXT("Data Complected-----"));
			SpawnedRotation = SpawnedActor->GetActorRotation();
			SpawnedArmLenght = SpawnedActor->SpringArm->TargetArmLength;
			for(int i=0; i<CurrentInstance->PlanetarParts.Num(); i++)
			{
				SpawnedActor->AddNewMesh(CurrentInstance->GetMeshFromTable(CurrentInstance->PlanetarParts[i]));
			}
			UGameplayStatics::FinishSpawningActor(SpawnedActor,SpawnTransform);
		}
	}
}

