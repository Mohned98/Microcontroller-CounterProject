#include "DIO.h"
/**
  * @brief This function is used to read pins value using port_index (0 to 5) 
  *        indicating ports from portA to portF.
  * @param port_index specifies the port that will be read.
  * @retval value of pins selected by pins_mask.
  */
uint8 DIO_ReadPort( uint8 port_index, uint8 pins_mask )
{ 
	switch(port_index)
	{	case 0:
			pins_level=GPIO_PORTA_DATA_R & pins_mask;
			break;
		case 1:
			pins_level=GPIO_PORTB_DATA_R & pins_mask;
			break;
		case 2:
			pins_level=GPIO_PORTC_DATA_R & pins_mask;
			break;
		case 3:
			pins_level=GPIO_PORTD_DATA_R & pins_mask;
			break;
		case 4:
			pins_level=GPIO_PORTE_DATA_R & pins_mask;
			break;
		case 5:
			pins_level=GPIO_PORTF_DATA_R & pins_mask;
			break;
	}
	return pins_level;
}