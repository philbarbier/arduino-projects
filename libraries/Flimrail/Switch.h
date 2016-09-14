/*
	Flimrail Switch Control

	Switch header class
	v. 0.1
	Phil Barbier - 2016.
*/

#ifndef Switch_h
#define Switch_h
#include "WProgram.h"

class Switch {
	public:
		Switch();
		~Switch();

		void makeTurn(int switchId);
		void makeStraight(int switchId);

		std:array buildSwitcdhDetails();
};

#endif