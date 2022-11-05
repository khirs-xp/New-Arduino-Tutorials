#define LED_RED 6
#define BUTTON_RED 5

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(BUTTON_RED, INPUT);
}

void loop()
{

    if (digitalRead(BUTTON_RED) == HIGH)
    {
        digitalWrite(LED_RED, HIGH);
    }
    else
    {
        digitalWrite(LED_RED, LOW);
    }
}