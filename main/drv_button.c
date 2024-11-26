#include "drv_button.h"

#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static volatile bool isr_flag = false;

bool button_isr_flag ()
{
  return isr_flag;
}

void update_button_state (void)
{
  // Get the current time in milliseconds (use your preferred method to get time)
  uint32_t current_time = bsp_timer_get_time() / 1000; // Convert to milliseconds
}


// ISR handler for button interrupt
void IRAM_ATTR button_isr_handler(void *arg)
{
  // Read the button state
  int isr_flag = gpio_get_level(BUTTON_GPIO);
}