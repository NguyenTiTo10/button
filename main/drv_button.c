

// ISR handler for button interrupt
void IRAM_ATTR button_isr_handler(void *arg)
{
    // Read the button state
    int button_state = gpio_get_level(BUTTON_GPIO);

    // Log the button state
    if (button_state == 1) {
        ESP_EARLY_LOGI(TAG, "Button Pressed!");
    }
}