#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "driver/gpio.h"
#include "esp_system.h"  // Include this for IRAM_ATTR
#include "esp_log.h"
#include "bsp_gpio.h"
#include "bsp_timer.h"

#define MAIN_BTN_GPIO     GPIO_NUM_34       
#define LEFT_BTN_GPIO     GPIO_NUM_25
#define MID_BTN_GPIO      GPIO_NUM_26
#define RIGHT_BTN_GPIO    GPIO_NUM_27


typedef enum
{
  NON_BTN_PRESS = 0,
  MAIN_BTN_PRESSED,
  LEFT_BTN_PRESSED,
  MID_BTN_PRESSED,
  RIGHT_BTN_PRESSED
} drv_btn_type_t;

typedef enum
{
  NO_PRESS = 0,
  PRESSED
} drv_btn_press_state_t;




void update_button_state (void);

#endif 