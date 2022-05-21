// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DodgeBallPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DODGEBALL_API ADodgeBallPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartWidget> BP_RestartWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UHUDWidget> BP_HUDWidget;

public:
	void ShowRestartWidget();
	void HideRestartWidget();

	void UpdateHealthPercent(float HealthPercent);
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class URestartWidget* RestartWidget;

	UPROPERTY()
	class UHUDWidget* HUDWidget;
	
};
