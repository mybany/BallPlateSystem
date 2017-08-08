#ifndef __COMPLEMENTARY_FUSION_FILTER_H
#define __COMPLEMENTARY_FUSION_FILTER_H

#include "stm32f7xx_hal.h"
#include "mpu6050_filter.h"

typedef struct
{
    float Real_Angle_x;
    float Real_Angle_y;
}Real_Angle_struct;


void Complementary_Fusion_Filter(void);
void Angle_send_data(short Real_Angle_x, short Real_Angle_y);




#endif

