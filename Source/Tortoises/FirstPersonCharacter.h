// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TortoiseSpawner.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class TORTOISES_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnAction();

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* TriggerCapsule;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	ATortoiseSpawner* CurrentTortoiseSpawner;
};
