// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputMappingContext.h"
#include "InputAction.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"

class AWeapon;
class UWidgetComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* BlasterCamera;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* BlasterSpringArm;
	
	/** LOCOMOTION */
	UPROPERTY(EditAnywhere, Category = "Blaster: Input")
	UInputMappingContext* KnightMappingContext;

	UPROPERTY(EditAnywhere, Category = "Blaster:: Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category = "Blaster: Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category = "Blaster: Input")
	UInputAction* LookAction;

	/** HUD */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	UWidgetComponent* OverheadWidgetComponent;

	/** Overlapped Weapon */
	UPROPERTY(Replicated)
	AWeapon* OverlappingWeapon;

public:
	FORCEINLINE void SetOverlappingWeapon(AWeapon* Weapon) { OverlappingWeapon = Weapon; }
};
