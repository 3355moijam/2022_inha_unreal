// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/Character.h"
#include "MyThirdPersonChar.generated.h"

UCLASS()
class CHAPTER03_1_API AMyThirdPersonChar : public ACharacter
{
	GENERATED_BODY()

		// spring arm
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = MyTPS_Cam, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	// cam
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = MyTPS_Cam, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	AMyThirdPersonChar();


	UPROPERTY(EditAnyWhere)//, BlueprintReadWrite, Category = MyTPS_Cam, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* sMeshTest;
	UPROPERTY(VisibleAnyWhere)//, BlueprintReadWrite, Category = MyTPS_Cam, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* sMeshTest2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float TestValue = 0.4f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
