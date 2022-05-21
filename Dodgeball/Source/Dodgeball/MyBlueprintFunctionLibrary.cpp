// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"

bool UMyBlueprintFunctionLibrary::CanSeeActor(
	const UWorld* world, 
	FVector location, 
	const AActor* targetActor, 
	TArray<const AActor*> ignoreActors)
{
	if (targetActor == nullptr) return false;

	// Store the results of the Line Trace
	FHitResult Hit;

	// Where the Line Trace starts and ends
	FVector Start = location;
	FVector End = targetActor->GetActorLocation();

	// The trace channel we want to compare against
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;
	// Ignore the actor that's executing this Line Trace
	QueryParams.AddIgnoredActors(ignoreActors);
	

	// Execute the Line Trace
	world->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// Show the Line Trace inside the game
	DrawDebugLine(world, Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}