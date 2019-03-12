
#include "headfile.h"

int main(void)
{
  
    int32_t a = -2147483647;

    pll_init();

    IIC_init();
    OLED_Init();

    OLED_P8x16Num(0,0,a);
}



