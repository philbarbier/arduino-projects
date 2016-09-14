/*
	Flimrail Switch Control

	Switch object class
	v. 0.1
	Phil Barbier - 2016
*/

#include "Switch.h"
#include "Servo.h"

const byte SWITCH_TYPE1_MAX = 25; // movement of servo

// <<constructor>>
Switch::Switch(switchId){
	// look up switch details

	// build servo objects for each switch

	// setup pins for input/output

}

//<<destructor>>
Switch::~Switch() {
}

void Switch::makeTurn(switchId, direction) {
	// access switch data, turn servo by switchType movement value constant declared above

}

void Switch::makeStraight(switchId, direction) {
	// access switch data, move servo to position 0

}

std:array Switch::buildSwitchDetails() {
	// build switch data

}