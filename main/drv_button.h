#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"

void IRAM_ATTR button_isr_handler(void *arg);

#endif 
