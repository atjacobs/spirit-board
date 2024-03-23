#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  for(uint8_t pin_idx = 1; pin_idx < 14; pin_idx++){
    digitalWrite(pin_idx,0);
    pinMode(pin_idx,OUTPUT);
  }
  
  digitalWrite(1,0);
  pinMode(1,OUTPUT);
}

void loop() {
  static uint8_t active_pin = 1;
  for(uint8_t pin_idx = 1; pin_idx < 14; pin_idx++){
    pinMode(pin_idx, INPUT);
  }
  pinMode(active_pin,OUTPUT);
  delay(200);
  if(++active_pin > 13){
    active_pin = 1;
  }
}
