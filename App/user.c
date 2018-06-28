#include "user.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
#include "usart.h"
#include "sensors.h"
#include "color_bar.h"
#include "ws2813b.h"

uint8_t RxBuffer_temp,RxBuffer[7];
uint16_t sensors_init_status = 0x0;

void user_board_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);

	HAL_UART_Receive_IT(&huart1,&RxBuffer_temp, 1);
	HAL_GPIO_WritePin(GPIOB,BOTTOM_LED_EN_Pin, GPIO_PIN_SET);
	bottom_led(blue);
	front_led(blue);
	HAL_Delay(3000);
	sensors_init_status = read_sensor_status(TOUCH_SEN);
	HAL_GPIO_WritePin(GPIOA,SPK_EN_Pin, GPIO_PIN_SET);	
	HAL_Delay(12000);
}

void user_progress(void)
{
	update_sensors_data();
	HAL_Delay(500);
}

uint8_t breath_start = 0;
void mode_command(uint8_t cmd)
{
	switch(cmd)
	{
		case 0x00:breath_start = 0;bottom_led(red);	front_led(red);break;
		case 0x01:breath_start = 0;bottom_led(green);front_led(green);break;
		case 0x02:breath_start = 0;bottom_led(blue);front_led(blue);break;
		case 0x03:breath_start = 1;break;
		default:break;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{
		static uint8_t cnt = 0;
		uint8_t temp = RxBuffer_temp;
		if(cnt == 0){
			if(temp == 0xaa){
				RxBuffer[cnt++]  = 0xaa;
			}	
		}
		else{
			if(cnt < 7){
				RxBuffer[cnt++] = temp;
				if(0xdd == temp && cnt == 7){	
					mode_command(RxBuffer[4]);
				}
				if(cnt == 7) cnt = 0;
			}
			else cnt = 0;	
		}		
//		static uint8_t cnt = 0;
//		uint8_t temp = RxBuffer_temp;
//		if(cnt == 0){
//			if(temp == 0xaa){
//				RxBuffer[cnt++]  = 0xaa;
//			}	
//		}
//		else if(cnt == 5)/*judge checksum*/
//		{
//			RxBuffer[5] = checksum((uint8_t *)RxBuffer,sizeof(RxBuffer)- 2);
//			if(RxBuffer[5] != temp) cnt = 0;
//			else RxBuffer[cnt++] =  temp;
//		}		
//		else if(cnt == 6)
//		{
//			if(0xdd == temp) 
//			{
//				RxBuffer[cnt++] =  temp;
//				mode_command(RxBuffer[4]);
//			}
//			else cnt = 0;		
//		}
//		else
//		{
//			if(cnt < 7)
//			RxBuffer[cnt++] = temp;
//			else cnt = 0;
//		}
		
		HAL_UART_Receive_IT(&huart1, &RxBuffer_temp, 1);		
	}	
}

/**
  * @brief  Period elapsed callback in non blocking mode 
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)/*called per 1ms*/
{	
  if(htim->Instance == htim4.Instance)
	{
		static uint16_t time_cnt = 0;
		time_cnt++;
		if(time_cnt%1000 == 0)/*per 1s*/
			HAL_GPIO_TogglePin(GPIOB, PWR_LED_Pin);
		if(breath_start&&time_cnt%10)/*per 10ms*/
		{
			breath_blue_led();
		}
	}
}
