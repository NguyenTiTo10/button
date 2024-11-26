#include "drv_button.h"

#define BUTTON_GPIO GPIO_NUM_0   // Use GPIO0 for the button

#define TAG "Button ISR"  // Define a tag for logging

// ISR handler for button interrupt
void IRAM_ATTR button_isr_handler(void *arg)
{
  // Read the button state
  int button_state = gpio_get_level(BUTTON_GPIO);

  // Log the button state
  if (button_state == 1) {
      ESP_EARLY_LOGI(TAG, "Button Pressed!");
    }
}