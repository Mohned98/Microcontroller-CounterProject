#ifndef DIO_H_
#define DIO_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "tm4c123gh6pm.h"

typedef enum
	{
		STD_LOW,
		STD_HIGH
  }Dio_LevelType;

	/*Functions prototypes*/
	uint8 DIO_ReadPort( uint8 port_index, uint8 pins_mask );
	void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level);
	void DIO_FlipPort(uint8 port_index, uint8 pins_mask);
	

#endif