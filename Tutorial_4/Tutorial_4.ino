// C++ code
//

int redLED=8;
float pi=3.14;
int dit=250;
int dah=700;
int longW=2000;

String myName="Khris Bharmmano"

void setup()
{
  pinMode(redLED, OUTPUT);
}

void loop()
{
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  
  digitalWrite(redLED, HIGH);
  delay(dah);
  digitalWrite(redLED, LOW);
  delay(dah);
  
  digitalWrite(redLED, HIGH);
  delay(dah);
  digitalWrite(redLED, LOW);
  delay(dah);
  
  digitalWrite(redLED, HIGH);
  delay(dah);
  digitalWrite(redLED, LOW);
  delay(dah);
  
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  
  delay(longW);
}