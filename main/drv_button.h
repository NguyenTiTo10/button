#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"
#include "esp_system.h"  // Include this for IRAM_ATTR
#include "esp_log.h"
#include "bsp_gpio.h"
#include "bsp_timer.h"

#define BUTTON_GPIO GPIO_NUM_0    // Use GPIO0 for the button

void update_button_state (void);
void IRAM_ATTR button_isr_handler(void *arg);

#endif 
