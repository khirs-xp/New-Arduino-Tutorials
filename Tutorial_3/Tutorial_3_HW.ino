// C++ code
//
int Count1 = 0;
int Count2 = 0;
int Count3 = 0;
  
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  while (Count1 < 5)
  {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    Count1++;
  }
  Count1 = 0;
  while (Count2 < 5)
  {
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
    Count2++;
  }
  Count2= 0;
  while (Count3 < 5)
  {
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
    Count3++;
  }
  Count3=0;
}