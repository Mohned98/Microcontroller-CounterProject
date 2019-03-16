#include "lcd.h"

 
/**
  * @brief This function Initialize the LCD based on port A for control and port B for command /data .
  * @param No parameters required
  * @retval None
  */

void LCD_init(void){

	Port_Init(LCD_CTRL_PORT); //port A 
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<RS, PORT_PIN_OUT );
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<RW, PORT_PIN_OUT );
	SysTick_delay_ms(1);
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<E, PORT_PIN_OUT );

	Port_Init(LCD_DATA_PORT); // port B 
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<RS, PORT_PIN_OUT );
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<RW, PORT_PIN_OUT );
	SysTick_delay_ms(1);
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<E, PORT_PIN_OUT );
	
	
	LCD_sendCommand(WAKEUP_COMMAND);                //wakeup command
	//delay();
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);   //8-bits data 
	//delay();
	LCD_sendCommand(SET_CURSOR_LOCATION);           // start from the beginning of the first line
	//delay();
	LCD_sendCommand(CURSOR_BLINKING);               //cursor blinking command
	//delay();
	
	
}