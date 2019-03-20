#include "port.h"
#include "DIO.h"
#include "SysTick.h"
#include "button.h"
#include "lcd.h"

#define BUTTONS_PORT 0
#define INCREMENT_BUTTON 2
#define DECREMENT_BUTTON 4
#define RESET_BUTTON 3
#define BUTTONS_MASK (1<<INCREMENT_BUTTON)|(1<<DECREMENT_BUTTON)|(1<<RESET_BUTTON)
uint32 count=0;

void Increment(void); /*Incrementation of the counter function*/
void Decrement(void); /*Decrementation of the counter function*/
void Reset(void); /*Reset of the counter function*/

	
int main(void)
{    SysTick_Init();
	/*Initialization of LCD & push buttons*/
	LCD_init();
	LCD_goToRowColumn(0,7);
	 Button_Init(BUTTONS_PORT,BUTTONS_MASK, PULL_DOWN);
		while(1) 
		{
		Button_ActOnHighLevel(BUTTONS_PORT,INCREMENT_BUTTON,Increment );
		Button_ActOnRisingEdge(BUTTONS_PORT, RESET_BUTTON, Decrement );
		Button_ActOnFallingEdge(BUTTONS_PORT, DECREMENT_BUTTON, Reset );
		}
	
}

/*Reset of the counter function*/
void Reset(void){
	count=0;
	LCD_clearScreen();
	LCD_goToRowColumn(0,7);
	LCD_intgerToString(count); /*display on LCD*/
}

/*Incrementation of the counter function*/
void Increment(void){
	if(count==999) /*Reset the counter when reaching 999*/
		Reset();
	else
	{
		count++;
		LCD_goToRowColumn(0,7);
		LCD_intgerToString(count); /*display on LCD*/
	}
}

/*Decrementation of the counter function*/
void Decrement(void){
	if(count==0) /*Return to 999 when reaching 0*/
		count=999;
	else
		count--;
	LCD_clearScreen();
	LCD_goToRowColumn(0,7);
	LCD_intgerToString(count); /*display on LCD*/
}
