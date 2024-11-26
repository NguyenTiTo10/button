#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"
#include "esp_system.h"  // Include this for IRAM_ATTR
#include "esp_log.h"

#define BUTTON_GPIO GPIO_NUM_0   // Use GPIO0 for the button
#define TAG "Button ISR"  // Define a tag for logging

void IRAM_ATTR button_isr_handler(void *arg);

#endif 
