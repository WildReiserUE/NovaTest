// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NT_Object_Struct.h"
#include "Components/SphereComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "NT_CompletePart.generated.h"

UCLASS()
class NOVATEST_API ANT_CompletePart : public AActor
{
	GENERATED_BODY()

public:
	ANT_CompletePart();
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	USphereComponent* Sphere;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	USphereComponent* RotationSphere;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	USceneCaptureComponent2D* CaptureCamera;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Settings")
	TArray<FNT_Object_Data> InfoArray;

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void SetHighlightOn(UPrimitiveComponent* Component);
	UFUNCTION()
	void SetHighlightOff(UPrimitiveComponent* Component);

public:
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(BlueprintCallable)
	//bool AddNewMesh(UStaticMesh* Mesh);

};
