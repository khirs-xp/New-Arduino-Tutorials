int redPin = 13;
int greenPin = 12;
int yellowPin = 11;
int count = 0;

int slow = 1000;

int bright[] = {255,125,62,31};
int dark = 0;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop()
{
  analogWrite(redPin,bright[0]);
  analogWrite(greenPin,bright[0]);
  analogWrite(yellowPin,bright[0]);
  delay(slow);
  
  analogWrite(redPin,bright[1]);
  analogWrite(greenPin,bright[1]);
  analogWrite(yellowPin,bright[1]);
  delay(slow);
  
  analogWrite(redPin,bright[2]);
  analogWrite(greenPin,bright[2]);
  analogWrite(yellowPin,bright[2]);
  delay(slow);
  
  analogWrite(redPin,bright[3]);
  analogWrite(greenPin,bright[3]);
  analogWrite(yellowPin,bright[3]);
  delay(slow);
}