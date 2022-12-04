#define LED_1 9
#define LED_2 8
#define BUTTON_1 2

#define goLED1 0
#define goLED2 1

struct State
{
    unsigned long ST_Out;
    unsigned long Time;
    unsigned long Next[2];
};
typedef const struct State SType;

SType FSM[2] = {
    {B00000001, 2000, {goLED1, goLED2}},
    {B00000010, 2000, {goLED2, goLED1}},
};

unsigned long S = 0;

void setup()
{
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(BUTTON_1, INPUT);
}
int button1, input;

void loop()
{
    digitalWrite(LED_1, FSM[S].ST_Out & B00000001);
    digitalWrite(LED_2, FSM[S].ST_Out & B00000010);

    delay(FSM[S].Time);
    button1 = digitalRead(BUTTON_1);

    input = button1;
    S = FSM[S].Next[input];
}