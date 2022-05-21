// Fill out your copyright notice in the Description page of Project Settings.


#include "DodgeBallPlayerController.h"
#include "RestartWidget.h"
#include "HUDWidget.h"

void ADodgeBallPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (BP_HUDWidget == nullptr) return;
	HUDWidget = CreateWidget<UHUDWidget>(this, BP_HUDWidget);
	HUDWidget->AddToViewport();
}
void ADodgeBallPlayerController::ShowRestartWidget()
{
	if (BP_RestartWidget == nullptr) return;
	SetPause(true);
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;

	RestartWidget = CreateWidget<URestartWidget>(this, BP_RestartWidget);
	RestartWidget->AddToViewport();


}

void ADodgeBallPlayerController::HideRestartWidget()
{
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();

	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void ADodgeBallPlayerController::UpdateHealthPercent(float HealthPercent)
{
	if (HUDWidget == nullptr) return;
	HUDWidget->UpdateHealthPercent(HealthPercent);
}

