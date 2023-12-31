// Fill out your copyright notice in the Description page of Project Settings.


#include "OverHeadWidget.h"
#include "Components/TextBlock.h"

void UOverHeadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverHeadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	auto RemoteRole = InPawn->GetRemoteRole();
	auto LocalRole = InPawn->GetLocalRole();
	FString Role, Role2;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	}

	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:
		Role2 = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role2 = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role2 = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None:
		Role2 = FString("None");
		break;
	}

	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s Local Role %s"), *Role, *Role2);
	SetDisplayText(RemoteRoleString);
}

void UOverHeadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
