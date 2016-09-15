#include <Servo.h>

Servo switch1;

int controlPin = 2;
int servoPin = 27;
int b = 0;
int die = 0;
int switchMax = 25;

void setup() {
  switch1.attach(servoPin);
  Serial.begin(9600);
}

void loop() {

  int switchState = digitalRead(controlPin);

  Serial.println("state: ");
  Serial.println(switchState);
  if (switchState == 0) {
    makeTurn();
  } else {
    makeStraight();  
  }

  //exit(0);
  
  if (die > 25) {
    exit(0);
  }
  
  die++;
}

void makeTurn() {
  for (b = 0; b <= switchMax; b+=1) {
    switch1.write(b);
    delay(15);
  }
}

void makeStraight() {
  
  for (b = switchMax; b >= 0; b-=1) {
    switch1.write(b);
    delay(15);
  }
}

