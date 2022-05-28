// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperSideScroller_Player.h"

#include "PlayerProjectile.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// #include "Animation/AnimInstance.h"

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
	PlayerInputComponent->BindAction("ThrowProjectile", IE_Pressed, this, &ASuperSideScroller_Player::ThrowProjectile);
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


void ASuperSideScroller_Player::ThrowProjectile()
{
	if(ThrowMontage == nullptr) return;

	auto instance = GetMesh()->GetAnimInstance();
	
	if(instance->Montage_IsPlaying(ThrowMontage)) return;

	instance->Montage_Play(ThrowMontage, 2.0f);
}

void ASuperSideScroller_Player::SpawnProjectile()
{
	if(nullptr == PlayerProjectile) return;
	UWorld* World = GetWorld();
	if(nullptr == World) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	FVector SpawnLocation = this->GetMesh()->GetSocketLocation(FName("ProjectileSocket"));
	FRotator Rotation = GetActorForwardVector().Rotation();
	APlayerProjectile* Projectile = World->SpawnActor<APlayerProjectile>(PlayerProjectile, SpawnLocation, Rotation, SpawnParams);
	if(nullptr == Projectile) return;

	Projectile->CollisionComp->MoveIgnoreActors.Add(SpawnParams.Owner);
	// Projectile->CollisionComp->IgnoreActorWhenMoving(SpawnParams.Owner, true);
}
