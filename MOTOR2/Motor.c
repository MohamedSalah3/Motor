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

          case ALL_MOTOR:
			       {
				/*Enable PWM Bit...output*/
				/*IN1*/
      	/*IN2*/
				/*ENABLE PWM BIT FOR MOTOR 2*/
				/*IN3*/
      	/*IN4*/
        Ret=Pwm_Init(&PWM_Configuration_1A);
        Ret=Pwm_Init(&PWM_Configuration_1B);
        Ret=DIO_init(&ALL_Motor);
				break;
			   }
      default:
      Ret=E_NOK;
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
  			Ret=DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
  			Ret=DIO_Write (MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);

  			break;
  		}
  		case MOTOR_BACKWARD:
  		{
  		Ret=DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
        Ret=DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);

  			break;
  		}
  		case MOTOR_STOP:{Ret=DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
  		Ret=DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
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
  				Ret=DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
          Ret=DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);

  				break;
  			}
  			case MOTOR_BACKWARD:
  			{
  				Ret=DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
  			Ret=DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
  				break;
  			}
  			case MOTOR_STOP:
  			{
  				Ret=DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
  				Ret=DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
  				break;
  			}

  		}

  		break;
  	}
  	case ALL_MOTOR:
  	{
  switch(Motor_Direction)
  {
  	case MOTOR_FORWARD:
  	{
  		Ret=DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
  		Ret=DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);

  	Ret=DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
  		Ret=DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);

  		break;
  	}
  	case MOTOR_BACKWARD:
  	{

  		Ret=DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
      Ret=DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
  		Ret=DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
  		Ret=DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);

  		break;	}
  	case MOTOR_STOP:
  	{
  			Ret=DIO_Write(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
  			Ret=DIO_Write(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);

  			Ret=DIO_Write(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
  			Ret=DIO_Write(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);

  		break;
  	}
    default:
    Ret=E_NOK;
    break;
  	}

    }
  	break;



    }
return Ret;
}


ERROR_STATUS Motor_Start(uint8_t Motor_Number, uint8_t Mot_Speed)
{
switch (Motor_Number) {
  case MOTOR_1:
  {
    Ret=Pwm_Start(PWM_CH1A,Mot_Speed,30)
    break;
  }
}



}
