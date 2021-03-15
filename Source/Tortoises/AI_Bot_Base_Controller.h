// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Bot_Base_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TORTOISES_API AAI_Bot_Base_Controller : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_Bot_Base_Controller();

	virtual void BeginPlay() override;

	virtual void Tick(float deltaSecconds) override;

protected:
	void ChangeMoveOnTimer();

	bool IsMoveEnabled;
	FTimerHandle MemberTimerHandle;
};
