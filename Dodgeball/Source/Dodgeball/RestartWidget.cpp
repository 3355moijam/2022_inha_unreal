// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "DodgeBallPlayerController.h"

void URestartWidget::OnRestartClick()
{
	ADodgeBallPlayerController* PlayerController = Cast<ADodgeBallPlayerController>(GetOwningPlayer());
	if (PlayerController == nullptr) return;

	PlayerController->HideRestartWidget();

	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}

void URestartWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (RestartButton == nullptr) return;

	RestartButton->OnClicked.AddDynamic(this, &URestartWidget::OnRestartClick);

}
