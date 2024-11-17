#include <Arduino.h>
#include "SPI.h"
#include "driver/pcnt.h"
#include "tlc59401.h"
#include "ouija.h"
#include <Wire.h>
#include <ble.h>

bool toggle = true;
// char my_message[] = "abcdefghijklmnopqr";
char my_message[] = "greenfirst";

void setup() {
  Wire.begin(23,22,0);
  exp32_hal_led_init();
  Serial.begin(115200);
  ouija_init();
  ouija_set_string(my_message);
  analogWrite(15, 16);
  Wire.beginTransmission(0x3B);
  Wire.write(0xeb);
  Wire.endTransmission();
  ble_setup();
}

void loop() {
  // analogWrite(current_pin, 16);
  // ouija_loop();
}
