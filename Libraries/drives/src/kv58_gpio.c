
#include "kv58_gpio.h"

static GPIO_Type * const GPIOx[] = GPIO_BASE_PTRS;

void gpio_init(PTXn_e ptxn, gpio_direction_t direction, uint8_t output)
{
    //复用为GPIO
    port_init(ptxn,AsGpio);
    
    if(gpi == direction)
    {
        GPIOx[PTX(ptxn)]->PDDR &= ~(1U << PTn(ptxn));
    }
    else if(gpo == direction)
    {
        GPIOx[PTX(ptxn)]->PDDR |= (1U << PTn(ptxn));
        if(0 == output)
        {
            GPIOx[PTX(ptxn)]->PCOR = 1U << PTn(ptxn);
        }
        else if(1 == output)
        {
            GPIOx[PTX(ptxn)]->PSOR = 1U << PTn(ptxn);
        }
    }
}

void gpio_set(PTXn_e ptxn, uint8_t output)
{
    if(0 == output)
    {
        GPIOx[PTX(ptxn)]->PCOR = 1U << PTn(ptxn);
    }
    else if(1 == output)
    {
        GPIOx[PTX(ptxn)]->PSOR = 1U << PTn(ptxn);
    }
}

void gpio_turn(PTXn_e ptxn)
{
    GPIOx[PTX(ptxn)]->PTOR = 1U << PTn(ptxn);
}

void gpio_ddr(PTXn_e ptxn, gpio_direction_t direction)
{
    if(gpi == direction)
    {
        GPIOx[PTX(ptxn)]->PDDR &= ~(1U << PTn(ptxn));
    }
    else if(gpo == direction)
    {
        GPIOx[PTX(ptxn)]->PDDR |= (1U << PTn(ptxn));
    }
}


uint8_t gpio_get(PTXn_e ptxn)
{
    return ((GPIOx[PTX(ptxn)]->PDIR >> PTn(ptxn)) & 0x01);
}

