#include "tm4c123gh6pm.h"
#include "STANDARD_TYPES.h"
#include "MACROS.h"
#include "DIO.h"


void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level){
	
		switch(port_index){
			case 0:
				if(pins_level == STD_HIGH)
					GPIO_PORTA_DATA_R |= pins_mask;
				else
					GPIO_PORTA_DATA_R &= ~(pins_mask);
			break;
			case 1:
				if(pins_level == STD_HIGH)
					GPIO_PORTB_DATA_R |= pins_mask;
				else
					GPIO_PORTB_DATA_R &= ~(pins_mask);
			break;
			case 2:
				if(pins_level == STD_HIGH)
					GPIO_PORTC_DATA_R |= pins_mask;
				else
					GPIO_PORTC_DATA_R &= ~(pins_mask);
			break;
			case 3:
				if(pins_level == STD_HIGH)
					GPIO_PORTD_DATA_R |= pins_mask;
				else
					GPIO_PORTD_DATA_R &= ~(pins_mask);
			break;
			case 4:
				if(pins_level == STD_HIGH)
					GPIO_PORTE_DATA_R |= pins_mask;
				else
					GPIO_PORTE_DATA_R &= ~(pins_mask);
			break;
			case 5:
				if(pins_level == STD_HIGH)
					GPIO_PORTF_DATA_R |= pins_mask;
				else
					GPIO_PORTF_DATA_R &= ~(pins_mask);
			break;
		}
}