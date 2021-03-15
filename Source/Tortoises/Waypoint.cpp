// Fill out your copyright notice in the Description page of Project Settings.


#include "Waypoint.h"
#include "TortoiseCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWaypoint::AWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(Root);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWaypoint::OnPlayerEnter);

	static ConstructorHelpers::FObjectFinder<USoundWave> spawnSound(TEXT("/Game/StarterContent/Audio/Collapse02"));

	m_playerEnteredSound = spawnSound.Object;
}

// Called when the game starts or when spawned
void AWaypoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaypoint::OnPlayerEnter(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResul)
{
	ATortoiseCharacter* character = nullptr;
	if (OtherActor != nullptr)
	{
		character = Cast<ATortoiseCharacter>(OtherActor);

		if (character != nullptr)
		{
			if (Effect)
			{
				UGameplayStatics::SpawnEmitterAtLocation(this, Effect, character->GetActorLocation());
			}
			character->Destroy();
			UGameplayStatics::PlaySound2D(this, m_playerEnteredSound);
		}
	}
}

