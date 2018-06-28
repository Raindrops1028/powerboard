#ifndef __SENSORS_H
#define __SENSORS_H

#include <stdint.h>
typedef enum dev_type
{
	BODY_SEN = 0x0,
	TOUCH_SEN
}DEV_TYPE;
#pragma pack(1) 
typedef struct
{
	uint8_t head;
	uint8_t length;
	uint8_t device_type;
	uint16_t sensors_status;
	uint8_t checksum;
	uint8_t tail;
}sensors_report_struct;
#pragma pack()

uint16_t read_sensor_status(DEV_TYPE dev_type);
void update_sensors_data(void);
uint8_t checksum(uint8_t *pdate, int size);
#endif
