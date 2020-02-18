/*
 * MOTOR2.c
 *
 * Created: 18/02/2020 01:35:31 م
 *  Author: mo
 */


#include "Motor.h"

int main(void)
{
Motor_Init(MOTOR_1|MOTOR_2);
    while(1)
    {
      Motor_Start(MOTOR_1|MOTOR_2,20);
        //TODO:: Please write your application code
    }
}
