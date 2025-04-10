#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// M5NanoC6のLEDピン（データシートやドキュメントで確認してください）
#define LED_PIN GPIO_NUM_7

static const char *TAG = "m5nano-blink";

void app_main(void)
{
  // GPIOを設定
  gpio_reset_pin(LED_PIN);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

  ESP_LOGI(TAG, "M5NanoC6 LED Blink Start");

  while (1)
  {
    ESP_LOGI(TAG, "LED ON");
    gpio_set_level(LED_PIN, 1);           // LED点灯
    vTaskDelay(500 / portTICK_PERIOD_MS); // 500ms待機

    ESP_LOGI(TAG, "LED OFF");
    gpio_set_level(LED_PIN, 0);           // LED消灯
    vTaskDelay(500 / portTICK_PERIOD_MS); // 500ms待機
  }
}