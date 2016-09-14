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
		Switch(int numSwitches, int switchData);
		// ~Switch();
		void makeTurn(int switchId);
		void makeStraight(int switchId);
};

#endif
