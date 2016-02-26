
namespace WheelLib
{
	struct buttonState {
		bool gearUp;
		bool gearDown;
		bool lights;
		bool mainLights;
		bool ignition;
		bool handbrake;
		bool seatbelt;
	};
	
	class MyWheelLib
	{
	private:


	public:
		static void ActivateWheel();			//needs to be done before accessing the wheel
		static void DeactivateWheel();			//should be done at end
		static void Update();					//every tick, or at least before reading wheel data

		static bool isConnected();				//check is wheel is connected

		// INPUT
		static double GetSteeringValue();		//return the value of the steering wheel, range -1.0 to 1.0
		static double GetBrakeValue();			//return brake pedal value, range 0.0 - 1.0
		static double GetAccelerateValue();		//return gas pedal value, range 0.0 - 1.0
		static double GetClutchValue();			//return clutch pedal value, range 0.0 - 1.0

		static buttonState GetButtonState();	//return states, Learn2Drive mapping

		// FORCE FEEDBACK

		// offset - where the wheel should be centered to. Range -1.0 - 1.0
		// saturation - intensity of the effect. Range 0.0 - 1.0
		// Percentage - slope of the effect, higher value means the full efect (saturation) is reached sooner. Range -1.0 - 1.0
		static void PlaySpringForce(double offset,double saturation, double percentage);     
		static void StopSpringForce();

		static void PlayLEDS(int RPM);


	};
}