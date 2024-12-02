#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"

#include "drv_button.h"

#define     MAIN_BTN_GPIO       GPIO_NUM_32   // Use GPIO0 for the button
#define     LEFT_BTN_GPIO       GPIO_NUM_25
#define     MID_BTN_GPIO        GPIO_NUM_26
#define     RIGHT_BTN_GPIO      GPIO_NUM_27

static const char *TAG = "Button";

static esp_err_t config_gpio (void);


static esp_err_t config_gpio (void)
{
    gpio_config_t io_conf = 
    {
        .mode = GPIO_MODE_INPUT,               // Set as input
        .pull_up_en = GPIO_PULLUP_DISABLE,     // Disable pull-up
        .pull_down_en = GPIO_PULLDOWN_ENABLE,  // Enable pull-down
        .intr_type = GPIO_INTR_POSEDGE         // Trigger interrupt on rising edge
    };
    

    // Configuring GPIO32
    io_conf.pin_bit_mask = (1ULL << MAIN_BTN_GPIO);  // Select GPIO 32
    esp_err_t err = gpio_config(&io_conf);
    if (err != ESP_OK) return err;

    // Configuring GPIO25
    io_conf.pin_bit_mask = (1ULL << LEFT_BTN_GPIO);  // Select GPIO 25
    err = gpio_config(&io_conf);
    if (err != ESP_OK) 
        return err;

    // Configuring GPIO26
    io_conf.pin_bit_mask = (1ULL << MID_BTN_GPIO);  // Select GPIO 26
    err = gpio_config(&io_conf);
    if (err != ESP_OK) 
        return err;

    // Configuring GPIO27
    io_conf.pin_bit_mask = (1ULL << RIGHT_BTN_GPIO);  // Select GPIO 27
    err = gpio_config(&io_conf);
        return err;
}

static esp_err_t config_isr_gpio (void)
{
    esp_err_t ret;

    // Install GPIO ISR service with default flags
    ret = gpio_install_isr_service(ESP_INTR_FLAG_LEVEL1);
    if (ret != ESP_OK)
        return ret;

    // Hook ISR handler for the button GPIO
    gpio_isr_handler_add(MAIN_BTN_GPIO, bsp_gpio_isr_handler, NULL);
    gpio_isr_handler_add(LEFT_BTN_GPIO, bsp_gpio_isr_handler, NULL);
    gpio_isr_handler_add(MID_BTN_GPIO, bsp_gpio_isr_handler, NULL);
    gpio_isr_handler_add(RIGHT_BTN_GPIO, bsp_gpio_isr_handler, NULL);


    ESP_LOGI(TAG, "Interrupt-based button detection initialized.");

    return ESP_OK;
}

void app_main(void)
{
    if (config_gpio() == ESP_OK)
        printf("GPIO config succesfully.\n");
    else
        printf("GPIO error.\n");

    config_isr_gpio();
    
    
    while (1)
    {
        drv_btn_update_state();

        bsp_timer_delay(10);
    }
    
}