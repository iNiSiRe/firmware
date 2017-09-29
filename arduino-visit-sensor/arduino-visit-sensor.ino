#include <Arduino.h>
#include "BeamIntersectionTracker.h";
#include <Wire.h>;

int led = 13;
int left = 3;
int right = 2;

int currentDirection = NULL;

void callback(int direction) {
  Serial.println("callback");
  
  Wire.beginTransmission(8);
  Wire.write(direction);
  Wire.endTransmission();
  
  // currentDirection = direction;
}

BeamIntersectionTracker tracker(callback);

int previousLeftValue, previousRightValue = LOW;

void requestEvent() {
  if (currentDirection != NULL) {
    Serial.println("test-send");
    Wire.write(currentDirection);
    currentDirection = NULL; 
  }
}

// the setup routine runs once when you press reset:
void setup() {     
  Serial.begin(9600);
  Serial.println("test");
  
  Wire.begin(9);
  //Wire.onRequest(requestEvent);
             
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);

  attachInterrupt(digitalPinToInterrupt(left), changedLeft, CHANGE);
  attachInterrupt(digitalPinToInterrupt(right), changedRight, CHANGE);
}

// the loop routine runs over and over again forever:
void loop() {  
  delay(1);
  tracker.loop();
}

void changedLeft() {
  int value = digitalRead(left);

  if (previousLeftValue != value) {
    tracker.intersection(1, value);
    previousLeftValue = value;
  }
}

void changedRight() {
  int value = digitalRead(right);

  if (previousRightValue != value) {
    tracker.intersection(2, value);
    previousRightValue = value;
  }
}

