/*
 * Flimrail switch control software
 * 
 * v 0.1 - (c)2016 Phil Barbier / Flimflam
 * 
 */

#include <Switch.h>

const int numSwitches = 2;

// switches that work as pairs (ie: crossovers)
const int switchPairs[1][2] = {
  {0,1}
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
 * - switchType - was intended to identify differences in switches for servo movement
 *              - not necessary anymore since switchData contains the servo movement value
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
int die = 0;

// for now have this shit in here, eventually move to SD card + csv
/*
 * switchData definition
 * array(switchId, servoMovement, inputPin, outputPin, defaultDirection - 0=straight, 1=turn, isPair - 0=no, 1=yes)
 * 
 */
int switchData[8][6] = {
  {0, 25, 2, 27, 0, 1}, // inner->outer loop north side
  {1, 25, 3, 28, 0, 1}, // outer->inner loop north side
  {2, 25, 4, 29, 0, 1}, // outer->inner loop south side
  {3, 25, 5, 30, 0, 1}, // inner->outer loop south side
  {4, 25, 6, 31, 0, 0}, // outer->upper
  {5, 25, 7, 32, 0, 0}, // inner->passing track south side
  {6, 25, 8, 33, 0, 0}, // inner->passing track north side
  {7, 25, 9, 34, 1, 0} // upper line escape track switch
};

Switch switches(numSwitches);

void setup() {
  Serial.begin(9600);

  for (int i=0; i < numSwitches; i++) {
    pinMode(switchData[i][2], INPUT);
    switches.attachServo(switchData[i][0], switchData[i][3]);
  }

  delay(500);
  //exit(0);
}

void loop() {

  for (int i=0; i < numSwitches; i++) {
    // scan for inputs
    switchState = digitalRead(switchData[i][2]);

    int pairId = checkIsPair(switchData[i][0]);
    Serial.println("Pair:");
    Serial.println(pairId);
    if (switchState == HIGH) {
      switches.makeTurn(switchData[i][0], switchData[i][1]);
      if (pairId > 0) {
        switches.makeTurn(pairId, switchData[pairId][1]);
      }
    } else {
      switches.makeStraight(switchData[i][0]);
      if (pairId > 0) {
        switches.makeStraight(pairId);
      }
    }
    delay(1);
  }
  
  delay(250);
  
  if (die > 250) {
    Serial.println("End");
    delay(5);
    exit(0);
  }
  die++;
}

int checkIsPair(int switchId) {
  for (int i=0; i < sizeof(switchPairs); i++) {
    for (int j=0; j < sizeof(switchPairs[i]); j++) {
      if (switchPairs[i][j] == switchId) {
        if (j == 0) {
          return switchPairs[i][1];
        } else {
          return switchPairs[i][0];
        }
      }
    }
  }
  return 0;
}
