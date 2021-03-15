// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Bot_Base_Controller.h"
#include "TortoiseCharacter.h"
#include "Waypoint.h"

AAI_Bot_Base_Controller::AAI_Bot_Base_Controller() : 
	IsMoveEnabled{true}
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAI_Bot_Base_Controller::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_Bot_Base_Controller::Tick(float deltaSecond)
{
	Super::Tick(deltaSecond);

	ATortoiseCharacter* character = Cast<ATortoiseCharacter>(GetPawn());
	if (character->Waypoint != nullptr)
	{
		MoveToActor(character->Waypoint, 5.0f);
	}
}

void AAI_Bot_Base_Controller::ChangeMoveOnTimer()
{
	IsMoveEnabled ^= true;
}