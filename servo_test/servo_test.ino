#include <Servo.h>

Servo switch1;

int controlPin = 47;
int servoPin = 7;
int b = 0;
int switchMax = 25;

void setup() {
  switch1.attach(servoPin);
}

void loop() {

  makeTurn();

  makeStraight();
  

  

  exit(0);
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

