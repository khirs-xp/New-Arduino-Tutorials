// DEFINE LED
#define LED_RED 6
#define LED_YELLOW 5
#define LED_GREEN 4
#define LED_BLUE 3
#define LED_ORANGE 2

// DEFINE BUTTON
#define BUTTON_RED 13
#define BUTTON_YELLOW 12
#define BUTTON_GREEN 11
#define BUTTON_BLUE 10
#define BUTTON_ORANGE 9

// Timer
unsigned long RedTimer = 0;
unsigned long YellowTimer = 0;
unsigned long GreenTimer = 0;
unsigned long BlueTimer = 0;
unsigned long OrangeTimer = 0;

// LED STATE
unsigned char RedLedState = LOW;
unsigned char YellowLedState = LOW;
unsigned char GreenLedState = LOW;
unsigned char BlueLedState = LOW;
unsigned char OrangeLedState = LOW;

// Blink State
unsigned char RedLedBlink = LOW;
unsigned char BlueLedBlink = LOW;
unsigned char OrangeLedBlink = LOW;

// Button State
unsigned char RedButtonState = LOW;
unsigned char YellowButtonState = LOW;
unsigned char GreenButtonState = LOW;
unsigned char BlueButtonState = LOW;
unsigned char OrangeButtonState = LOW;

// LAST BUTTON STATE
unsigned char LastRedButtonState = LOW;
unsigned char LastYellowButtonState = LOW;
unsigned char LastGreenButtonState = LOW;
unsigned char LastBlueButtonState = LOW;
unsigned char LastOrangeButtonState = LOW;

// DEBOUNCE
unsigned long DBRedTimer = 0;
unsigned long DBYellowTimer = 0;
unsigned long DBGreenTimer = 0;
unsigned long DBBlueTimer = 0;
unsigned long DBOrangeTimer = 0;

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_ORANGE, OUTPUT);

    pinMode(BUTTON_RED, INPUT);
    pinMode(BUTTON_YELLOW, INPUT);
    pinMode(BUTTON_GREEN, INPUT);
    pinMode(BUTTON_BLUE, INPUT);
    pinMode(BUTTON_ORANGE, INPUT);
}

void loop()
{
    // LED RED

    RedButtonState = digitalRead(BUTTON_RED);
    if (RedLedState == HIGH)
    {
        RedLedBlink = RedLedState;
        if (millis() - RedTimer > 1000)
        {
            RedLedBlink = LOW;
        }
        if (millis() - RedTimer > 2000)
        {
            RedLedBlink = HIGH;
        }
        if (millis() - RedTimer > 3000)
        {
            RedLedBlink = LOW;
        }
        if (millis() - RedTimer > 4000)
        {
            RedLedBlink = HIGH;
        }
        if (millis() - RedTimer > 5000)
        {
            RedLedBlink = LOW;
        }
        if (millis() - RedTimer > 6000)
        {
            RedLedBlink = HIGH;
        }
        if (millis() - RedTimer > 7000)
        {
            RedLedBlink = LOW;
        }
        if (millis() - RedTimer > 8000)
        {
            digitalWrite(LED_RED, LOW);
            RedLedBlink = LOW;
            RedLedState = LOW;
        }
        digitalWrite(LED_RED, RedLedBlink);
    }

    if (RedButtonState != LastRedButtonState)
    {
        LastRedButtonState = RedButtonState;
        if ((RedButtonState == LOW) && (RedLedState == LOW) && (YellowLedState == LOW) && (GreenLedState == LOW) && (BlueLedState == LOW) && (OrangeLedState == LOW))
        {
            if (millis() - DBRedTimer > 300)
            {
                digitalWrite(LED_RED, HIGH);
                RedLedState = HIGH;
                RedTimer = millis();
                DBRedTimer = millis();
            }
        }
        if ((RedButtonState == LOW) && (RedLedState == HIGH))
        {
            if (millis() - DBRedTimer > 300)
            {
                digitalWrite(LED_RED, LOW);
                RedLedState = LOW;
                DBRedTimer = millis();
            }
        }
    }

    // LED YELLOW

    YellowButtonState = digitalRead(BUTTON_YELLOW);
    if (YellowLedState == HIGH)
    {
        if (millis() - YellowTimer > 5000)
        {
            digitalWrite(LED_YELLOW, LOW);
            YellowLedState = LOW;
        }
    }

    if (YellowButtonState != LastYellowButtonState)
    {
        LastYellowButtonState = YellowButtonState;
        if ((YellowButtonState == LOW) && (YellowLedState == LOW))
        {
            if (millis() - DBYellowTimer > 300)
            {
                digitalWrite(LED_YELLOW, HIGH);
                YellowLedState = HIGH;
                YellowTimer = millis();
                DBYellowTimer = millis();
            }
        }
        else if ((YellowButtonState == LOW) && (YellowLedState == HIGH))
        {
            if (millis() - DBYellowTimer > 300)
            {
                digitalWrite(LED_YELLOW, LOW);
                YellowLedState = LOW;
                DBYellowTimer = millis();
            }
        }
    }

    // LED GREEN

    GreenButtonState = digitalRead(BUTTON_GREEN);
    if (GreenLedState == HIGH)
    {
        if (millis() - GreenTimer > 2000)
        {
            digitalWrite(LED_GREEN, LOW);
            GreenLedState = LOW;
        }
    }

    if (GreenButtonState != LastGreenButtonState)
    {
        LastGreenButtonState = GreenButtonState;
        if ((GreenButtonState == LOW) && (GreenLedState == LOW) && (RedLedState = HIGH) && (YellowLedState == HIGH) && (BlueLedState == HIGH) && (OrangeLedState == HIGH))
        {
            if (millis() - DBGreenTimer > 300)
            {
                digitalWrite(LED_GREEN, HIGH);
                GreenLedState = HIGH;
                GreenTimer = millis();
                DBGreenTimer = millis();
            }
        }
        else if ((GreenButtonState == LOW) && (GreenLedState == HIGH))
        {
            if (millis() - DBGreenTimer > 300)
            {
                digitalWrite(LED_GREEN, LOW);
                GreenLedState = LOW;
                DBGreenTimer = millis();
            }
        }
    }

    // LED BLUE

    BlueButtonState = digitalRead(BUTTON_BLUE);
    if (BlueLedState == HIGH)
    {
        BlueLedBlink = BlueLedState;
        if (millis() - BlueTimer > 1500)
        {
            BlueLedBlink = LOW;
        }
        if (millis() - BlueTimer > 3000)
        {
            BlueLedBlink = HIGH;
        }
        if (millis() - BlueTimer > 4500)
        {
            BlueLedBlink = LOW;
        }
        if (millis() - BlueTimer > 6000)
        {
            BlueLedBlink = HIGH;
        }
        if (millis() - BlueTimer > 7500)
        {
            BlueLedBlink = LOW;
            digitalWrite(LED_BLUE, LOW);
            BlueLedState = LOW;
        }
        digitalWrite(LED_BLUE, BlueLedBlink);
    }

    if (BlueButtonState != LastBlueButtonState)
    {
        LastBlueButtonState = BlueButtonState;
        if ((BlueButtonState == LOW) && (BlueLedState == LOW) && (YellowLedState == LOW))
        {
            if (millis() - DBBlueTimer > 300)
            {
                digitalWrite(LED_BLUE, HIGH);
                BlueLedState = HIGH;
                BlueTimer = millis();
                DBBlueTimer = millis();
            }
        }
        if ((BlueButtonState == LOW) && (BlueLedState == HIGH))
        {
            if (millis() - DBBlueTimer > 300)
            {
                digitalWrite(LED_BLUE, LOW);
                BlueLedState = LOW;
                DBBlueTimer = millis();
            }
        }
    }

    // LED ORANGE

    OrangeButtonState = digitalRead(BUTTON_ORANGE);
    if (OrangeLedState == HIGH)
    {
        OrangeLedBlink = OrangeLedState;
        if (millis() - OrangeTimer > 200)
        {
            OrangeLedBlink = LOW;
        }
        if (millis() - OrangeTimer > 400)
        {
            OrangeLedBlink = HIGH;
        }
        if (millis() - OrangeTimer > 600)
        {
            OrangeLedBlink = LOW;
        }
        if (millis() - OrangeTimer > 800)
        {
            OrangeLedBlink = HIGH;
        }
        if (millis() - OrangeTimer > 1000)
        {
            OrangeLedBlink = LOW;
        }
        if (millis() - OrangeTimer > 1200)
        {
            OrangeLedBlink = HIGH;
        }
        if (millis() - OrangeTimer > 1400)
        {
            OrangeLedBlink = LOW;
        }
        if (millis() - OrangeTimer > 1600)
        {
            OrangeLedBlink = HIGH;
        }
        if (millis() - OrangeTimer > 1800)
        {
            OrangeLedBlink = LOW;
        }
        if (millis() - OrangeTimer > 2000)
        {
            OrangeLedBlink = LOW;
            digitalWrite(LED_ORANGE, LOW);
            OrangeLedState = LOW;
        }
        digitalWrite(LED_ORANGE, OrangeLedBlink);
    }

    if (OrangeButtonState != LastOrangeButtonState)
    {
        LastOrangeButtonState = OrangeButtonState;
        if ((OrangeButtonState == LOW) && (OrangeLedState == LOW) && (YellowLedState == HIGH))
        {
            if (millis() - DBOrangeTimer > 300)
            {
                digitalWrite(LED_ORANGE, HIGH);
                OrangeLedState = HIGH;
                OrangeTimer = millis();
                DBOrangeTimer = millis();
            }
        }
        if ((OrangeButtonState == LOW) && (OrangeLedState == HIGH))
        {
            if (millis() - DBOrangeTimer > 300)
            {
                digitalWrite(LED_ORANGE, LOW);
                OrangeLedState = LOW;
                DBOrangeTimer = millis();
            }
        }
    }
}