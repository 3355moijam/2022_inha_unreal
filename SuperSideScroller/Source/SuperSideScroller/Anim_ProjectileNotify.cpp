// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim_ProjectileNotify.h"

#include "SuperSideScroller_Player.h"

void UAnim_ProjectileNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	// Super::Notify(MeshComp, Animation);
	// UE_LOG(LogTemp, Warning, TEXT("Throw Notify"));
	ASuperSideScroller_Player* Player = Cast<ASuperSideScroller_Player>(MeshComp->GetOwner());
	if(nullptr == Player) return;

	Player->SpawnProjectile();
}

