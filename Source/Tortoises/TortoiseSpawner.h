// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TortoiseCharacter.h"
#include "GameFramework/Actor.h"
#include "TortoiseSpawner.generated.h"

UCLASS()
class TORTOISES_API ATortoiseSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATortoiseSpawner();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATortoiseCharacter> ToSpawn;

	UPROPERTY(EditAnywhere)
		class AWaypoint* Waypoint;

	UPROPERTY(EditAnywhere)
		UParticleSystem* Effect;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Spawn();

private:
	USoundWave* m_spawnSound;
};
