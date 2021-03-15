// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Bot_BackRunner_Controller.h"
#include "TortoiseCharacter.h"
#include "Waypoint.h"

AAI_Bot_BackRunner_Controller::AAI_Bot_BackRunner_Controller()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAI_Bot_BackRunner_Controller::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AAI_Bot_BackRunner_Controller::ChangeMoveOnTimer, 1.5f, true, 0.0f);
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AAI_Bot_BackRunner_Controller::ChangeMoveOnTimer, 1.5f, true, 1.0f);
}

void AAI_Bot_BackRunner_Controller::Tick(float deltaSecond)
{
	Super::Tick(deltaSecond);

	ATortoiseCharacter* character = Cast<ATortoiseCharacter>(GetPawn());
	if (character->Waypoint != nullptr && IsMoveEnabled)
	{
		MoveToActor(character->Waypoint, 5.0f);
	}
	else
	{
		MoveToActor(character->SpawnPoint, 5.0f);
	}
}