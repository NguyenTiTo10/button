#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"
#include "esp_system.h"  // Include this for IRAM_ATTR
#include "esp_log.h"


void IRAM_ATTR button_isr_handler(void *arg);

#endif 
