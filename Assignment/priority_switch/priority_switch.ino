#define LED_RED 4
#define LED_YELLOW 3
#define LED_GREEN 2

#define BUTTON_RED 12
#define BUTTON_YELLOW 11
#define BUTTON_GREEN 10

unsigned long RedTimer = 0;
unsigned long YellowTimer = 0;
unsigned long GreenTimer = 0;

unsigned char LedRedState = LOW;
unsigned char LedYellowState = LOW;
unsigned char LedGreenState = LOW;

unsigned char LedYellowBlink = LOW;

unsigned char ButtonRedState = LOW;
unsigned char ButtonYellowState = LOW;
unsigned char ButtonGreenState = LOW;

unsigned char LastButtonRedState = LOW;
unsigned char LastButtonYellowState = LOW;
unsigned char LastButtonGreenState = LOW;

unsigned long DBButtonRed = 0;
unsigned long DBButtonYellow = 0;
unsigned long DBButtonGreen = 0;

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(BUTTON_RED, INPUT_PULLUP);
    pinMode(BUTTON_YELLOW, INPUT);
    pinMode(BUTTON_GREEN, INPUT_PULLUP);
}

void loop()
{

    // LED RED

    ButtonRedState = digitalRead(BUTTON_RED);

    if (LedRedState == HIGH)
    {
        if (millis() - RedTimer > 3000)
        {
            digitalWrite(LED_RED, LOW);
            LedRedState = LOW;
        }
    }

    if (ButtonRedState != LastButtonRedState)
    {
        LastButtonRedState = ButtonRedState;
        if ((ButtonRedState == LOW) && (LedRedState == LOW))
        {
            if (millis() - DBButtonRed >= 300)
            {
                digitalWrite(LED_RED, HIGH);
                LedRedState = HIGH;
                RedTimer = millis();
                DBButtonRed = millis();
            }
        }
        else if ((ButtonRedState == LOW) && (LedRedState == HIGH))
        {
            if (millis() - DBButtonRed >= 300)
            {
                digitalWrite(LED_RED, LOW);
                LedRedState = LOW;
                DBButtonRed = millis();
            }
        }
    }

    // LED GREEN

    ButtonGreenState = digitalRead(BUTTON_GREEN);

    if (LedGreenState == HIGH)
    {
        if (millis() - GreenTimer > 3000)
        {
            digitalWrite(LED_GREEN, LOW);
            LedGreenState = LOW;
        }
    }

    if (ButtonGreenState != LastButtonGreenState)
    {
        LastButtonGreenState = ButtonGreenState;
        if ((ButtonGreenState == LOW) && (LedGreenState == LOW) && (LedRedState == LOW))
        {
            if (millis() - DBButtonGreen >= 300)
            {
                digitalWrite(LED_GREEN, HIGH);
                LedGreenState = HIGH;
                GreenTimer = millis();
                DBButtonGreen = millis();
            }
        }
        else if ((ButtonGreenState == LOW) && (LedGreenState == HIGH))
        {
            if (millis() - DBButtonGreen >= 300)
            {
                digitalWrite(LED_GREEN, LOW);
                LedGreenState = LOW;
                GreenTimer = millis();
            }
        }
    }

    // LED YELLOW

    ButtonYellowState = digitalRead(BUTTON_YELLOW);

    if (LedYellowState == HIGH)
    {
        LedYellowBlink = LedYellowState;
        if (millis() - YellowTimer > 500)
        {
            LedYellowBlink = LOW;
        }
        if (millis() - YellowTimer > 1000)
        {
            LedYellowBlink = HIGH;
        }
        if (millis() - YellowTimer > 1500)
        {
            LedYellowBlink = LOW;
        }
        if (millis() - YellowTimer > 2000)
        {
            LedYellowBlink = LOW;
            digitalWrite(LED_YELLOW, LOW);
            LedYellowState = LOW;
        }
        digitalWrite(LED_YELLOW, LedYellowBlink);
    }

    if (ButtonYellowState != LastButtonYellowState)
    {
        LastButtonYellowState = ButtonYellowState;
        if ((ButtonYellowState == LOW) && (LedRedState == LOW) && (LedYellowState == LOW) && (LedGreenState == LOW))
        {
            if (millis() - DBButtonYellow >= 300)
            {
                digitalWrite(LED_YELLOW, HIGH);
                LedYellowState = HIGH;
                YellowTimer = millis();
                DBButtonYellow = millis();
            }
        }
        else if ((ButtonYellowState == LOW) && (LedYellowState == HIGH))
        {
            if (millis() - DBButtonYellow >= 300)
            {
                digitalWrite(LED_YELLOW, LOW);
                LedYellowState = LOW;
                DBButtonYellow = millis();
            }
        }
    }
}