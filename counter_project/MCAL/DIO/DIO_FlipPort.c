#include "DIO.h"
/**
  * @brief This function is used to toggle the values of the pins selected 
	*        by pins_masks in the port selected by port_index
  * @param port_index specifies the port that will be toggled.
	*				 pins_mask specifies thepin that willbe toggled in the selected port
  * 
  */
void DIO_FlipPort( uint8 port_index, uint8 pins_mask )
{ 
	switch(port_index)
	{	case 0:
			GPIO_PORTA_DATA_R =(GPIO_PORTA_DATA_R ^ pins_mask);
			break;
		case 1:
			GPIO_PORTB_DATA_R =(GPIO_PORTB_DATA_R ^ pins_mask);
			break;
		case 2:
			GPIO_PORTC_DATA_R =(GPIO_PORTC_DATA_R ^ pins_mask);
			break;
		case 3:
			GPIO_PORTD_DATA_R =(GPIO_PORTD_DATA_R ^ pins_mask);
			break;
		case 4:
			GPIO_PORTE_DATA_R =(GPIO_PORTE_DATA_R ^ pins_mask);
			break;
		case 5:
			GPIO_PORTF_DATA_R =(GPIO_PORTF_DATA_R ^ pins_mask);
			break;
	}
}