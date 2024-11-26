#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"

#define BUTTON_GPIO GPIO_NUM_0   // Use GPIO0 for the button

static const char *TAG = "Button";

// ISR handler for button interrupt
static void IRAM_ATTR button_isr_handler(void *arg)
{
    // Read the button state
    int button_state = gpio_get_level(BUTTON_GPIO);

    // Log the button state
    if (button_state == 1) {
        ESP_EARLY_LOGI(TAG, "Button Pressed!");
    } else {
        ESP_EARLY_LOGI(TAG, "Button Released!");
    }
}

void app_main(void)
{
    // Configure the button GPIO as input with pull-up resistor
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),  // Select GPIO
        .mode = GPIO_MODE_INPUT,               // Set as input
        .pull_up_en = GPIO_PULLUP_ENABLE,      // Enable pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE, // Disable pull-down
        .intr_type = GPIO_INTR_ANYEDGE         // Trigger interrupt on both rising and falling edges
    };
    gpio_config(&io_conf);

    // Install GPIO ISR service with a specific interrupt flag
    gpio_install_isr_service(ESP_INTR_FLAG_LEVEL1);

    // Hook ISR handler for the button GPIO
    gpio_isr_handler_add(BUTTON_GPIO, button_isr_handler, NULL);

    ESP_LOGI(TAG, "Interrupt-based button detection initialized.");
}
