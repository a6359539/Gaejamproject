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
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter::Lookup);
	
}

void AMyCharacter::Turn(float Value)
{
	if (possessing)//못움직이게 할 상황
	{
	}
	else{
		AddControllerYawInput(Value);
	}
}

void AMyCharacter::Lookup(float Value)
{
	if (possessing)
	{
	}
	else {
		AddControllerPitchInput(Value);
	}
}

void AMyCharacter::MoveForward(float Value)
{
	if (possessing)
	{
	}
	else {
		AddMovementInput(GetActorForwardVector(), Value);
		FB = Value;
	}
}
void AMyCharacter::MoveRight(float Value)
{
	if (possessing)
	{
	}
	else {
		AddMovementInput(GetActorRightVector(), Value);
		LR = Value;
	}
}


float AMyCharacter::RFB()
{
	return FB;
}
float AMyCharacter::RLR() {

	return LR; 

}