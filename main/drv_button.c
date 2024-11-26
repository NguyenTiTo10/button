#include "drv_button.h"

#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static volatile bool isr_flag;

bool button_isr_flag ()
{
  return isr_flag;
}

void update_button_state (void)
{
  
}


// ISR handler for button interrupt
void IRAM_ATTR button_isr_handler(void *arg)
{
  // Read the button state
  int isr_flag = gpio_get_level(BUTTON_GPIO);
}