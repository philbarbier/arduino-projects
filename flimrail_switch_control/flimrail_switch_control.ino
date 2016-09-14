#include <Servo.h>
#include <Switch.h>

const int maxNumSwitches = 24;
const int numSwitches = 8;

// switches that work as pairs (ie: crossovers)
const int switchPairs[4][2] = {
  {1,2},
  {3,4}
};

// for now have this shit in here, eventually move to SD card + csv
/*
 * switchData definition
 * array(switchId, servoMovement, inputPin, outputPin, defaultDirection - 0=straight, 1=turn, isPair - 0=no, 1=yes)
 * 
 */
const int switchData[8][6] = {
  {1, 25, 2, 27, 0, 1}, // inner->outer loop north side
  {2, 25, 3, 28, 0, 1}, // outer->inner loop north side
  {3, 25, 4, 29, 0, 1}, // outer->inner loop south side
  {4, 25, 5, 30, 0, 1}, // inner->outer loop south side
  {5, 25, 6, 31, 0, 0}, // outer->upper
  {6, 25, 7, 32, 0, 0}, // inner->passing track south side
  {7, 25, 8, 33, 0, 0}, // inner->passing track north side
  {8, 25, 9, 34, 1, 0} // upper line escape track switch
};

/*
 * Have custom header for switch object .h and .cpp, has functions to makeTurn/Straight given a switch ID.
 * 
 * switch has following constants:
 * - maxNumSwitches
 * 
 * switch has following properties:
 * - servoMovement
 * - inputPin
 * - outputPin
 * - id
 * - location?
 * - switchType - wtf is this for?
 * - defaultDirection (straight / turned)
 * 
 * switch has following methods
 * - makeTurn
 * - makeStraight
 * 
 * When instantiating switch object in control software below: 
 * - need to dynamically assign the pins to each switch
 * - need to define pins and servo movement
 * 
 * 
 */

int switchState = 0;
int b = 0;
int die = 0;
// Servo servos[8];

void setup() {
  Serial.begin(9600);
  // attach servos
  switches = new Switch(switchData); // how to init array of Switches?
  for (int i=0; i < numSwitches; i++) {
    // servos[i].attach(switchData[i][3]);
    
  }
  switch1.attach(servoPin);
  pinMode(switchPin, INPUT);
}

void loop() {
  //exit(0);
  //delay(500);
  for (i=0; i < (numSwitches-1); i++) {
    // scan for inputs
    switchState = digitalRead(switchData[i][2]);
    
    if (switchState == LOW) {
      Switch::makeTurn(switchData[i]);
      Serial.println("turn");
    } else {
      Switch::makeStraight(switchData[i]);
      Serial.println("straight");
    }
  }
  
  delay(1);
  
  if (die > 5000) {
    Serial.println("End");
    exit(0);
  }
  die++;
}


void makeTurn() {
  switch1.write(servoMax);
}

void makeStraight() {
  switch1.write(0);
}

