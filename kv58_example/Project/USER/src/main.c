
#include "headfile.h"

int main(void)
{
    pll_init();

    IIC_init();
    OLED_Init();

    OLED_Picture();
}



