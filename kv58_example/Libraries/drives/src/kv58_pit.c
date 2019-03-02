
#include "kv58_pit.h"
#include "kv58_gpio.h"
#include "kv58_clock.h"
#include "kv58_ftm.h"
#include "kv58_uart.h"

void pit_delay(PITn_e pitn,uint32_t count)
{
    /* Enable the module */
    SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
    /* Enable the clock */
    PIT->MCR &= ~(PIT_MCR_MDIS_MASK);
    /* Set timer period */
    PIT->CHANNEL[pitn].LDVAL = bus_clk_khz * count;
    /* Start pit */
    PIT->CHANNEL[pitn].TCTRL |= PIT_TCTRL_TEN_MASK;
    /* Wait for time */
    while(!(PIT->CHANNEL[pitn].TFLG & PIT_TFLG_TIF_MASK));
    /* Clear Interrupt Flag */
    pit_flag_clr(pitn);
}

void pit_init(PITn_e pitn,uint32_t count)
{
    /* Enable the module */
    SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
    /* Enable the clock */
    PIT->MCR &= ~(PIT_MCR_MDIS_MASK);
    /* Set timer period */
    PIT->CHANNEL[pitn].LDVAL = 23750 * count;
    /* Enable timer interrupts */
    PIT->CHANNEL[pitn].TCTRL |= PIT_TCTRL_TIE_MASK;
    /* Enable at the NVIC */
    NVIC_EnableIRQ(((IRQn_Type)(1 * PIT0_IRQn + pitn)));
    /* Start pit */
    PIT->CHANNEL[pitn].TCTRL |= PIT_TCTRL_TEN_MASK;
}

void PIT0_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    pit_flag_clr(pit0);
    /* for user */
}
