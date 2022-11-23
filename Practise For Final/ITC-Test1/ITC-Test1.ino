// DEFINE LED
#define LED_1 10
#define LED_2 11
#define LED_3 12
#define LED_4 13

// DEFINE BUTTON
#define BUTTON_1 2
#define BUTTON_2 3
#define BUTTON_3 4
#define BUTTON_SUBMIT 5
#define BUTTON_RESET 6

// LED & BUTTON ARRAY
unsigned int LED[] = {LED_1, LED_2, LED_3, LED_4};
unsigned int BUTTON[] = {BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_SUBMIT, BUTTON_RESET};

// MEMORIES
unsigned int MEM[] = {0, 0, 0};

// INTEGER
int sum = 0;
int num[] = {0, 0};

// CHECK PRESSED
unsigned int IS_BUTTON_SUBMIT_PRESSED = 0;
unsigned int IS_BUTTON_RESET_PRESSED = 0;

// DEBOUNCE TIME
unsigned long LAST_DEBOUNCE_TIME[] = {0, 0, 0, 0, 0};

// BUTTON STATE
unsigned int BUTTON_STATE[] = {LOW, LOW, LOW, LOW, LOW};
unsigned int LAST_BUTTON_STATE[] = {LOW, LOW, LOW, LOW, LOW};

// ROUND
unsigned int ROUND = 0;

void setup()
{
    for (int i = 0; i < 5; i++)
    {
        pinMode(LED[i], OUTPUT);
        pinMode(LED[i], INPUT);
    }
}

// FUNCTION DEBOUNCE
void debounce(int b)
{
    int buttonState = digitalRead(BUTTON_STATE[b]);
    if (LAST_BUTTON_STATE != buttonState)
    {
        LAST_BUTTON_STATE = millis();
    }
    if (millis() - LAST_DEBOUNCE_TIME[b] >= 50)
    {
        BUTTON_STATE[b] = buttonState;
    }
    LAST_BUTTON_STATE[b] = buttonState;
}

void resetMem()
{
    for (int i = 0; i < 3; i++)
    {
        MEM[i] = 0;
    }
}

void show(int tmp)
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(LED[i], tmp % 2);
        tmp /= 2;
    }
}

void reset()
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(LED[i], LOW);
    }
    num[0] = 0;
    num[1] = 1;
}

void loop()
{
    for (int i = 0; i < 5; i++)
    {
        debounce(i);
    }
    for (int i = 0; i < 3; i++)
    {
        if (BUTTON_STATE[i])
        {
            MEM[i] = 1;
        }
    }

    if (BUTTON_SUBMIT && !IS_BUTTON_SUBMIT_PRESSED && ROUND < 3)
    {
        IS_BUTTON_SUBMIT_PRESSED = 1;
        if (ROUND < 2)
        {
            for (int i = 0; i < 3; i++)
            {
                num[ROUND] *= 2;
                num[ROUND] += MEM[i];
            }
            resetMem();
            show(num[ROUND++]);
        }
        else
        {
            sum = num[0] + num[1];
            show(sum);
        }
    }
    else if (!BUTTON_SUBMIT)
    {
        IS_BUTTON_SUBMIT_PRESSED = 0;
    }
    else if (BUTTON_RESET && !IS_BUTTON_RESET_PRESSED)
    {
        reset();
        IS_BUTTON_RESET_PRESSED = 1;
    }
    else if (!BUTTON_RESET)
    {
        IS_BUTTON_RESET_PRESSED = 0;
    }
}