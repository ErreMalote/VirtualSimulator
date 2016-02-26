
#pragma once

#include "G27BPFrontend.generated.h"

UCLASS()
class G27PLUGIN_API UG27BPFrontend : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:

	// Basic functions 
	UFUNCTION(BlueprintCallable, Category = "Input|G27 Plugin", meta = (FriendlyName = "Wheel Tick", Keywords = "steering wheel"))
	static void Wheel_update();

	UFUNCTION(BlueprintCallable, Category = "Input|G27 Plugin", meta = (FriendlyName = "Wheel Activate", Keywords = "steering wheel"))
	static void Wheel_activate();

	UFUNCTION(BlueprintPure, Category = "Input|G27 Plugin", meta = (FriendlyName = "Is Wheel Connected", Keywords = "steering wheel"))
	static bool Wheel_isConnected();

	//Value reading		
	UFUNCTION(BlueprintPure, Category = "Input|G27 Plugin", meta = (FriendlyName = "Get steering value", CompactNodeTitle = "(-)", Keywords = "steering wheel"))
	static float Wheel_getSteeringValue();

	UFUNCTION(BlueprintPure, Category = "Input|G27 Plugin", meta = (FriendlyName = "Get brake value", Keywords = "steering wheel brake"))
	static float Wheel_getBrakeValue();

	UFUNCTION(BlueprintPure, Category = "Input|G27 Plugin", meta = (FriendlyName = "Get accelerate value", Keywords = "steering wheel accelerate thrust"))
	static float Wheel_getAccelerateValue();

	UFUNCTION(BlueprintPure, Category = "Input|G27 Plugin", meta = (FriendlyName = "Get combined throttle value", Keywords = "steering wheel accelerate thrust"))
	static float Wheel_getCombinedThrottleValue();


	//Force Feedback
	UFUNCTION(BlueprintCallable, Category = "Input|G27 Plugin", meta = (FriendlyName = "PlaySpringForce", Keywords = "steering wheel"))
	static void Wheel_playSpringForce(float offset = 0.0, float saturation = 0.5, float percentage = 0.5);


};

