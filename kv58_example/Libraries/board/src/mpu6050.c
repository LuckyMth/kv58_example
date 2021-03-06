
#include "mpu6050.h"
#include "kv58_i2c_soft.h"

int16_t mpu_gyro_x,mpu_gyro_y,mpu_gyro_z;
int16_t mpu_acc_x,mpu_acc_y,mpu_acc_z;

//-------------------------------------------------------------------------------------------------------------------
//  @brief      初始化MPU6050
//  @param      NULL
//  @return     void					
//  @since      v1.0
//  Sample usage:				调用该函数前，请先调用模拟IIC的初始化
//-------------------------------------------------------------------------------------------------------------------
void InitMPU6050(void)
{
    uint8_t aa = simiic_read_reg(MPU6050_DEV_ADDR,WHO_AM_I);
    
    simiic_write_reg(MPU6050_DEV_ADDR, PWR_MGMT_1, 0x00);	   //解除休眠状态
    simiic_write_reg(MPU6050_DEV_ADDR, SMPLRT_DIV, 0x07);      //125HZ采样率
    simiic_write_reg(MPU6050_DEV_ADDR, CONFIG, 0x04);          //
    simiic_write_reg(MPU6050_DEV_ADDR, GYRO_CONFIG, 0x18);     //2000
    simiic_write_reg(MPU6050_DEV_ADDR, ACCEL_CONFIG, 0x10);    //8g
	simiic_write_reg(MPU6050_DEV_ADDR, User_Control, 0x00);
    simiic_write_reg(MPU6050_DEV_ADDR, INT_PIN_CFG, 0x02);
    simiic_write_reg(MPU6050_DEV_ADDR, PWR_MGMT_1, 0x00);	   //解除休眠状态
}



//-------------------------------------------------------------------------------------------------------------------
//  @brief      获取MPU6050加速度计数据
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:				执行该函数后，直接查看对应的变量即可
//-------------------------------------------------------------------------------------------------------------------
void Get_AccData(void)
{
    uint8_t dat[6];
    
    simiic_read_regs(MPU6050_DEV_ADDR, ACCEL_XOUT_H, dat, 6);  
    mpu_acc_x = (int16_t)(((uint16_t)dat[0]<<8 | dat[1]));
    mpu_acc_y = (int16_t)(((uint16_t)dat[2]<<8 | dat[3]));
    mpu_acc_z = (int16_t)(((uint16_t)dat[4]<<8 | dat[5]));
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      获取MPU6050陀螺仪数据
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:				执行该函数后，直接查看对应的变量即可
//-------------------------------------------------------------------------------------------------------------------
void Get_Gyro(void)
{
    uint8_t dat[6];
    
    simiic_read_regs(MPU6050_DEV_ADDR, GYRO_XOUT_H, dat, 6);  
    mpu_gyro_x = (int16_t)(((uint16_t)dat[0]<<8 | dat[1]));
    mpu_gyro_y = (int16_t)(((uint16_t)dat[2]<<8 | dat[3]));
    mpu_gyro_z = (int16_t)(((uint16_t)dat[4]<<8 | dat[5]));
}


