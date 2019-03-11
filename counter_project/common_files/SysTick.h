

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void);

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock)
void SysTick_delay(uint32_t delay);

// Time delay using busy wait.
void SysTick_delayms(uint32_t delay);
