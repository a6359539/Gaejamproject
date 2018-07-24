// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	possessing = 0;


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
}


void AMyCharacter::MoveForward(float Value)
{
	if (GetActorLocation().X >= 0 && GetActorLocation().X<=1000)
	{
		AddMovementInput(GetActorForwardVector(), Value);
		FB = Value;
	}
	else
	{
		if (GetActorLocation().X < 0) 
		{
			SetActorLocation(FVector(1, GetActorLocation().Y, GetActorLocation().Z));
		}
		else if(GetActorLocation().X > 1000)
		{
			SetActorLocation(FVector(999, GetActorLocation().Y, GetActorLocation().Z));
		}
	}
}
void AMyCharacter::MoveRight(float Value)
{
	if (GetActorLocation().Y >= 0 && GetActorLocation().Y <= 3000)
	{
		AddMovementInput(GetActorRightVector(), Value);
		LR = Value;
	}
	else
	{
		if (GetActorLocation().Y < 0)
		{
			SetActorLocation(FVector(GetActorLocation().X, 1, GetActorLocation().Z));
		}
		else if(GetActorLocation().Y > 3000)
		{
			SetActorLocation(FVector(GetActorLocation().X, 2999, GetActorLocation().Z));
		}
	}

	
}


float AMyCharacter::RFB()
{
	return FB;
}
float AMyCharacter::RLR() {

	return LR; 

}