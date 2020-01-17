// Copyright Perry Winch 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IMPERIALPLUNDER_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	float Reach = 100.f;
	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	UInputComponent *InputComponent = nullptr;
	void Grab();
	void Release();
	void FindPhysicsHandleComponent();
	void SetupInputComponent();

	//Return hit for first physics bodu in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Return current start of reach line
	FVector GetReachLineStart();

	// Return current end of reach line
	FVector GetReachLineEnd();
};
