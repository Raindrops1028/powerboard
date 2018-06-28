#include "sensors.h"
#include "stm32f1xx_hal.h"

extern UART_HandleTypeDef huart1;

sensors_report_struct body_sensor;
sensors_report_struct touch_sensor;

uint8_t checksum(uint8_t *pdate, int size)  
{  
    uint8_t sum=0;  
    while (size>1)  
    {     
        sum += *pdate;  
        pdate++;  
        size--;  
    }     
      
    if (size)  
        sum += *(uint8_t*)pdate;  
    return sum;  
}


#define SET_BIT_STATUS(status,dev_id) ((((status) == 1) ?  1 : 0) << (dev_id - 1))

uint16_t read_sensor_status(DEV_TYPE dev_type)
{
	uint16_t status = 0;
	switch(dev_type)
	{
		case BODY_SEN:
			status = SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOA,BODY_DET_Pin),1);		
			break;
		case TOUCH_SEN:
			status  = SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOA,TOUCH_DET_1_Pin),1);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOC,TOUCH_DET_2_Pin),2);		
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOC,TOUCH_DET_3_Pin),3);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOC,TOUCH_DET_4_Pin),4);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOB,TOUCH_DET_5_Pin),5);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOB,TOUCH_DET_6_Pin),6);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOB,TOUCH_DET_7_Pin),7);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOB,TOUCH_DET_8_Pin),8);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOB,TOUCH_DET_9_Pin),9);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOA,TOUCH_DET_10_Pin),10);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOA,TOUCH_DET_11_Pin),11);
			status |= SET_BIT_STATUS(HAL_GPIO_ReadPin(GPIOA,TOUCH_DET_12_Pin),12);		
			break;		
		default:break;
	}
	return status;
}

uint16_t read_sensor_status_(DEV_TYPE dev_type)
{
	uint16_t status = 0;
	switch(dev_type)
	{
		case BODY_SEN:
			status = GPIOA->IDR&0x01;		
			break;
		case TOUCH_SEN:
			status = GPIOB->IDR&0xff;
			break;		
		default:break;
	}
	return status;	
}
extern uint16_t sensors_init_status;
void fill_report(sensors_report_struct * report, DEV_TYPE dev_type)
{
	report->head = 0xaa;
	report->device_type = dev_type;
	report->length = 0x07;
	if(dev_type == TOUCH_SEN)
	{
		report->sensors_status = read_sensor_status(dev_type);
		report->sensors_status &= ~sensors_init_status;
		HAL_GPIO_WritePin(GPIOB,TOUCH_DET_Pin, report->sensors_status ? GPIO_PIN_SET : GPIO_PIN_RESET);/*¿ØÖÆ´¥Ãþ×´Ì¬Ö¸Ê¾µÆ£¬µÆÁÁ´ú±íÓÐ´¥Ãþ*/
	}
	else report->sensors_status = read_sensor_status(dev_type);

	report->checksum = checksum((uint8_t *)report,sizeof(sensors_report_struct)- 2);	
	report->tail = 0xdd;
}


void scan_all_sensors(void)
{
	fill_report(&body_sensor,BODY_SEN);
	fill_report(&touch_sensor,TOUCH_SEN);
}

void update_sensors_data(void)
{
	scan_all_sensors();
	
	HAL_UART_Transmit_IT(&huart1,(uint8_t *)&body_sensor,sizeof(body_sensor));
	HAL_Delay(500);
	HAL_UART_Transmit_IT(&huart1,(uint8_t *)&touch_sensor,sizeof(touch_sensor));
}

