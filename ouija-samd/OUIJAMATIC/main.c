#include <atmel_start.h>

#include "message.h"

#define I2C_ADDR (0x)

typedef struct{
	ouija_symbol_t symbol;
	uint32_t pin;
} ouija_pin_table_entry;

message_ouija_t message;

ouija_pin_table_entry ouija_pin_table[NUM_OUIJA_SYMBOLS] = {
		{OUIJA_SYMBOL_A, PIN_A},
		{OUIJA_SYMBOL_B, PIN_B},
		{OUIJA_SYMBOL_C, PIN_C},
		{OUIJA_SYMBOL_D, PIN_D},
		{OUIJA_SYMBOL_E, PIN_E},
		{OUIJA_SYMBOL_F, PIN_F},
		{OUIJA_SYMBOL_G, PIN_G},
		{OUIJA_SYMBOL_H, PIN_H},
		{OUIJA_SYMBOL_I, PIN_I},
		{OUIJA_SYMBOL_J, PIN_J},
		{OUIJA_SYMBOL_K, PIN_K},
		{OUIJA_SYMBOL_L, PIN_L},
		{OUIJA_SYMBOL_M, PIN_M},
		{OUIJA_SYMBOL_N, PIN_N},
		{OUIJA_SYMBOL_O, PIN_O},
		{OUIJA_SYMBOL_P, PIN_P},
		{OUIJA_SYMBOL_Q, PIN_Q},
		{OUIJA_SYMBOL_R, PIN_R},
		{OUIJA_SYMBOL_S, PIN_S},
		{OUIJA_SYMBOL_T, PIN_T},
		{OUIJA_SYMBOL_U, PIN_U},
		{OUIJA_SYMBOL_V, PIN_V},
		{OUIJA_SYMBOL_W, PIN_W},
		{OUIJA_SYMBOL_X, PIN_X},
		{OUIJA_SYMBOL_Y, PIN_Y},
		{OUIJA_SYMBOL_Z, PIN_Z},
		{OUIJA_SYMBOL_YES, PIN_YES},
		{OUIJA_SYMBOL_NO, PIN_NO},
		{OUIJA_SYMBOL_1, PIN_1},
		{OUIJA_SYMBOL_2, PIN_2},
		{OUIJA_SYMBOL_3, PIN_3},
		{OUIJA_SYMBOL_4, PIN_4},
		{OUIJA_SYMBOL_5, PIN_5},
		{OUIJA_SYMBOL_6, PIN_6},
		{OUIJA_SYMBOL_7, PIN_7},
		{OUIJA_SYMBOL_8, PIN_8},
		{OUIJA_SYMBOL_9, PIN_9},
		{OUIJA_SYMBOL_0, PIN_0},
		{OUIJA_SYMBOL_WAVE, PIN_WAVE},
		{OUIJA_SYMBOL_OFF, 0xFFFFFFFF},
};

void init(void){
	for(uint8_t gpio_idx = 0; gpio_idx < (NUM_OUIJA_SYMBOLS - 1); gpio_idx++){
		ouija_pin_table_entry *mapping = &ouija_pin_table[gpio_idx];
		gpio_set_pin_level(mapping->pin, false);
		gpio_set_pin_direction(mapping->pin, GPIO_DIRECTION_IN);
	}
}

void onehot_gpio(uint32_t gpio){
	for(uint8_t gpio_idx = 0; gpio_idx < (NUM_OUIJA_SYMBOLS - 1); gpio_idx++){
		ouija_pin_table_entry *mapping = &ouija_pin_table[gpio_idx];
		if(mapping->pin == gpio)
			continue;
		gpio_set_pin_direction(mapping->pin, GPIO_DIRECTION_IN);
	}
	if (gpio != 0xFFFFFFFF){
		gpio_set_pin_direction(gpio, GPIO_DIRECTION_OUT);
	}
}

void fw_assert(int expr){
	if(expr)
		return;
	while(1);
}

static struct io_descriptor *io;

ouija_symbol_t current_symbol = OUIJA_SYMBOL_OFF;

void i2c_rx_cb(const struct i2c_s_async_descriptor *const descr){
	uint8_t c;

	io_read(io, &c, 1);
	
	if(current_symbol >= NUM_OUIJA_SYMBOLS){
		current_symbol = (uint8_t)OUIJA_SYMBOL_OFF;
	}
	
	onehot_gpio(ouija_pin_table[current_symbol].pin);
}



int main(void)
{
	uint32_t ret;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	init();
	i2c_s_async_set_addr(&I2C_0, 0x3B);
	i2c_s_async_get_io_descriptor(&I2C_0, &io);
	ret = i2c_s_async_register_callback(&I2C_0, I2C_S_RX_COMPLETE, i2c_rx_cb);
	i2c_s_async_enable(&I2C_0);
	
	while(1){
		hal_sleep(0);
	}
	//uint8_t idx = 0;
	///* Replace with your application code */
	//while (1) {
		//uint32_t gpio = ouija_pin_table[idx].pin;
		//onehot_gpio(gpio);
		//delay_ms(250);
		//idx = ++idx % NUM_OUIJA_SYMBOLS;
	//}
}
