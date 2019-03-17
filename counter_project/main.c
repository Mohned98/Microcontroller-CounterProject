#include "MACROS.h"
#include "STANDARD_TYPES.h"
uint32 count=0;

void Increment(void){
	if(count==999)
		count=0;
	else
		count++;
	LCD_intgerToString(count);
}

void Decrement(void){
	if(count==0)
		count=999;
	else
		count--;
	LCD_intgerToString(count);
}

void Reset(void){
	count=0;
	LCD_intgerToString(count);
}

void SystemInit(void){}
	
int main(void)
{
		while(1) 
		{
			 
		}
	
}

