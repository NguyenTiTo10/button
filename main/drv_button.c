#include "drv_button.h"

#define TAG "Button ISR"          // Define a tag for logging
#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static volatile bool isr_flag = false;
static uint32_t last_debounce_time = 0;     // Last debounce time
// static bool last_button_state = false;      // Last stable state of the button (true = pressed, false = not pressed)


bool button_isr_flag ()
{
  return isr_flag;
}

void update_button_state (void)
{
  // Get the current time in milliseconds (use your preferred method to get time)
  uint32_t current_time = bsp_timer_get_time() / 1000; // Convert to milliseconds

  if (current_time - last_debounce_time >= DEBOUNCE_DELAY_MS) 
  {
    last_debounce_time = current_time;

    if (isr_flag) 
      ESP_LOGI(TAG, "Button Pressed!");
    else 
      ESP_LOGI(TAG, "Button Released!");

    isr_flag = false;
  }
}


// ISR handler for button interrupt
void IRAM_ATTR button_isr_handler(void *arg)
{
  // Read the button state
  int isr_flag = gpio_get_level(BUTTON_GPIO);
}