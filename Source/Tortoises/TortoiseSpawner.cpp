// Fill out your copyright notice in the Description page of Project Settings.


#include "TortoiseSpawner.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATortoiseSpawner::ATortoiseSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USoundWave> spawnSound(TEXT("/Game/StarterContent/Audio/Collapse01"));

	m_spawnSound = spawnSound.Object;
}

// Called when the game starts or when spawned
void ATortoiseSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATortoiseSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATortoiseSpawner::Spawn()
{
	FVector tortoiseSpawnLocation{ GetActorLocation() };
	tortoiseSpawnLocation.Y += 250;
	tortoiseSpawnLocation.Z += 50;

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;

	if (ToSpawn)
	{
		UGameplayStatics::PlaySound2D(this, m_spawnSound);
		if (Effect)
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, Effect, tortoiseSpawnLocation);
		}
		ATortoiseCharacter* spawnedTortoise = GetWorld()->SpawnActor<ATortoiseCharacter>(ToSpawn, tortoiseSpawnLocation, FRotator(), spawnParams);
		spawnedTortoise->Waypoint = Waypoint;
		spawnedTortoise->SpawnPoint = this;
	}
}

