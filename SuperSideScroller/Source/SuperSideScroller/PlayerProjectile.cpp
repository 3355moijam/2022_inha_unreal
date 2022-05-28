// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProjectile.h"

#include "EnemyBase.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
APlayerProjectile::APlayerProjectile()
{
 	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("BlockAll");
	CollisionComp->OnComponentHit.AddDynamic(this, &APlayerProjectile::OnHit);

	RootComponent = CollisionComp;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->InitialSpeed = 800.0f;
	ProjectileMovement->MaxSpeed = 800.0f;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	InitialLifeSpan = 3.0f;
	
}

void APlayerProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Projectile Hit"));

	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
	if(Enemy)
	{
		Enemy->DestroyEnemy();
	}
	ExplodeProjectile();

}

void APlayerProjectile::ExplodeProjectile()
{
	Destroy();
}

//
// // Called when the game starts or when spawned
// void APlayerProjectile::BeginPlay()
// {
// 	Super::BeginPlay();
// 	
// }
//
// // Called every frame
// void APlayerProjectile::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// }

