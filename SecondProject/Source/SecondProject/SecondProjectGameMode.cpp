// Copyright Epic Games, Inc. All Rights Reserved.

#include "SecondProjectGameMode.h"
#include "SecondProjectBall.h"

ASecondProjectGameMode::ASecondProjectGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = ASecondProjectBall::StaticClass();
}
