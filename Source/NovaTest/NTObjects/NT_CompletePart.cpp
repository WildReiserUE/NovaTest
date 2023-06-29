// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_CompletePart.h"

ANT_CompletePart::ANT_CompletePart()
{
	PrimaryActorTick.bCanEverTick = true;
	Sphere=CreateDefaultSubobject<USphereComponent>(TEXT("SphereRoot"));
	SetRootComponent(Sphere);
	RotationSphere=CreateDefaultSubobject<USphereComponent>(TEXT("SphereRotation"));
	RotationSphere->SetupAttachment(RootComponent);

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

void ANT_CompletePart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ANT_CompletePart::AddNewMesh(UStaticMesh* Mesh)
{
	if(Mesh)
	{
		// UStaticMeshComponent* AddedMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPart")); TODO:SPAWN AND CONSTRUCT ACTOR
		// AddedMesh->SetupAttachment(RootComponent);
		// AddedMesh->SetRelativeRotation(GetActorRotation());
		// AddedMesh->SetCastShadow(false);
		// AddedMesh->SetStaticMesh(Mesh);
		// FNT_Object_Data NewInfo;
		// NewInfo.DetailMesh = AddedMesh;
		// NewInfo.bIsActive = false;
		// InfoArray.Add(NewInfo);
		return true;
	}
	return false;
}

