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

Servo servos[1];

int timeDelay = 25;

// constructor
Switch::Switch(int numSwitches) {
  Servo servos[numSwitches];
  Serial.begin(9600);
}

// destructor ?
//Switch::~Switch() {
//}

void Switch::attachServo(int switchId, int servoPin) {
	Serial.println("attaching:");
	Serial.println(switchId);
	Serial.println("to pin:");
	Serial.println(servoPin);
	servos[switchId].attach(servoPin);
	servos[switchId].write(0); // reset position
	delay(250);
	/*
	// this is just a on-start check, will have to be removed for production use
	Serial.println(servos[switchId].read());
	servos[switchId].write(90);
	delay(250);
	Serial.println(servos[switchId].read());
	servos[switchId].write(180);
	delay(250);
	servos[switchId].write(90);
	delay(250);
	servos[switchId].write(0);
	delay(250);
	*/
}

void Switch::makeTurn(int switchId, int servoMove) {

	int currPos = servos[switchId].read();

	if (currPos != servoMove) {
		for (int i=0; i <= servoMove; i++) {
			if ((servos[switchId].read() < servoMove) && (1)) {
				servos[switchId].write(i);
				delay(timeDelay);
			}
		}
	}
}

void Switch::makeStraight(int switchId) {
	// access switch data, move servo to position 0
	int currPos = servos[switchId].read();

	for (int i=currPos; i > 0; i--) {
		if (servos[switchId].read() > i) {
  			servos[switchId].write(i);
  			delay(timeDelay);
		}
	}
}

