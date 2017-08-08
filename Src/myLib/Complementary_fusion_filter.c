#include "Complementary_fusion_filter.h"
#include "usart.h"
#include "mpu6050_filter.h"

Real_Angle_struct Real_Angle;



void Complementary_Fusion_Filter(void)
{
	Real_Angle.Real_Angle_x = (Real_Angle.Real_Angle_x + sensor.gyro.averag.x * 0.008f) * 0.88f + sensor.acc.averag.x * 0.12f;
    Real_Angle.Real_Angle_y = (Real_Angle.Real_Angle_y + sensor.gyro.averag.y * 0.008f) * 0.88f + sensor.acc.averag.y * 0.12f;
	
    //Angle_send_data(Real_Angle.Real_Angle_x, Real_Angle.Real_Angle_y);
}

void Angle_send_data(short Real_Angle_x, short Real_Angle_y)
{
	uint8_t tbuf[4]; 
	tbuf[0]=(Real_Angle_x>>8)&0XFF;
	tbuf[1]=Real_Angle_x&0XFF; 
	tbuf[2]=(Real_Angle_y>>8)&0XFF;
	tbuf[3]=Real_Angle_y&0XFF;
	usart3_niming_report(0XA2,tbuf,4);
}	

