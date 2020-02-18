/*
 * Motor.c
 *
 * Created: 18/02/2020 01:38:30 م
 *  Author: mo
 */
#include "motor.h"



ERROR_STATUS Motor_Init(uint8_t Motor_Number)
{uint8_t Ret=0;


    switch(Motor_Number)
    {
        case MOTOR_1:
        /*Enable PWM Bit...output*/
        /*IN1*/
        /*IN2*/
			Ret=Pwm_Init(&PWM_Configuration_1A);
			Ret=DIO_init(&Motorone);

			  break;

          case MOTOR_2:
		      Ret=Pwm_Init(&PWM_Configuration_1B);
          Ret=DIO_init(&Motortwo);
          break;
    }


return Ret;
}
