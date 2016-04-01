// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"


/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class IG27Plugin : public IModuleInterface
{

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IG27Plugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IG27Plugin >( "G27Plugin" );
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "G27Plugin" );
	}

	//Matching functions of MyWheelLib.h
	//Wheel management
	virtual void updateWheel() = 0;
	virtual bool isWheelConnected() = 0;
	virtual void activateWheel() = 0;
	virtual void deactivateWheel() = 0;
	virtual void refreshButtonState() = 0;

	//Input
	virtual float getSteeringValue() = 0;
	virtual float getBrakeValue() = 0;
	virtual float getAccelerateValue() = 0;
	virtual float getClutchValue() = 0;

	//buttons, from saved state. Return as bools so the rest of code don't meet 
	virtual bool getGearUp() = 0;
	virtual bool getGearDown() = 0;

	//ForceFeedback
	virtual void playSpringForce(double offset, double saturation, double percentage) = 0;
	
};

