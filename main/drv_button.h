#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"
#include "esp_system.h"  // Include this for IRAM_ATTR
#include "esp_log.h"
#include "bsp_gpio.h"
#include "bsp_timer.h"


void update_button_state (void);

#endif 