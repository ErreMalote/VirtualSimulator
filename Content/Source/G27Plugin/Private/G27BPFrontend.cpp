#include "G27PluginPrivatePCH.h"
#include "G27BPFrontend.h"
//////////////////////////////////////////////////////////////////////////
// UG27BPFrontend

#define G27PLUGIN IG27Plugin::Get()

float UG27BPFrontend::Wheel_getSteeringValue()
{
	return G27PLUGIN.getSteeringValue();
}

float UG27BPFrontend::Wheel_getBrakeValue()
{
	return G27PLUGIN.getBrakeValue();
}

float UG27BPFrontend::Wheel_getAccelerateValue()
{
	return G27PLUGIN.getAccelerateValue();
}

float UG27BPFrontend::Wheel_getCombinedThrottleValue()
{
	return G27PLUGIN.getAccelerateValue() - G27PLUGIN.getBrakeValue();
}


void UG27BPFrontend::Wheel_update()
{
	G27PLUGIN.updateWheel();
	return;
}

void UG27BPFrontend::Wheel_activate()
{
	G27PLUGIN.activateWheel();
	return;
}

bool UG27BPFrontend::Wheel_isConnected()
{
	return G27PLUGIN.isWheelConnected();
}

void UG27BPFrontend::Wheel_playSpringForce(float offset, float saturation, float percentage)
{
	G27PLUGIN.playSpringForce(offset, saturation, percentage);
	return;
}
	
