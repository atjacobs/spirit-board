#include <ouija.h>
#include <Arduino.h>
#include <config.h>

#define OUIJA_CHAR_ON_TIME_US   (3000000)
#define OUIJA_FADE_STEP_TIME_US ( 50000)
#define OUIJA_FADE_STEPS        (16)
#define PWM_FREQ                (2000000)
#define FADE_FREQ_STEP          ((PWM_FREQ)/(OUIJA_FADE_STEPS))
#define DUTY_CYCLE_STEP         (1)

#if BOARD == LOLIN32_KO
// Knock-off lolin32
static uint8_t gpio_table[] = {15,02,04,16,17,05,18,23,19,13,12,14,27,26,25,35,34,33,32,39,36};
#elif BOARD == LOLIN32_ADA
// static uint8_t gpio_table[] = {21,19,18,05,04,36,39,34,25,26,23,22,14,32,15,33,27,12,13};
// static uint8_t gpio_table[] = {21,19,18,05,04,25,26,23,22,14,32,15,33,27,12,13};
static uint8_t gpio_table[] = {21,19,18,05,04,25,26,14,32,15,33,27,12,13};

#else
#error Unknown board
#endif
static int64_t microseconds_elapsed(void){
    static int64_t last_time = 0;
    int64_t tmp = last_time;
    last_time = esp_timer_get_time();
    return esp_timer_get_time() - tmp;
}

void ouija_init(){
    dacDisable(25);
    dacDisable(26);
    for(uint8_t pin_idx = 0; pin_idx< sizeof(gpio_table); pin_idx++){
        // pinMatrixOutDetach(gpio_table[pin_idx],false,false);
        // pinMatrixInDetach(gpio_table[pin_idx], false, false);
        digitalWrite(gpio_table[pin_idx], 0);
    }
}

static char ouija_message[100] = {0};
int ouija_set_string(char message[]){
    uint8_t char_idx;
    for(char_idx = 0; char_idx < sizeof(ouija_message) - 1; char_idx++){
        printf("char: %c\n",message[char_idx]);
        if(message[char_idx] == 0){
            printf("ouija string of length %d\n", char_idx);
            break;
        }
        ouija_message[char_idx] = message[char_idx];
    }
    printf("setting idx %d to 0\n", char_idx);
    ouija_message[char_idx] == 0;
    return 0;
}

static int current_char_idx = -1;
static int current_step = 0;
static int direction = 1;

typedef enum {
    OUIJA_STATE_OFF,
    OUIJA_STATE_FADE_IN,
    OUIJA_STATE_ON,
    OUIJA_STATE_FADE_OUT,
} ouija_state_t;

typedef struct 
{
    char c;
    uint8_t pin;
} char_pin_map_t;

//static uint8_t gpio_table[] = {21,19,18,05,04,25,26,23,22,14,32,15,33,27,12,13}; 
char_pin_map_t char_pin_mapping[] = 
{
    {'n', 14},
    {'i', 32},
    {'t', 15},
    {'s', 33},
    {'r', 27},
    {'g', 12},
    {'f', 13},
    {'e', 21},
};

#define NUM_CHAR_PINS (sizeof(char_pin_mapping)/sizeof(char_pin_map_t))

static int char_to_pin(char c){
    int pin = -1;
    for(uint8_t idx = 0; idx < NUM_CHAR_PINS; idx++){
        if(char_pin_mapping[idx].c == c){
            pin = char_pin_mapping[idx].pin;
            break;
        }
    }
    return pin;
}

void ouija_loop(){
    static ouija_state_t state;
    static int fade_count = 8;
    static int current_pin = -1;
    static uint32_t current_fade = 0;
    char current_char;
    switch (state){
        case OUIJA_STATE_OFF:
            current_char_idx++;
            current_char = ouija_message[current_char_idx];
            if(current_char == 0){
                current_char_idx = -1;
                break;
            }
            current_pin = char_to_pin(current_char);
            if(current_pin == -1){
                break;
            }
            // printf("state: fading in %c\n", current_char);
            state = OUIJA_STATE_FADE_IN;
        case OUIJA_STATE_FADE_IN:
            fade_count++;
            // analogWriteFrequency(FADE_FREQ_STEP*fade_count);
            // analogWrite(current_pin, 8);
            analogWrite(current_pin, fade_count);
            if(fade_count == OUIJA_FADE_STEPS){
                printf("state: on\n");
                delayMicroseconds(OUIJA_CHAR_ON_TIME_US);
                // printf("Driving PWM %02d. hit enter when done\n", current_pin);
                // while(Serial.available() == 0){
                //     delay(100);
                // }
                while(Serial.available() != 0){
                    char x = Serial.read();
                }
                state = OUIJA_STATE_FADE_OUT;
                break;
            }
            delayMicroseconds(OUIJA_FADE_STEP_TIME_US);
            // printf("state: fading off\n");
        break;
        case OUIJA_STATE_ON:
        break;
        case OUIJA_STATE_FADE_OUT:
            fade_count--;
            if(fade_count == 0){
                analogWrite(current_pin, 0);
                // printf("state: off\n");
                state = OUIJA_STATE_OFF;
                break;
            }
            // analogWriteFrequency(FADE_FREQ_STEP*fade_count);
            // analogWrite(current_pin, 8);
            analogWrite(current_pin, fade_count);
            delayMicroseconds(OUIJA_FADE_STEP_TIME_US);
        break;
        default:
        printf("Error: unhandled ouija state: %02X", state);
    }

    // static int idx = 0;
    // int ret;
    // char c;
    // uint8_t pin = gpio_table[idx];
    // uint8_t pin_off = idx == 0 ? gpio_table[sizeof(gpio_table) -1] : gpio_table[idx -1];
    // analogWrite(pin_off, 0);
    // printf("wrote %02d off\n", pin_off);

    // ret = analogWrite(pin, 8);
    
    // printf("Driving PWM %02d. hit enter when done\n", pin);
    // while(Serial.available() == 0){
    //     delay(100);
    // }
    // while(Serial.available() != 0){
    //     char x = Serial.read();
    // }
    // if(++idx == sizeof(gpio_table)){
    //     idx = 0;
    // }
}

