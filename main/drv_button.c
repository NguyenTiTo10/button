#include "drv_button.h"

#define TAG "Button ISR"          // Define a tag for logging
#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static volatile bool isr_flag = false;
static uint32_t last_debounce_time = 0;     // Last debounce time
static bool last_button_state = false;      // Last stable state of the button (true = pressed, false = not pressed)


bool button_isr_flag ()
{
  return isr_flag;
}

void update_button_state (void)
{
  // Get the current time in milliseconds (use your preferred method to get time)
    uint32_t current_time = esp_timer_get_time() / 1000; // Convert to milliseconds

    // Check if enough time has passed since the last debounce check
    if (current_time - last_debounce_time >= DEBOUNCE_DELAY_MS) {
        // Update the last debounce time
        last_debounce_time = current_time;

        // Check the button state
        if (isr_flag != last_button_state) {
            // Button state has changed (pressed/released)
            last_button_state = isr_flag;  // Update the stable state

            // Log the button state change
            if (last_button_state) {
                ESP_LOGI(TAG, "Button Pressed!");
            } else {
                ESP_LOGI(TAG, "Button Released!");
            }
        }
    }
}


// ISR handler for button interrupt
void IRAM_ATTR button_isr_handler(void *arg)
{
  // Read the button state
  if (gpio_get_level(BUTTON_GPIO) == 1)
    isr_flag = true;
    
  update_button_state();
}