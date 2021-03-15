// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Bot_Base_Controller.h"
#include "AI_Bot_BackRunner_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TORTOISES_API AAI_Bot_BackRunner_Controller : public AAI_Bot_Base_Controller
{
	GENERATED_BODY()
	
public:
	AAI_Bot_BackRunner_Controller();

	virtual void BeginPlay() override;

	virtual void Tick(float deltaSecconds) override;
};
