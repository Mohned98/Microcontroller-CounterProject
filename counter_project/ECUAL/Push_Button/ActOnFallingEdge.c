#include "button.h"

void Button_ActOnFallingEdge( uint8 port_index, uint8 pin_Number, void (*pAction)(void) )
{
	bool first_read=0;
	bool second_read=0;
	bool switch_pressed=0;
	bool switch_released=0;
			if (DIO_ReadPort( port_index, (1<<pin_Number))){
				first_read=1;
				systick_delayms(50);
				if((DIO_ReadPort( port_index, (1<<pin_Number))==1))
					second_read=1;
				if(first_read&&second_read) switch_pressed=1;
				else switch_pressed=0;
			}
			
			else {
				first_read=0;
				systick_delayms(50);
				if((DIO_ReadPort( port_index, (1<<pin_Number))==0))
			`		second_read=0;
				if(!first_read&&!second_read&&switch_pressed) switch_released=1;
				else switch_released=0;
			}
			
			while(switch_released&&switch_pressed){
							pAction();
							SysTick_delay_ms(200);
			}
			

}
