
#include "headfile.h"

int main(void)
{
    pll_init();

    IIC_init();
    InitMPU6050();

    //在线调试查看mpu_gyro_x mpu_gyro_y mpu_gyro_z mpu_acc_x mpu_acc_y mpu_acc_z三个变量即可
    for(;;)
    {
        //采集MPU6050数据
        Get_Gyro();
        Get_AccData();
        
        printf("mpu_gyro_x=%d\n",mpu_gyro_x);
        printf("mpu_gyro_y=%d\n",mpu_gyro_y);
        printf("mpu_gyro_z=%d\n\n",mpu_gyro_z);
        
        printf("mpu_acc_x=%d\n",mpu_acc_x);
        printf("mpu_acc_y=%d\n",mpu_acc_y);
        printf("mpu_acc_z=%d\n\n",mpu_acc_z);
        
        systick_delay_ms(30);//延时30ms

    }
    
    
}









