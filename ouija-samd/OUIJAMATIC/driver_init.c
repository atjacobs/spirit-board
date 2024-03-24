/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

struct usart_sync_descriptor USART_0;

struct i2c_s_async_descriptor I2C_0;
uint8_t                       SERCOM5_i2c_s_buffer[SERCOM5_I2CS_BUFFER_SIZE];

void USART_0_PORT_init(void)
{

	gpio_set_pin_function(PA04, PINMUX_PA04D_SERCOM0_PAD0);

	gpio_set_pin_function(PA05, PINMUX_PA05D_SERCOM0_PAD1);
}

void USART_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, SERCOM0, (void *)NULL);
	USART_0_PORT_init();
}

void I2C_0_PORT_init(void)
{

	gpio_set_pin_pull_mode(PIN_SDA,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_SDA, PINMUX_PB30D_SERCOM5_PAD0);

	gpio_set_pin_pull_mode(PIN_SCL,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_SCL, PINMUX_PB31D_SERCOM5_PAD1);
}

void I2C_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM5);
	_gclk_enable_channel(SERCOM5_GCLK_ID_CORE, CONF_GCLK_SERCOM5_CORE_SRC);
	_gclk_enable_channel(SERCOM5_GCLK_ID_SLOW, CONF_GCLK_SERCOM5_SLOW_SRC);
}

void I2C_0_init(void)
{
	I2C_0_CLOCK_init();
	i2c_s_async_init(&I2C_0, SERCOM5, SERCOM5_i2c_s_buffer, SERCOM5_I2CS_BUFFER_SIZE);
	I2C_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA00

	// Set pin direction to input
	gpio_set_pin_direction(PIN_E, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_E,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_E, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA01

	// Set pin direction to input
	gpio_set_pin_direction(PIN_S, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_S,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_S, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA02

	// Set pin direction to input
	gpio_set_pin_direction(PIN_D, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_D,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_D, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA03

	// Set pin direction to input
	gpio_set_pin_direction(PIN_R, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_R,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_R, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA06

	// Set pin direction to input
	gpio_set_pin_direction(PIN_YES, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_YES,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_YES, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA08

	// Set pin direction to input
	gpio_set_pin_direction(PIN_1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA09

	// Set pin direction to input
	gpio_set_pin_direction(PIN_2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA10

	// Set pin direction to input
	gpio_set_pin_direction(PIN_3, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_3,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_3, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA11

	// Set pin direction to input
	gpio_set_pin_direction(PIN_4, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_4,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_4, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA16

	// Set pin direction to input
	gpio_set_pin_direction(PIN_WAVE, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_WAVE,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_WAVE, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA17

	// Set pin direction to input
	gpio_set_pin_direction(PIN_Z, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_Z,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_Z, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA18

	// Set pin direction to input
	gpio_set_pin_direction(PIN_N, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_N,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_N, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA19

	// Set pin direction to input
	gpio_set_pin_direction(PIN_Y, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_Y,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_Y, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA20

	// Set pin direction to input
	gpio_set_pin_direction(PIN_M, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_M,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_M, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA21

	// Set pin direction to input
	gpio_set_pin_direction(PIN_X, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_X,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_X, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA22

	// Set pin direction to input
	gpio_set_pin_direction(PIN_L, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_L,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_L, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA23

	// Set pin direction to input
	gpio_set_pin_direction(PIN_W, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_W,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_W, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA24

	// Set pin direction to input
	gpio_set_pin_direction(PIN_K, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_K,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_K, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA25

	// Set pin direction to input
	gpio_set_pin_direction(PIN_J, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_J,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_J, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA27

	// Set pin direction to input
	gpio_set_pin_direction(PIN_I, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_I,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_I, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA28

	// Set pin direction to input
	gpio_set_pin_direction(PIN_U, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_U,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_U, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB00

	// Set pin direction to input
	gpio_set_pin_direction(PIN_H, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_H,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_H, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB01

	// Set pin direction to input
	gpio_set_pin_direction(PIN_T, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_T,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_T, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB02

	// Set pin direction to input
	gpio_set_pin_direction(PIN_G, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_G,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_G, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB03

	// Set pin direction to input
	gpio_set_pin_direction(PIN_F, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_F,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_F, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB04

	// Set pin direction to input
	gpio_set_pin_direction(PIN_C, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_C,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_C, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB05

	// Set pin direction to input
	gpio_set_pin_direction(PIN_Q, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_Q,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_Q, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB06

	// Set pin direction to input
	gpio_set_pin_direction(PIN_B, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_B,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_B, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB07

	// Set pin direction to input
	gpio_set_pin_direction(PIN_P, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_P,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_P, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB08

	// Set pin direction to input
	gpio_set_pin_direction(PIN_A, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_A,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_A, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB09

	// Set pin direction to input
	gpio_set_pin_direction(PIN_O, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_O,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_O, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB10

	// Set pin direction to input
	gpio_set_pin_direction(PIN_5, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_5,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_5, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB11

	// Set pin direction to input
	gpio_set_pin_direction(PIN_6, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_6,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_6, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB12

	// Set pin direction to input
	gpio_set_pin_direction(PIN_7, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_7,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_7, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB13

	// Set pin direction to input
	gpio_set_pin_direction(PIN_8, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_8,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_8, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB14

	// Set pin direction to input
	gpio_set_pin_direction(PIN_9, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_9,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_9, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB15

	// Set pin direction to input
	gpio_set_pin_direction(PIN_0, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_0,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB16

	// Set pin direction to input
	gpio_set_pin_direction(USART_TX, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(USART_TX,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(USART_TX, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB17

	// Set pin direction to input
	gpio_set_pin_direction(USART_RX, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(USART_RX,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(USART_RX, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB22

	// Set pin direction to input
	gpio_set_pin_direction(PIN_V, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_V,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_V, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB23

	// Set pin direction to input
	gpio_set_pin_direction(PIN_NO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_NO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_NO, GPIO_PIN_FUNCTION_OFF);

	USART_0_init();

	I2C_0_init();
}
