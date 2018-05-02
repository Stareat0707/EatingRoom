// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EatingRoomRoom.generated.h"

UCLASS()
class EATINGROOM_API AEatingRoomRoom : public AActor
{
	GENERATED_BODY()

	/** Static mesh component */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class UStaticMeshComponent* StaticMeshComponent;

	/** Point light component */
	UPROPERTY(VisibleDefaultsOnly, Category = Light)
	class UPointLightComponent* PointLightComponent;

	/** Box collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
	class UBoxComponent* BoxComponent;
	
public:	
	// Sets default values for this actor's properties
	AEatingRoomRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when box overlapped
	UFUNCTION()
	void OnBoxBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
