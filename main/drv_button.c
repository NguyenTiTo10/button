#include "drv_button.h"

#define TAG "Button ISR"          // Define a tag for logging
#define DEBOUNCE_DELAY_MS 50     // Debounce delay in milliseconds

static  uint32_t           last_debounce_time  = 0;               // Last debounce time
static  drv_btn_type_t     last_button_press   = NON_BTN_PRESSED;   // Last stable state of the button (true = pressed, false = not pressed)
static  uint32_t           current_time;
static  uint32_t           elasped_time;

static  uint8_t  count = 1;

drv_btn_type_t drv_btn_detect_press ()
{
  if (!bsp_get_isr_flag())
    return NON_BTN_PRESSED;

    // Count the time to check whether debounce or not
  current_time = bsp_timer_get_time() / 1000;
  elasped_time = current_time - last_debounce_time;
  if (elasped_time <= DEBOUNCE_DELAY_MS)
    return NON_BTN_PRESSED;

  bsp_set_isr_flag (false);
  last_debounce_time = current_time;

  if (bsp_gpio_read_pin(MAIN_BTN_GPIO) == 1)
    return MAIN_BTN_PRESSED;
  
  if (bsp_gpio_read_pin(LEFT_BTN_GPIO) == 1)
    return LEFT_BTN_PRESSED;

  if (bsp_gpio_read_pin(RIGHT_BTN_GPIO) == 1)
    return RIGHT_BTN_PRESSED;
}



drv_btn_type_t drv_btn_update_state (void)
{
  while (1)
  {
    if (!bsp_get_isr_flag())
      continue;
    drv_btn_type_t button_press = drv_btn_detect_press();

    if (button_press == NON_BTN_PRESSED)
    if (bsp_get_isr_flag() && bsp_gpio_read_pin(MAIN_BTN_GPIO) == 1)
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


  
