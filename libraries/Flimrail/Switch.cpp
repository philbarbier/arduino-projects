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

// constructor
Switch::Switch(int numSwitches, int switchData) {
  Servo servos[numSwitches];
  for (int i=0; i < (numSwitches-1); i++) {
    servos[i].attach(switchData[i][3]);
  }
}

// destructor ?
//Switch::~Switch() {
//}

void Switch::makeTurn(int switchData) {
	// access switch data, turn servo by switchType movement value constant declared above
  servos[switchData[0]].write(switchData[1]);
}

void Switch::makeStraight(int switchData) {
	// access switch data, move servo to position 0
  servos[switchData[0]].write(0);
}

