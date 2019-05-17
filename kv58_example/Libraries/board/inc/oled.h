#ifndef _OLED_H_
#define _OLED_H_

#include "MKV58F24.h"

#define OLED_DEV_ADDR   0x78>>1
#define OLED_COMMAND    0x80
#define OLED_DATA       0xc0


extern void OLED_Init(void);
extern void OLED_Fill(uint8_t bmp_data);
extern void OLED_P8x16Str(uint8_t x,uint8_t y,uint8_t ch[]);
extern void OLED_P8x16Num(uint8_t x,uint8_t y,int32_t num);
extern void OLED_Picture();


#endif
