#ifndef _KV58_LED_H_
#define _KV58_LED_H_

#include "MKV58F24.h"
#include "kv58_gpio.h"

typedef enum _led
{
    led1 = 1,
    led2 = 2,
    led3 = 3,
    led4 = 4,
    led_all = 5,
}led_t;


extern void led_init(led_t led);
extern void led_set(led_t led, uint8_t output);


#endif
