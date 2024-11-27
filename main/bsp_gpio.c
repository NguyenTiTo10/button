#include "bsp_gpio.h"

uint8_t bsp_gpio_read_pin  (gpio_num_t gpio_num)
{
  return gpio_get_level(gpio_num);
}

void bsp_gpio_write_pin   (gpio_num_t gpio_num, uint32_t level)
{
  gpio_set_level(gpio_num, level);
}

void bsp_gpio_toggle_pin  (gpio_num_t gpio_num)
{
  uint32_t state = !(gpio_get_level(gpio_num));
  gpio_set_level(gpio_num, state);
}

// ISR handler for button interrupt
void  button_isr_handler(void *arg)
{
  // Read the button state
  if (gpio_get_level(MID_BTN_GPIO) == 1)
    isr_flag = true;
  
}-