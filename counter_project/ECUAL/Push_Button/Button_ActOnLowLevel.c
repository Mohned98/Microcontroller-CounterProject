#include "button.h"
/**
  * @brief This function used to take action while button is on low level state.
  * @param port_index specifies the number of port that the button is on,
	* @param pin_Number specifies pin number of the button,
	* @param pAction is a pointer to function that contains action to be done
  * @retval None
  */
void Button_ActOnLowLevel( uint8 port_index, uint8 pin_Number, void (*pAction)(void) )
{
if(DIO_ReadPort(port_index,~(1<<pin_Number) ))
	{
		SysTick_delay_ms(30);
		if(DIO_ReadPort(port_index,~(1<<pin_Number) ))
		{
			while(DIO_ReadPort(port_index,~(1<<pin_Number) ))
			{
				pAction();
				SysTick_delay_ms(200);
			}
		}
	}
}
