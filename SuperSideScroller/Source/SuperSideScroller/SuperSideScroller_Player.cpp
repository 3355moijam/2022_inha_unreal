// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperSideScroller_Player.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASuperSideScroller_Player::ASuperSideScroller_Player()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void ASuperSideScroller_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ASuperSideScroller_Player::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ASuperSideScroller_Player::StopSprinting);
}

void ASuperSideScroller_Player::Sprint()
{
	if (!bIsSprinting)
	{
		bIsSprinting = true;
		GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	}
}

void ASuperSideScroller_Player::StopSprinting()
{
	if (bIsSprinting)
	{
		bIsSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	}
}
