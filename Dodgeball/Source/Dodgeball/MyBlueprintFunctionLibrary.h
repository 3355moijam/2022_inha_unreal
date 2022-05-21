// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DODGEBALL_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	static bool CanSeeActor(
		const UWorld* world, 
		FVector location, 
		const AActor* targetActor, 
		TArray<const AActor*> ignoreActors = TArray<const AActor*>());
};
