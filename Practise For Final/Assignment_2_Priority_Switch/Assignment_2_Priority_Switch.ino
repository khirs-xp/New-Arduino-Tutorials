// DEFINE LED AND BUTTON

const int LED_RED = 4;
const int LED_YELLOW = 3;
const int LED_GREEN = 2;

const int BUTTON_RED = 12;
const int BUTTON_YELLOW = 11;
const int BUTTON_GREEN = 10;

// LED STATE

bool is_red_active = false;
bool is_yellow_active = false;
bool is_green_active = false;

// Time

int red_timer = 0;
int yellow_timer = 0;
int green_timer = 0;

// BUTTON CHECK

bool is_red_button_pressed = false;
bool is_yellow_button_pressed = false;
bool is_green_button_pressed = false;

// DEBOUNCE DELAY

unsigned long debounce_delay = 50;

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    pinMode(BUTTON_RED, INPUT);
    pinMode(BUTTON_YELLOW, INPUT);
    pinMode(BUTTON_GREEN, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(BUTTON_RED) == HIGH)
    {
        if (is_red_active && !is_red_button_pressed)
        {
            digitalWrite(LED_RED, LOW);

            is_red_active = false;
            red_timer = 0;
        }
        else if (!is_red_active && !is_red_button_pressed)
        {
            digitalWrite(LED_RED, HIGH);

            is_red_active = true;
            red_timer = millis();
        }
        is_red_button_pressed = true;
    }
    else
    {
        is_red_button_pressed = false;
        delay(50);
    }
    if (isTimePassed(red_timer, 3000) && is_red_active)
    {
        digitalWrite(LED_RED,LOW);

        is_red_active = false;
        red_timer = 0;
    }
}

bool isTimePassed(long last_run, int delay)
{
    return (millis() >= last_run + delay);
}