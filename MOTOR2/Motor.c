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

ERROR_STATUS Motor_Direction(uint8_t Motor_Number, uint8_t Motor_Direction)
{

  switch(Motor_Number)
  {
  	case MOT_1:{
  	switch(Motor_Direction)
  	{
  		case MOTOR_FORWARD:
  		{
  			DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
  			DIO_Write (MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);

  			break;
  		}
  		case MOTOR_BACKWARD:
  		{
  			DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
  			DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);

  			break;
  		}
  		case MOTOR_STOP:{DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
  		DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
  		break;}

  	}
  		break;
  	}
  	case MOTOR_2:
  	{
  		switch(Motor_Direction)
  		{
  			case MOTOR_FORWARD:
  			{
  				DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
  				DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);

  				break;
  			}
  			case MOTOR_BACKWARD:
  			{
  				DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
  				DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
  				break;
  			}
  			case MOTOR_STOP:
  			{
  				DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
  				DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
  				break;
  			}

  		}

  		break;
  	}
  	case ALLMOT:
  	{
  switch(en_motor_dir)
  {
  	case FORWARD:
  	{
  		gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
  		gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);

  		gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
  		gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);

  		break;
  	}
  	case BACKWARD:
  	{

  		gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
  		gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);

  		gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
  		gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);

  		break;	}
  	case STOP:
  	{
  			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
  			gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);

  			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
  			gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);

  		break;
  	}
  	}

  }
  	break;
  	}






}
