// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterVER2.generated.h"

UCLASS()
class JAM_API AMyCharacterVER2 : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AMyCharacterVER2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	UFUNCTION()
		void MoveForward(float Value);
	UFUNCTION()
		void MoveRight(float Value);


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float FB;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float LR;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool possessing;

//	UFUNCTION(BlueprintCallable, Category = "Tick Nodes")
	//	float RMove();




};
