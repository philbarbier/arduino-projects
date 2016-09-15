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

int timeDelay = 50;

// constructor
Switch::Switch(int numSwitches) {
  Servo servos[numSwitches];
  Serial.begin(9600);
}

// destructor ?
//Switch::~Switch() {
//}

void Switch::attachServo(int switchId, int servoPin) {
	servos[switchId].attach(servoPin);
}

void Switch::makeTurn(int switchId, int servoMove) {
	// access switch data, turn servo by switchType movement value constant declared above

	Serial.println(switchId);
	Serial.println(servoMove);

	for (int i=0; i < servoMove; i++) {
		if (servos[switchId].read() < servoMove) {
			Serial.println("turn");
			Serial.println(i);
			servos[switchId].write(i);
			delay(timeDelay);
		}
	}
}

void Switch::makeStraight(int switchId) {
	// access switch data, move servo to position 0
	int currPos = servos[switchId].read();

	for (int i=currPos; i > 0; i--) {
		if (servos[switchId].read() > currPos) {
			Serial.println("straight");
  			servos[switchId].write(i);
  			Serial.println(i);
  			delay(timeDelay);
		}
	}
}

