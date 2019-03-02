#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "MKV58F24.h"
#include "kv58_clock.h"

extern void systick_delay(uint32_t time);
extern void systick_delay_ms(uint32_t ms);

#endif
