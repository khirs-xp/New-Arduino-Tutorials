#include <Arduino_FreeRTOS.h>

#define LED_RED 8
#define LED_YELLOW 7
#define LED_GREEN 6

const uint16_t *redLed = (uint16_t *)LED_RED;
const uint16_t *yellowLed = (uint16_t *)LED_YELLOW;
const uint16_t *greenLed = (uint16_t *)LED_GREEN;

const uint16_t *taskParams[3][2] = {{redLed, 500}, {yellowLed, 1000}, {greenLed, 2000}};

void setup()
{
    xTaskCreate(LedControllerTask, "RED LED TASK", 128, (void *)taskParams[0], 1, NULL);
    xTaskCreate(LedControllerTask, "YELLOW LED TASK", 128, (void *)taskParams[1], 1, NULL);
    xTaskCreate(LedControllerTask, "GREEN LED TASK", 128, (void *)taskParams[2], 1, NULL);
}

void LedControllerTask(void *pvParameters)
{

    const uint16_t *params = pvParameters;
    int ledPin = params[0];
    int time = params[1];
    pinMode(ledPin, OUTPUT);
    while (1)
    {
        delay(time);
        digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
    }
}

void loop()
{
}