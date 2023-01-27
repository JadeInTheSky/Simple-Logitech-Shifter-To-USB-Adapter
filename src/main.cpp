#include <Arduino.h>
#include <Joystick.h>

//You can adjust the delay between each check loop in ms (ie: 1000 = 1 second)
#define shifter_delay 250

//Look into the X and Y value in Serial monitor and adjust the thresholds if it doesn't ingage gears correctly ingame
const int x_thresh_left = 400; // if x < 400
const int x_thresh_right = 625; // if x > 625
const int y_thresh_high = 900; // if y > 900
const int y_thresh_low = 150; // if y < 150

int last_gear = 0;
int current_gear = 0;

Joystick_ Joystick;

uint8_t ReadShifter(){
  int gear = 0;
  int x = analogRead(A0);
  int y = analogRead(A1);
  bool reverse = digitalRead(12);

  Serial.print("\n---------");
  Serial.print("\nX: "+String(x));
  Serial.print("\nY: "+String(y));
  Serial.print("\nReverse: "+String(reverse));
  Serial.print("\n---------");
  
  if (reverse){ // Reverse
    gear = 7; 
  }
  else if (x < x_thresh_left){ 
    if (y > y_thresh_high){
      gear = 1;
    }
    else if (y <y_thresh_low){
      gear = 2;
    }
  }
  else if (x > x_thresh_left and x < x_thresh_right){ 
    if (y > y_thresh_high){
      gear = 3;
    }
    else if (y <y_thresh_low){
      gear = 4;
    }
  }
  else if (x > x_thresh_right){ 
    if (y > y_thresh_high){
      gear = 5;
    }
    else if (y <y_thresh_low){
      gear = 6;
    }
  }

  Serial.print("\nGear Position: "+String(gear));
  return gear; //returns the gear position
}

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT); // Reverse
  pinMode(A1, INPUT_PULLUP); // Y Axis
  pinMode(A0, INPUT_PULLUP); // X axis

  Joystick.begin();
}

void loop() {
  current_gear = ReadShifter();

  if (last_gear != current_gear){
    Serial.print("\n|---------|");
    Serial.print("\nLast gear: "+String(last_gear));
    Serial.print("\nCurrent Gear: "+String(current_gear));
    Serial.print("\n|---------|");
    Joystick.releaseButton(last_gear);
    Joystick.pressButton(current_gear);
    last_gear = current_gear;
  }
  
  delay(shifter_delay);
}