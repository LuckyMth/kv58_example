
#include "kv58_systick.h"

void systick_delay(uint32_t time)
{
    if(time == 0)   return;

    SysTick->CTRL = 0x00;//先关了 systick ,清标志位
    SysTick->LOAD = time;//设置延时时间
    SysTick->VAL = 0x00;//清空计数器
    SysTick->CTRL = ( 0 | SysTick_CTRL_ENABLE_Msk     //使能 systick
                  //| SysTick_CTRL_TICKINT_Msk        //使能中断 (注释了表示关闭中断)
                    | SysTick_CTRL_CLKSOURCE_Msk      //时钟源选择 (core clk)
                );
    while( !(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));//等待时间到
}


void systick_delay_ms(uint32_t ms)
{
	while(ms--)
    {
        systick_delay(system_clk_khz);
    }
}


void systick_delay_us(uint32_t us)
{
	while(us--)
    {
        systick_delay((uint32_t)(system_clk_khz/1000));
    }
}
