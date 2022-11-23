int step = 0;
int btn[] = {2, 3, 4, 5, 6};
int led[] = {10, 11, 12, 13};
int buttonState[] = {LOW, LOW, LOW, LOW, LOW};
int lastButtonState[] = {LOW, LOW, LOW, LOW, LOW};
int mem[] = {0, 0, 0};
int pressed4 = 0;
int pressed3 = 0;
int num[] = {0, 0};
int sum = 0;
long long lastDebounceTime[] = {0, 0, 0, 0, 0};
void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 5; i++)
    {
        pinMode(btn[i], INPUT);
        pinMode(led[i], OUTPUT);
    }
}

void debounce(int b)
{
    int reading = digitalRead(btn[b]);
    if (lastButtonState[b] != reading)
    {
        lastDebounceTime[b] = millis();
    }

    if (millis() - lastDebounceTime[b] >= 50)
    {
        buttonState[b] = reading;
    }
    lastButtonState[b] = reading;
}

void resetMem()
{
    for (int i = 0; i < 3; i++)
    {
        mem[i] = 0;
    }
}

void show(int tmp)
{
    Serial.print("show ");
    Serial.println(tmp);
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(led[3 - i], tmp % 2);
        tmp /= 2;
    }
}

void reset()
{
    step = 0;
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(led[i], LOW);
    }
    num[0] = 0;
    num[1] = 0;
}

void loop()
{
    for (int i = 0; i < 5; i++)
    {
        debounce(i);
    }

    for (int i = 0; i < 3; i++)
    {
        if (buttonState[i])
        {
            mem[i] = 1;
        }
    }

    if (buttonState[3] && !pressed3 && step < 3)
    {

        Serial.print("step = ");
        Serial.println(step);
        pressed3 = 1;
        if (step < 2)
        {
            for (int i = 0; i < 3; i++)
            {
                num[step] *= 2;
                num[step] += mem[i];
                Serial.println(mem[i]);
            }
            resetMem();
            show(num[step++]);
        }
        else
        {
            sum = num[0] + num[1];
            Serial.print("sum = ");
            Serial.println(sum);
            show(sum);
        }

        Serial.print(num[0]);
        Serial.print(" ");
        Serial.println(num[1]);
    }
    else if (!buttonState[3])
    {
        pressed3 = 0;
    }

    if (buttonState[4] && !pressed4)
    {
        reset();
        pressed4 = 1;
    }
    else if (!buttonState[4])
    {
        pressed4 = 0;
    }
}