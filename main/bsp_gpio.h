#ifndef BSP_GPIO_H
#define BSP_GPIO_H

#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"

void bsp_gpio_write_pin (gpio_num_t gpio_num, uint32_t level);

#endif