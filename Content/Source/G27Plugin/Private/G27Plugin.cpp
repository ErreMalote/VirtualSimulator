// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "G27PluginPrivatePCH.h"
#include <MyWheelLib.h>

using namespace WheelLib;

class FG27Plugin : public IG27Plugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	//MyWheelLib Proxy
	virtual void updateWheel() override;
	virtual bool isWheelConnected() override;
	virtual void activateWheel() override;
	virtual void deactivateWheel() override; 
	virtual void refreshButtonState() override;

	//Input
	virtual float getSteeringValue() override;
	virtual float getBrakeValue() override;
	virtual float getAccelerateValue() override;
	virtual float getClutchValue() override;

	//from saved button state
	virtual bool getGearUp() override;
	virtual bool getGearDown() override;

	//ForceFeedback
	virtual void playSpringForce(double offset, double saturation, double percentage) override;

	private:
		buttonState buttonState;


};

IMPLEMENT_MODULE( FG27Plugin, G27Plugin )



void FG27Plugin::StartupModule()
{
	// for some yet unknown reason, this makes wheel not work while using Play-in-Editor mode (Standalone game works fine)
	//MyWheelLib::ActivateWheel();
}


void FG27Plugin::ShutdownModule()
{
	MyWheelLib::DeactivateWheel();
}

void FG27Plugin::activateWheel()
{
	MyWheelLib::ActivateWheel();
}

void FG27Plugin::deactivateWheel()
{
	//MyWheelLib::DeactivateWheel();
}

bool FG27Plugin::isWheelConnected()
{
	return MyWheelLib::isConnected();
}

void FG27Plugin::updateWheel()
{
	MyWheelLib::Update();
	refreshButtonState();
}

void FG27Plugin::refreshButtonState()
{
	buttonState = MyWheelLib::GetButtonState();
}


float FG27Plugin::getSteeringValue()
{
	return MyWheelLib::GetSteeringValue();
}

float FG27Plugin::getBrakeValue()
{
	return MyWheelLib::GetBrakeValue();
}

float FG27Plugin::getAccelerateValue()
{
	return MyWheelLib::GetAccelerateValue();
}

float FG27Plugin::getClutchValue()
{
	return MyWheelLib::GetClutchValue();
}

bool FG27Plugin::getGearUp()
{
	return buttonState.gearUp;
}

bool FG27Plugin::getGearDown()
{
	return buttonState.gearDown;
}

void FG27Plugin::playSpringForce(double offset, double saturation, double percentage)
{
	MyWheelLib::PlaySpringForce(offset, saturation, percentage);
	return;
}




