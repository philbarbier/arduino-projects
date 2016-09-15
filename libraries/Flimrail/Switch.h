/*
	Flimrail Switch Control

	Switch header class
	v. 0.1
	Phil Barbier - 2016.
*/

#ifndef Switch_h
#define Switch_h

#include "Arduino.h"

class Switch
{
	public:
		Switch(int numSwitches);
		// ~Switch();

		void attachServo(int switchId, int servoPin);
		void makeTurn(int switchId, int servoMove);
		void makeStraight(int switchId);
};

#endif
