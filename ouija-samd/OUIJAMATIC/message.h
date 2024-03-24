/*
 * message.h
 *
 * Created: 10/6/2023 6:09:38 PM
 *  Author: alexa
 */ 


#ifndef MESSAGE_H_
#define MESSAGE_H_
#define MESSAGE_VERSION_MAJOR (00)

typedef struct {
	uint16_t version;
	uint16_t payload_size;
	uint32_t destination;
	uint32_t source;
	void *payload;
} message_header_t;

typedef enum {
	OUIJA_SYMBOL_A = 0,
	OUIJA_SYMBOL_B = 1,
	OUIJA_SYMBOL_C = 2,
	OUIJA_SYMBOL_D = 3,
	OUIJA_SYMBOL_E = 4,
	OUIJA_SYMBOL_F = 5,
	OUIJA_SYMBOL_G = 6,
	OUIJA_SYMBOL_H = 7,
	OUIJA_SYMBOL_I = 8,
	OUIJA_SYMBOL_J = 9,
	OUIJA_SYMBOL_K = 10,
	OUIJA_SYMBOL_L = 11,
	OUIJA_SYMBOL_M = 12,
	OUIJA_SYMBOL_N = 13,
	OUIJA_SYMBOL_O = 14,
	OUIJA_SYMBOL_P = 15,
	OUIJA_SYMBOL_Q = 16,
	OUIJA_SYMBOL_R = 17,
	OUIJA_SYMBOL_S = 18,
	OUIJA_SYMBOL_T = 19,
	OUIJA_SYMBOL_U = 20,
	OUIJA_SYMBOL_V = 21,
	OUIJA_SYMBOL_W = 22,
	OUIJA_SYMBOL_X = 23,
	OUIJA_SYMBOL_Y = 24,
	OUIJA_SYMBOL_Z = 25,
	OUIJA_SYMBOL_YES = 26,
	OUIJA_SYMBOL_NO = 27,
	OUIJA_SYMBOL_WAVE = 28,
	OUIJA_SYMBOL_1 = 29,
	OUIJA_SYMBOL_2 = 30,
	OUIJA_SYMBOL_3 = 31,
	OUIJA_SYMBOL_4 = 32,
	OUIJA_SYMBOL_5 = 33,
	OUIJA_SYMBOL_6 = 34,
	OUIJA_SYMBOL_7 = 35,
	OUIJA_SYMBOL_8 = 36,
	OUIJA_SYMBOL_9 = 37,
	OUIJA_SYMBOL_0 = 38,
	OUIJA_SYMBOL_OFF = 39,
	NUM_OUIJA_SYMBOLS
} ouija_symbol_t;

typedef struct{
	message_header_t header;
	ouija_symbol_t symbol;
} message_ouija_t;

#endif /* MESSAGE_H_ */