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
	Port_SetPinDirection(LCD_CTRL_PORT, 1<<E, PORT_PIN_OUT );

	Port_Init(LCD_DATA_PORT); // port B 
	Port_SetPinDirection(LCD_DATA_PORT, 0xFF, PORT_PIN_OUT );
	
	
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);   //8-bits data 
	LCD_sendCommand(SET_CURSOR_LOCATION);           // start from the beginning of the first line
	LCD_sendCommand(CURSOR_OFF);                		//cursor blinking command
	LCD_sendCommand(CLEAR_COMMAND);                 //clear command
	
}


