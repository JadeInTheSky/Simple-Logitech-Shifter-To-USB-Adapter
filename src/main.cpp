#include <Arduino.h>
#include <Joystick.h>

const int x_thresh_left = 400; // if x < 400
const int x_thresh_right = 625; // if x > 650
const int y_thresh_high = 900; // if y > 900
const int y_thresh_low = 150; // if y < 150

int last_gear = 0;
int current_gear = 0;

Joystick_ Joystick;

uint8_t ReadShifter(){
  int gear = 0;
  int x = analogRead(A0); //Green wire
  int y = analogRead(A1); //Blue wire
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
    if (y > y_thresh_high){ //gear 1
      gear = 1;
    }
    else if (y <y_thresh_low){ //gear 2
      gear = 2;
    }
  }
  else if (x > x_thresh_left and x < x_thresh_right){ 
    if (y > y_thresh_high){ //gear 3
      gear = 3;
    }
    else if (y <y_thresh_low){ //gear 4
      gear = 4;
    }
  }
  else if (x > x_thresh_right){ 
    if (y > y_thresh_high){ //gear 5
      gear = 5;
    }
    else if (y <y_thresh_low){ //gear 6
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
  pinMode(A2, INPUT_PULLUP); // X axis

  Joystick.begin();
}

void loop() {
  current_gear = ReadShifter();

  if (last_gear != current_gear){
    Serial.print("\nLast gear: "+String(last_gear));
    Serial.print("\nCurrent Gear: "+String(current_gear));
    Joystick.releaseButton(last_gear);
    Joystick.pressButton(current_gear);
    last_gear = current_gear;
  }
  
  delay(250);
}

// x_thresh_left = 850; //if x < 850 
// x_thresh_right = 990; //if x > 990
// x is at middle position when above 850 and below 990
// y_thresh_high = 800; //if y > 800 and y < 850
// y_thresh_mid = 850 // if y > 850 = neutral
// y_thresh_low = 550; //if y < 550

