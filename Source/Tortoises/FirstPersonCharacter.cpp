// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.f);

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AFirstPersonCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AFirstPersonCharacter::OnOverlapEnd);

	CurrentTortoiseSpawner = nullptr;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction("ButtonClick", IE_Pressed, this, &AFirstPersonCharacter::OnAction);

	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AFirstPersonCharacter::OnAction()
{
	if (CurrentTortoiseSpawner)
	{
		CurrentTortoiseSpawner->Spawn();
	}
}

void AFirstPersonCharacter::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(ATortoiseSpawner::StaticClass()))
	{
		CurrentTortoiseSpawner = Cast<ATortoiseSpawner>(OtherActor);
	}
}

void AFirstPersonCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		CurrentTortoiseSpawner = nullptr;
	}
}


