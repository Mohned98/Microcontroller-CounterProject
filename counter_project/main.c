#include "MACROS.h"
#include "STANDARD_TYPES.h"
uint32 count=0;

void Increment(void); /*Incrementation of the counter function*/
void Decrement(void); /*Decrementation of the counter function*/
void Reset(void); /*Reset of the counter function*/

void SystemInit(void){}
	
int main(void)
{       /*Initialization of LCD & push buttons*/
	LCD_init();
	LCD_goToRowColumn(0x8,0x86);
	 Button_Init(0x03, 0x07, PULL_UP);
		while(1) 
		{
			Button_ActOnHighLevel( 0x03,0x01,*Increment );
	  	        Button_ActOnFallingEdge( 0x03, 0x02, *Reset );
			Button_ActOnRisingEdge( 0x03, 0x03, *Decrement ); 
		}
	
}

/*Reset of the counter function*/
void Reset(void){
	count=0;
	LCD_intgerToString(count); /*display on LCD*/
}

/*Incrementation of the counter function*/
void Increment(void){
	if(count==999) /*Reset the counter when reaching 999*/
		Reset();
	else
		count++;
	LCD_intgerToString(count); /*display on LCD*/
}

/*Decrementation of the counter function*/
void Decrement(void){
	if(count==0) /*Return to 999 when reaching 0*/
		count=999;
	else
		count--;
	LCD_intgerToString(count); /*display on LCD*/
}
