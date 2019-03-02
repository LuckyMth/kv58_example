
#include "headfile.h"

int main(void)
{
    pll_init();
    
    gpio_init(PTD15,gpo,0);
    
    while(1)
    {
        pit_delay_ms(pit0,1000);
        gpio_set(PTD15,0);
        pit_delay_ms(pit0,1000);
        gpio_set(PTD15,1);
    }
}









