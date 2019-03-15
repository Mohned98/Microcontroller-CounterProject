#include <stdint.h>
#include "tm4c123gh6pm.h"
#include <math.h>
#define frequency 							16000000
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load value

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R =5;
}
// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock)
void SysTick_delay(uint32_t delay){
  volatile uint32_t elapsedTime;
  uint32_t startTime = NVIC_ST_CURRENT_R;
  do{
    elapsedTime = (startTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
  }
  while(elapsedTime <= delay);
}
// Time delay using busy wait.
void SysTick_delayms(uint32_t delay){
  uint32_t counts=(0.001*delay*frequency);
	if(counts<=(0xFFFFFF-1)){
    SysTick_delay(counts-1); 		
	}
	else {
	for(int i=0;i<(int)(counts/0xFFFFFF);i++){
		SysTick_delay(16000000-1);
	}
	SysTick_delay((((float)counts/0xFFFFFF)-((int)(counts/0xFFFFFF)))*16000000-1);
	}
}
