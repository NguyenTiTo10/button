#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"

#define BUTTON_GPIO    GPIO_NUM_0   // Use GPIO0 for the button

void app_main(void)
{
  // Configure the button GPIO as input with pull-up resistor
  gpio_config_t io_conf = {
      .pin_bit_mask = (1ULL << BUTTON_GPIO),
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_DISABLE,  // Enable pull-up resistor
      .pull_down_en = GPIO_PULLDOWN_ENABLE  
  };
  gpio_config(&io_conf);

  while (1) {
      // Read the button state (active-low)
      int button_state = gpio_get_level(BUTTON_GPIO);

      if (button_state == 0) {
          ESP_LOGI("Button", "Button Pressed!");
      } else {
          ESP_LOGI("Button", "Button Released!");
      }

      // Delay to prevent excessive logging
      vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
