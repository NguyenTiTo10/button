#include "drv_button.h"

#define TAG "Button ISR"          // Define a tag for logging
#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static volatile bool isr_flag = false;
// static uint32_t last_debounce_time = 0;     // Last debounce time
// static bool last_button_state = false;      // Last stable state of the button (true = pressed, false = not pressed)


bool button_isr_flag ()
{
  return isr_flag;
}


void update_button_state (void)
{
  // uint32_t current_time = bsp_timer_get_time() / 1000; // Convert to milliseconds

  while (1)
  {
    if (isr_flag) 
      ESP_EARLY_LOGI(TAG, "Button Pressed!");

    isr_flag = false;

    bsp_timer_delay(200);
  }
  
}


  
