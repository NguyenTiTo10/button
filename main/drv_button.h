#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"
#include "esp_system.h"  // Include this for IRAM_ATTR
#include "esp_log.h"
#include "bsp_gpio.h"
#include "bsp_timer.h"

#define MID_BTN_GPIO  GPIO_NUM_0    // Use GPIO0 for the button

typedef enum
{
  LEFT_BTN_PRESSED = 0,
  MID_BTN_PRESSED,
  RIGHT_BTN_PRESSED
} drv_btn_type_t;

typedef enum
{
  ONE_CLICK = 0,
  DOUBLE_CLICK,
  HOLD
} drv_btn_press_state_t;




void update_button_state (void);

#endif 