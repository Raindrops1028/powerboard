#include "color_bar.h"

extern TIM_HandleTypeDef htim3,htim4;

void pwm_set_pulse(TIM_OC_InitTypeDef *sConfigOC, uint16_t pulse_val)
{
    sConfigOC->OCMode = TIM_OCMODE_PWM1; 
    sConfigOC->OCPolarity = TIM_OCPOLARITY_HIGH; 
    sConfigOC->OCFastMode = TIM_OCFAST_DISABLE;
    sConfigOC->Pulse = pulse_val; 		
}

void red_pwm_value(uint16_t r_val) 
{ 	
	  TIM_OC_InitTypeDef sConfigOC; 
		pwm_set_pulse(&sConfigOC,r_val);
	  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);	
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); 	
}
void green_pwm_value(uint16_t g_val) 
{ 	
	  TIM_OC_InitTypeDef sConfigOC; 
		pwm_set_pulse(&sConfigOC,g_val);
	  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);		
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);  	
}
void blude_pwm_value(uint16_t b_val) 
{ 	
	  TIM_OC_InitTypeDef sConfigOC; 
		pwm_set_pulse(&sConfigOC,b_val);
	  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);		
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
void all_pwm_value(RGB rgb) 
{ 	
    TIM_OC_InitTypeDef sConfigOC; 
		pwm_set_pulse(&sConfigOC,rgb.b_val);
	  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);;
		pwm_set_pulse(&sConfigOC,rgb.r_val);	
    HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
		pwm_set_pulse(&sConfigOC,rgb.g_val);
		HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3); 
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);  	
}

void breath_blue_led(void)
{  
	#define MAX  9000U
	#define MIN  10U
	#define ACC  6U
	#define DEC  -4
	static int16_t pwm_value = 0,step = 0;
	
	if(pwm_value > MAX) step = DEC;
	if(pwm_value < MIN) step = ACC;

	pwm_value += step;
	blude_pwm_value(pwm_value) ;		
}

void red_led(void)
{
	red_pwm_value(9999);
}

void green_led(void)
{
	green_pwm_value(9999);
}


void blue_led(void)
{
	blude_pwm_value(9999);	
}


void bottom_led(led_color led_cl)
{
	switch(led_cl)
	{
		case red:red_led();break;
		case green:green_led();break;
		case blue:blue_led();break;
		default:break;
	}
}  

void running_leds(void)
{
	static uint8_t color = 0;
	
	switch(color%3)
	{
		case blue:
			blue_led();		
			break;
		case red:
			red_led();						
			break;
		case green:
			green_led();						
			break;
		default:break;
	}
	color++;	
}

