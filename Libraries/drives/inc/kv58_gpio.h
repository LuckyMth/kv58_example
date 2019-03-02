#ifndef _GPIO_H_
#define _GPIO_H_

#include "MKV58F24.h"
#include "kv58_port.h"

typedef enum _gpio_direction
{
    gpi = 0U,  /*!< Set current pin as digital input*/
    gpo = 1U, /*!< Set current pin as digital output*/
} gpio_direction_t;

extern void gpio_init(PTXn_e ptxn, gpio_direction_t direction, uint8_t outputLogic);
extern void gpio_set(PTXn_e ptxn, uint8_t output);
extern void gpio_turn(PTXn_e ptxn);
extern void gpio_ddr(PTXn_e ptxn, gpio_direction_t direction);
extern uint8_t gpio_get(PTXn_e ptxn);


#endif
