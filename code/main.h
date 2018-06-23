#include "registers.h"
#include <stdint.h>
#include <time.h>

// PC13 connected to display's RCLK pin
// PC14 connected to display's SCLK pin
// PC15 connected to display's DIO pin
enum port_c {PC13 = 0x2000, PC14 = 0x4000, PC15 = 0x8000};
enum digit {DIG_1 = 0x10, DIG_2 = 0x20, DIG_3 = 0x40, DIG_4 = 0x80};
enum segment {SEG_1 = 0x7f, SEG_2 = 0xbf, SEG_3 = 0xdf, SEG_4 = 0xef, SEG_5 = 0xf7, SEG_6 = 0xfb, SEG_7 = 0xfd, SEG_DOT = 0xfe};

void gpio_port_c_rcc_init(void);
void init(void);
void display(void);
void send_data(enum digit to_digit, uint8_t value);
void delay(void);
void show_changes(void);