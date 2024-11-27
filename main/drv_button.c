#include "drv_button.h"

#define TAG "Button ISR"          // Define a tag for logging
#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static uint32_t last_debounce_time  = 0;     // Last debounce time
static bool     last_button_state   = false;      // Last stable state of the button (true = pressed, false = not pressed)

static uint8_t  count = 1;

void update_button_state (void)
{
  while (1)
  {
    if (bsp_get_isr_flag() && bsp_gpio_read_pin(MID_BTN_GPIO) == 1)
    {
      uint32_t current_time = bsp_timer_get_time() / 1000;
      if ((current_time - last_debounce_time) > DEBOUNCE_DELAY_MS)
        ESP_EARLY_LOGI(TAG, "Count: %d - Button Pressed!", count);
      
      last_debounce_time = current_time;
      count++;
      bsp_set_isr_flag (false);
    }

    bsp_timer_delay(10);
  }
  
}


  
