#include <Arduino.h>
#include "SPI.h"
#include "driver/pcnt.h"
#include "tlc59401.h"
#include "ouija.h"

bool toggle = true;
// char my_message[] = "abcdefghijklmnopqr";
char my_message[] = "greenfirst";

void setup() {

  exp32_hal_led_init();
  Serial.begin(115200);
  ouija_init();
  ouija_set_string(my_message);

}

void loop() {

  ouija_loop();
}
