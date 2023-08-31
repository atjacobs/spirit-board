/*
 * tlc59401.h
 *
 *  Created on: June 26, 2023
 *      Author: alexjacobs
 */

#include <stdint.h>
#include <stdbool.h>

#define NUM_TLC59401_CHIPS 1

typedef enum {
    TLC59401_ERR_SUC,
    TLC59401_ERR_TEF,
    TLC59401_ERR_LOD,
} tlc59401_err_t;

// you should implement these elsewere--will be called by driver
int bsp_tlc59401_write(uint8_t buf[], uint16_t length);

// These must happen in greater than 10 ns:
//  - MODE     -> SCLK_up
//  - MODE     -> XLAT_up
//  - SCLK_up  -> MODE
//  - XLAT_dwn -> MODE
int bsp_tlc59401_set_mode(bool GS_mode);

int bsp_tlc59401_wait(uint32_t ns);

// void bsp_tlc59401_err(uint8_t err, void *data);

// Set XLAT, which latches all shifted data.
//  Timing constraints:
//  - Must stay high       > 20 ns
//  - XLAT_dwn -> MODE     > 10 ns
//  - MODE     -> XLAT_up  > 10 ns
//  - SCLK_dwn -> XLAT_up  > 10 ns
//  - XLAT_up  -> GSCLK_up > 30 ns
//  - XLAT_dwn -> SCLK_up  > 10 ns
void bsp_tlc59401_xlat();

void bsp_tlc59401_blank(bool high);

void bsp_tlc59401_disable_gsclk();
void bsp_tlc59401_enable_gsclk();

bool bsp_tlc59401_err_pin_high(void);

// Call this function when the PWM period has fired
// It programs register values and then resets the greyscale cycle.
// If you don't call this, the LEDs won't ever turn on.
// This also checks for errors.
tlc59401_err_t tlc59401_pwm_period_passed(void);

int tlc59401_init();

int tlc59401_set_pwm(uint8_t chip, uint8_t channel, uint16_t pwm_counter);

int tlc59401_set_current(uint8_t chip, uint8_t channel, uint8_t current);

tlc59401_err_t tlc59401_start();