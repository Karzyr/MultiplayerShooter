// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"


void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	// const ENetRole RemoteRole = InPawn->GetRemoteRole();
	// FString Role;
	// switch (RemoteRole) {
	// case ROLE_None:
	// 	Role = FString("None");
	// 	break;
	// case ROLE_SimulatedProxy:
	// 	Role = FString("Simulated Proxy");
	// 	break;
	// case ROLE_AutonomousProxy:
	// 	Role = FString("Autonomous Proxy");
	// 	break;
	// case ROLE_Authority:
	// 	Role = FString("Authority");
	// 	break;
	// default: ;
	// }
	//
	// FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);
	if (InPawn)
	{
		if (InPawn->GetPlayerState())
			SetDisplayText(InPawn->GetPlayerState()->GetPlayerName());
	}
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
