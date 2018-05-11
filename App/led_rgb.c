#include "led_rgb.h"

extern TIM_HandleTypeDef htim3,htim4;

uint8_t breath_start = 0;

void user_pwm_setvalue(RGB rgb) 
{ 	
    TIM_OC_InitTypeDef sConfigOC; 
    sConfigOC.OCMode = TIM_OCMODE_PWM1; 
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH; 
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    sConfigOC.Pulse = rgb.b_val; 	
    HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
    sConfigOC.Pulse = rgb.r_val; 	
    HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
    sConfigOC.Pulse = rgb.g_val; 	
		HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3); 
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);  	
}

void breath_leds(void)
{
	#define MAX  8000U
	#define MIN  1000U
	#define ACC  12U
	#define DEC  -8
	RGB rgb;
	static int16_t pwm_value = 0,step = 0;
	
	rgb.r_val = 0;
	rgb.g_val = 0;
	rgb.b_val = 0;
	
	if(pwm_value > MAX) step = DEC;
	if(pwm_value < MIN) step = ACC;

	pwm_value += step;
	
	rgb.b_val = pwm_value;
	user_pwm_setvalue(rgb);		
}

enum  color_table {bule,red,green,yellow,orange,purple,white};

void red_led(void)
{
	RGB rgb;
	rgb.r_val = 9999;
	rgb.g_val = 0;
	rgb.b_val = 0;
	user_pwm_setvalue(rgb);	
}

void green_led(void)
{
	RGB rgb;
	rgb.r_val = 0;
	rgb.g_val = 9999;
	rgb.b_val = 0;
	user_pwm_setvalue(rgb);	
}

void blud_led(void)
{
	RGB rgb;
	rgb.r_val = 0;
	rgb.g_val = 0;
	rgb.b_val = 9999;
	user_pwm_setvalue(rgb);	
}

void conver_leds(void)
{
	RGB rgb;
	static uint8_t color = 0;
	
	switch(color%7)
	{
		case bule:
			rgb.r_val = 9999;
			rgb.g_val = 0;
			rgb.b_val = 0;			
			break;
		case red:
			rgb.r_val = 0;
			rgb.g_val = 9999;
			rgb.b_val = 0;					
			break;
		case green:
			rgb.r_val = 0;
			rgb.g_val = 0;
			rgb.b_val = 9999;					
			break;
		case yellow:
			rgb.r_val = 9999;
			rgb.g_val = 0;
			rgb.b_val = 9999;					
			break;
		case orange:
			rgb.r_val = 0;
			rgb.g_val = 9999;
			rgb.b_val = 9999;					
			break;
		case purple:
			rgb.r_val = 9999;
			rgb.g_val = 9999;
			rgb.b_val = 0;					
			break;
		case white:
			rgb.r_val = 9999;
			rgb.g_val = 9999;
			rgb.b_val = 9999;					
			break;
		default:break;
	}
	user_pwm_setvalue(rgb);
	color++;	
}




void mode_command(uint8_t cmd)
{
	switch(cmd)
	{
		case 0x00:breath_start = 0;red_led();break;
		case 0x01:breath_start = 0;green_led();break;
		case 0x02:breath_start = 0;blud_led();break;
		case 0x03:breath_start = 1;break;
		default:break;
	}
}
/**
  * @brief  Period elapsed callback in non blocking mode 
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{	
  if(htim->Instance == htim4.Instance)
	{
		static uint16_t time_cnt = 0;
		time_cnt++;
		if(time_cnt%1000 == 0)
			HAL_GPIO_TogglePin(GPIOB, PWR_LED_Pin);
		if(breath_start)
		{
			breath_leds();
		}
	}
}
