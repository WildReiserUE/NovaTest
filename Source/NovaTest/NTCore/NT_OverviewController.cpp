
#include "NT_OverviewController.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "NT_Instance.h"
#include "NT_MenuWidget.h"
#include "NT_OverviewWidget.h"
#include "Engine/StaticMeshActor.h"
#include "InputMappingContext.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


ANT_OverviewController::ANT_OverviewController()
{
	PrimaryActorTick.bCanEverTick = true;
	//bEnableClickEvents = true;
	//bEnableMouseOverEvents = true;
	SetShowMouseCursor(true);

	MappingContext = ConstructorHelpers::FObjectFinder<UInputMappingContext>
		(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/NovaTest/Input/IMC_Default'")).Object;
	IA_LeftMB= ConstructorHelpers::FObjectFinder<UInputAction>
		(TEXT("/Script/EnhancedInput.InputAction'/Game/NovaTest/Input/Actions/IA_LeftMB'")).Object;
}

void ANT_OverviewController::BeginPlay()
{
	Super::BeginPlay();
	if(MenuWidget)
	{
		if(MenuWidget->IsInViewport())
		{
			MenuWidget->RemoveFromParent();
		}
	}
	if(!OverviewWidget)
	{
		OverviewWidget = CreateWidget<UNT_OverviewWidget>(this,UNT_OverviewWidget::StaticClass());
		if(!OverviewWidget->IsInViewport())
		{
			OverviewWidget->AddToViewport(0);
			if(!OverviewWidget->ButtonBack->OnClicked.IsBound())
				OverviewWidget->ButtonBack->OnClicked.AddDynamic(this,&ANT_OverviewController::BackToStartMap);
			if(!OverviewWidget->ButtonComplect->OnClicked.IsBound())
				OverviewWidget->ButtonComplect->OnClicked.AddDynamic(this,&ANT_OverviewController::CreatePreviewActor);
			if(!OverviewWidget->OnSendInfo.IsBound())
				OverviewWidget->OnSendInfo.AddDynamic(this,&ANT_OverviewController::GetInfo);
			if(!OverviewWidget->OnSingleInfo.IsBound())
				OverviewWidget->OnSingleInfo.AddDynamic(this,&ANT_OverviewController::SingleInfo);
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(this,OverviewWidget,EMouseLockMode::DoNotLock,true);
		}
	}
}

void ANT_OverviewController::GetInfo(UStaticMeshComponent* MeshComponent)
{
	SetHighlight(MeshComponent);
}

void ANT_OverviewController::SingleInfo(UStaticMeshComponent* Value)
{
	TArray<AActor*> SpawnedArr;
	SpawnedActor->GetAttachedActors(SpawnedArr,true);
	if(SingleActor)
	{
		for (auto Actor : SpawnedArr)
		{
			Actor->SetActorHiddenInGame(false);
			SingleActor = nullptr;
		}
		return;
	}
	for (auto Actor : SpawnedArr)
	{
		Actor->SetActorHiddenInGame(Actor->GetRootComponent() != Value && SpawnedActor && Value);
		if(!Actor->IsHidden())
		{
			SingleActor = Actor;
		}
	}
}

void ANT_OverviewController::SetHighlight(UPrimitiveComponent* Component)
{

	if(!TempComponent && Component)
	{
		TempComponent = Component;
		TempComponent->SetRenderCustomDepth(true);
	}
	else if(TempComponent != Component && Component)
	{
		TempComponent->SetRenderCustomDepth(false);
		TempComponent = Component;
		TempComponent->SetRenderCustomDepth(true);
	}
	else if (TempComponent && !Component)
	{
		TempComponent->SetRenderCustomDepth(false);
		TempComponent = Component;
	}
}

void ANT_OverviewController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if(MappingContext)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			if(IA_LeftMB)
			{
				EnhancedInputComponent->BindAction(IA_LeftMB, ETriggerEvent::Started, this, &ANT_OverviewController::ObjectRotationStart);
				EnhancedInputComponent->BindAction(IA_LeftMB, ETriggerEvent::Triggered, this, &ANT_OverviewController::ObjectRotation);
				EnhancedInputComponent->BindAction(IA_LeftMB, ETriggerEvent::Completed, this, &ANT_OverviewController::ObjectRotationEnd);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error,
				TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system."
					 " If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
		}
	}
}

void ANT_OverviewController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANT_OverviewController::ObjectRotationStart(const FInputActionValue& Value)
{
}

void ANT_OverviewController::ObjectRotation(const FInputActionValue& Value)
{
	if(SingleActor)
	{
		float Xx, Yy;
		GetInputMouseDelta(Xx,Yy);

		SpawnedActor->AddActorWorldRotation(FRotator(
		Value.Get<float>() * Yy * -3.0,
		Value.Get<float>() * Xx * -3.0,
		0));
	}
	else if (SpawnedActor)
	{
		float Xx, Yy;
		GetInputMouseDelta(Xx,Yy);

		SpawnedActor->AddActorWorldRotation(FRotator(
		Value.Get<float>() * Yy * -3.0,
		Value.Get<float>() * Xx * -3.0,
		0));
	}
}

void ANT_OverviewController::ObjectRotationEnd(const FInputActionValue& Value)
{
}

void ANT_OverviewController::BackToStartMap()
{
	if(GetCurrentGameInstance())
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(this,GetCurrentGameInstance()->ZeroLevel,true);
	}
}

void ANT_OverviewController::CreatePreviewActor()
{
	if(GetCurrentGameInstance()->PlanetarParts.Num() > 0 && !SpawnedActor)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = nullptr;
		SpawnParams.ObjectFlags = RF_Transient;
		SpawnParams.bDeferConstruction = true;

		const FTransform SpawnTransform = FTransform(FRotator(0.f,-20.f,-30.f), FVector(240.f,40.f,160.f), FVector::OneVector);

		SpawnedActor = GetWorld()->SpawnActor<ANT_CompletePart>(ANT_CompletePart::StaticClass(),SpawnTransform, SpawnParams);
		if(SpawnedActor)
		{
			SpawnedRotation = SpawnedActor->GetActorRotation();
			SpawnedArmLenght = SpawnedActor->SpringArm->TargetArmLength;
			UGameplayStatics::FinishSpawningActor(SpawnedActor,SpawnTransform);
			for(int i=0; i<GetCurrentGameInstance()->PlanetarParts.Num(); i++)
			{
				FNT_Object_Struct res;
				auto pp = GetCurrentGameInstance()->CollectionTable->FindRow<FNT_Object_Struct>(GetCurrentGameInstance()->PlanetarParts[i],"",true);
				AStaticMeshActor* MyNewActor = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass());
				MyNewActor->SetMobility(EComponentMobility::Stationary);
				UStaticMeshComponent* MeshComponent = MyNewActor->GetStaticMeshComponent();
				if (MeshComponent)
				{
					MeshComponent->SetStaticMesh(pp->ItemPreviewMesh);
				}
				MyNewActor->AttachToActor(SpawnedActor,FAttachmentTransformRules::SnapToTargetIncludingScale);
				if(OverviewWidget)
				{
					OverviewWidget->AddToList(i,pp->ItemNameUI,MeshComponent);
				}
			}
		}
	}
	else if (SpawnedActor)
	{
		TArray<AActor*> AcToDel;
		SpawnedActor->GetAttachedActors(AcToDel,true);
		for (auto Element : AcToDel)
		{
			Element->Destroy();
		}
		SpawnedActor->Destroy();
		SpawnedActor = nullptr;
		SingleActor = nullptr;
		if(OverviewWidget)
		{
			OverviewWidget->ClearList();
		}
	}
}

