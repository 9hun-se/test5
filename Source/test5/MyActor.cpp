// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	CurrentPosition = FVector2D(0, 0);
	Move();
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1); 
}

// Move 함수: 10번 이동하며 좌표 출력
void AMyActor::Move()
{
	UE_LOG(LogTemp, Warning, TEXT("Starting Position: (%.0f, %.0f)"), CurrentPosition.X, CurrentPosition.Y);

	// 10번 이동
	for (int32 i = 0; i < 10; ++i)
	{
		int32 XStep = Step();
		int32 YStep = Step();

		CurrentPosition.X += XStep;
		CurrentPosition.Y += YStep;

		// 이동 후 좌표 
		UE_LOG(LogTemp, Warning, TEXT("Step %d: Moved to (%.0f, %.0f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
	}

	UE_LOG(LogTemp, Warning, TEXT("Final Position: (%.0f, %.0f)"), CurrentPosition.X, CurrentPosition.Y);
}


