#define LED_RED 6
#define BUTTON_RED 5

byte lastButtonState;
byte ledState = LOW;

unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50; // millis

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(BUTTON_RED, INPUT);
    lastButtonState = digitalRead(BUTTON_RED);
}

void loop()
{
    if (millis() - lastTimeButtonStateChanged >= debounceDuration)
    {
        byte buttonState = digitalRead(BUTTON_RED);
        if (buttonState != lastButtonState)
        {
            lastTimeButtonStateChanged = millis();
            lastButtonState = buttonState;
            if (buttonState == LOW)
            {
                if (ledState == HIGH)
                {
                    ledState = LOW;
                }
                else
                {
                    ledState = HIGH;
                }
                digitalWrite(LED_RED, ledState);
            }
        }
    }
}