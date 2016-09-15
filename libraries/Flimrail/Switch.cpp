/*
	Flimrail Switch Control

	Switch object class
	v. 0.1
	Phil Barbier - 2016
*/

/*
 * switchData definition
 * array(switchId, servoMovement, inputPin, outputPin, defaultDirection - 0=straight, 1=turn, isPair - 0=no, 1=yes)
 *
 */

#include "Arduino.h"
#include "Switch.h"
#include "Servo.h"

Servo servos[24];

// constructor
Switch::Switch(int numSwitches) {
  Servo servos[numSwitches];
}

// destructor ?
//Switch::~Switch() {
//}

void Switch::attachServo(int switchId, int servoPin) {
	servos[switchId].attach(servoPin);
}

void Switch::makeTurn(int switchId, int servoMove) {
	// access switch data, turn servo by switchType movement value constant declared above
  servos[switchId].write(servoMove);
}

void Switch::makeStraight(int switchId) {
	// access switch data, move servo to position 0
  servos[switchId].write(0);
}

