// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_CompletePart.h"

#include "Engine/StaticMeshActor.h"

ANT_CompletePart::ANT_CompletePart()
{
	PrimaryActorTick.bCanEverTick = true;
	Sphere=CreateDefaultSubobject<USphereComponent>(TEXT("SphereRoot"));
	SetRootComponent(Sphere);
	RotationSphere=CreateDefaultSubobject<USphereComponent>(TEXT("SphereRotation"));
	RotationSphere->SetupAttachment(RootComponent);
	RotationSphere->SetMobility(EComponentMobility::Movable);
	RotationSphere->SetAbsolute(false,true,false);

	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 75.f;
	SpringArm->SetAbsolute(false,true,false);

	CaptureCamera=CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureCamera"));
	CaptureCamera->SetupAttachment(SpringArm);

}

void ANT_CompletePart::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANT_CompletePart::SetHighlightOn(UPrimitiveComponent* Component)
{
	if(!Component) return;
	Component->SetRenderCustomDepth(true);
}

void ANT_CompletePart::SetHighlightOff(UPrimitiveComponent* Component)
{
	if(!Component) return;
	Component->SetRenderCustomDepth(false);
}

void ANT_CompletePart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
