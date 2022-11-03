// C++ code
//

int redPin = 9;
//int bright = 255;
//int bright = 0;
//int bright = 125;
int bright = 10;

void setup()
{
  pinMode(redPin, OUTPUT);
}

void loop()
{
  analogWrite(redPin,bright);
}