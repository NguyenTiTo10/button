#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"

#include "drv_button.h"

#include "bsp_gpio.h"

#define BUTTON_GPIO GPIO_NUM_0   // Use GPIO0 for the button

static const char *TAG = "Button";

static esp_err_t config_gpio (void);


static esp_err_t config_gpio (void)
{
    // Config GPIO 0
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),  // Select GPIO
        .mode = GPIO_MODE_INPUT,               // Set as input
        .pull_up_en = GPIO_PULLUP_DISABLE,     // Disable pull-up
        .pull_down_en = GPIO_PULLDOWN_ENABLE,  // Enable pull-down
        .intr_type = GPIO_INTR_POSEDGE         // Trigger interrupt on rising edge
    };
    
    return gpio_config(&io_conf);
}

void app_main(void)
{
    if (config_gpio() == ESP_OK)
        printf("GPIO config succesfully.\n");
    else
        printf("GPIO error.\n");

    // Install GPIO ISR service with default flags
    gpio_install_isr_service(ESP_INTR_FLAG_LEVEL1);

    // Hook ISR handler for the button GPIO
    gpio_isr_handler_add(BUTTON_GPIO, bsp_gpio_isr_handler, NULL);

    ESP_LOGI(TAG, "Interrupt-based button detection initialized.");

    update_button_state();
}