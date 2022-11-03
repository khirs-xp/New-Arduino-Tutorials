#include <Arduino_FreeRTOS.h>

#define LED_RED 8
#define LED_YELLOW 7
#define LED_GREEN 6

// Create Task
void setup()
{
  xTaskCreate(redLedControllerTask, "RED LED TASK", 128, NULL, 1, NULL);
  xTaskCreate(yellowLedControllerTask, "YELLOW LED TASK", 128, NULL, 1, NULL);
  xTaskCreate(greenLedControllerTask, "GREEN LED TASK", 128, NULL, 1, NULL);
}

// LED Function
void redLedControllerTask(void *pvParameters)
{
  pinMode(LED_RED, OUTPUT);
  while (1)
  {
    delay(500);
    digitalWrite(LED_RED, digitalRead(LED_RED) ^ 1); // Blink
  }
}

void yellowLedControllerTask(void *pvParameters)
{
  pinMode(LED_YELLOW, OUTPUT);
  while (1)
  {
    delay(500);
    digitalWrite(LED_YELLOW, digitalRead(LED_YELLOW) ^ 1); // Blink
  }
}

void greenLedControllerTask(void *pvParameters)
{
  pinMode(LED_GREEN, OUTPUT);
  while (1)
  {
    delay(500);
    digitalWrite(LED_GREEN, digitalRead(LED_GREEN) ^ 1); // Blink
  }
}

void loop()
{
}
