// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankPawn.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATankPawn>(GetPawn());

	if (PlayerTank)
	{
		// TODO move to player

		// aim at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// fire every frame
		ControlledTank->Fire(); //TODO limit fire rate
	}
}



