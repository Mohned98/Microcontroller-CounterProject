#include "lcd.h"

/**
  * @brief This function used to send command to data pins (DB0-DB7). 
  * @param command specifies the command to be sent.
  * @retval None
  */
	
void LCD_displayCharacter(uint8 data)
{
	DIO_WritePort(LCD_CTRL_PORT,1<<RS,STD_HIGH);
	DIO_WritePort(LCD_CTRL_PORT,1<<RW,STD_LOW);
	SysTick_delay_ms(1);
	DIO_WritePort(LCD_CTRL_PORT,1<<E,STD_HIGH);
	SysTick_delay_ms(1);
	DIO_WritePort(LCD_DATA_PORT,data,STD_HIGH);
	SysTick_delay_ms(1);
	DIO_WritePort(LCD_CTRL_PORT,1<<E,STD_LOW);
	SysTick_delay_ms(1);
}