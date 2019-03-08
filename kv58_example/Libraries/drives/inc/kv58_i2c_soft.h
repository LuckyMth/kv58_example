
#ifndef _I2C_SOFT_h
#define _I2C_SOFT_h


#include "kv58_gpio.h"
#include "kv58_port.h"


#define IIC_SCL    PTD0 //定义SCL引脚  可任意更改为其他IO
#define IIC_SDA    PTD1 //定义SDA引脚  可任意更改为其他IO

typedef enum IIC    //DAC模块
{
    IIC,
    SCCB
} IIC_type;

void  IIC_start(void);
void  IIC_stop(void);
void  IIC_ack_main(uint8_t ack_main);
void  send_ch(uint8_t c);
uint8_t read_ch(uint8_t ack);
void  simiic_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat);
uint8_t simiic_read_reg(uint8_t dev_add, uint8_t reg, IIC_type type);
void simiic_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num, IIC_type type);
void  IIC_init(void);


#endif

