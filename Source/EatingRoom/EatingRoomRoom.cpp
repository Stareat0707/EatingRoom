// Fill out your copyright notice in the Description page of Project Settings.

#include "EatingRoomRoom.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AEatingRoomRoom::AEatingRoomRoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a StaticMeshComponent
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComponent);

	// Create a PointLightComponent
	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLightComponent->SetupAttachment(RootComponent);
	PointLightComponent->SetRelativeLocation(FVector(0.f, 0.f, 170.f));
	PointLightComponent->SetLightColor(FLinearColor::Green);
	
	// Create a BoxComponent
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetRelativeLocation(FVector(0.f, 0.f, 170.f));
	BoxComponent->SetRelativeScale3D(FVector(6.5f, 6.5f, 4.25f));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AEatingRoomRoom::OnBoxBeginOverlap);
}

// Called when the game starts or when spawned
void AEatingRoomRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEatingRoomRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when box overlapped
void AEatingRoomRoom::OnBoxBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT("Hello!"));
	PointLightComponent->SetLightColor(FLinearColor::Blue);
}
