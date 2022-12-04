#define LED_1 8
#define LED_2 9
#define LED_3 10
#define LED_4 11
#define BUTTON_1 2
#define BUTTON_2 3

#define goLED1 0
#define goLED2 1
#define goLED3 2
#define goLED4 3

struct State
{
    unsigned long ST_Out;
    unsigned long Time;
    unsigned long Next[4];
};
typedef const struct State SType;

SType FSM[4] = {
    {B00000001, 2000, {goLED1, goLED2, goLED3, goLED4}},
    {B00000010, 2000, {goLED2, goLED2, goLED1, goLED1}},
    {B00000100, 2000, {goLED3, goLED1, goLED3, goLED1}},
    {B00001000, 2000, {goLED4, goLED1, goLED1, goLED4}},
};

unsigned long S = 0;

void setup()
{
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
}
int button1, button2, input;

void loop()
{
    digitalWrite(LED_1, FSM[S].ST_Out & B00000001);
    digitalWrite(LED_2, FSM[S].ST_Out & B00000010);
    digitalWrite(LED_3, FSM[S].ST_Out & B00000100);
    digitalWrite(LED_4, FSM[S].ST_Out & B00001000);

    delay(FSM[S].Time);
    button1 = digitalRead(BUTTON_1);
    button2 = digitalRead(BUTTON_2);

    input = button1 + (button2 * 2);
    S = FSM[S].Next[input];
}