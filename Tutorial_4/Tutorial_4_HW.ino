int redLED = 13;
int greenLED = 12;
int blueLED = 11;

int fast_sign = 250;
int slow_sign = 500;
int slowest_sign = 1000;

int count = 0;

void setup()
{
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
}

void loop()
{
  while(count < 5)
  {
  	digitalWrite(redLED,HIGH);
    delay(fast_sign);
    digitalWrite(redLED,LOW);
    delay(fast_sign);
    count++;
  }
  count = 0;
  while(count < 10)
  {
  	digitalWrite(greenLED,HIGH);
    delay(slow_sign);
    digitalWrite(greenLED,LOW);
    delay(slow_sign);
    count++;
  }
  count = 0;
  while(count < 15)
  {
  	digitalWrite(blueLED,HIGH);
    delay(slowest_sign);
    digitalWrite(blueLED,LOW);
    delay(slowest_sign);
    count++;
  }
  count = 0;
}