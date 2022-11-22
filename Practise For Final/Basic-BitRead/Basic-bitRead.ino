int bitPattern = B00011010;
const byte numPin = 5;
const int ledPins[5] = {13, 12, 11, 10, 9};
void setup()
{
    Serial.begin(9600);
    for (int i = 0; i <= 5; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop()
{
    boolean isBitSet;
    for (int led = 0; led < 5; led++)
    {
        isBitSet = bitRead(bitPattern, led);
        digitalWrite(ledPins[led], isBitSet);
    }
}