#ifndef _KV58_I2C_SOFT_h
#define _KV58_I2C_SOFT_h

#include "MKV58F24.h"

#define I2C_SCL    PTD0 //定义SCL引脚  可任意更改为其他IO
#define I2C_SDA    PTD1 //定义SDA引脚  可任意更改为其他IO

extern void  IIC_start(void);
extern void  IIC_stop(void);
extern void  send_ch(uint8_t c);
extern uint8_t read_ch(uint8_t ack);
extern void  simiic_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat);
extern uint8_t simiic_read_reg(uint8_t dev_add, uint8_t reg);
extern void simiic_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num);
extern void  IIC_init(void);


#endif

