#include "button.h"


void Button_Init( uint8 port_index, uint8 pins_mask, InputMode mode ){
	
	Port_Init( port_index );
	Port_SetPinDirection( port_index, pins_mask, PORT_PIN_IN );
	
	if(mode == PULL_DOWN) {
			
		Port_SetPinPullDown( port_index, pins_mask, 1);
	
	}
	
	
	else{

		Port_SetPinPullUp(port_index,  pins_mask, 1);
		}	

	
}
