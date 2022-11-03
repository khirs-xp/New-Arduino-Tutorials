#include <Arduino_FreeRTOS.h>

#define LED_RED 8
#define LED_YELLOW 7
#define LED_GREEN 6

const uint16_t *redLed = (uint16_t *)LED_RED;
const uint16_t *yellowLed = (uint16_t *)LED_YELLOW;
const uint16_t *greenLed = (uint16_t *)LED_GREEN;

void setup()
{
    xTaskCreate(LedControllerTask, "RED LED TASK", 128, (void *)redLed, 1, NULL);
    xTaskCreate(LedControllerTask, "YELLOW LED TASK", 128, (void *)yellowLed, 1, NULL);
    xTaskCreate(LedControllerTask, "GREEN LED TASK", 128, (void *)greenLed, 1, NULL);
}

void LedControllerTask(void *pvParameters)
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    while (1)
    {
        delay(500);
        digitalWrite(pvParameters, digitalRead(pvParameters) ^ 1);
    }
}

void loop() {}