int pin_1 = 13;
int pin_2 = 12;
int pin_3 = 11;

int slow = 1000;

void setup()
{
  
}

void loop()
{
  // LED 1
  pinMode(pin_1,OUTPUT);
  digitalWrite(pin_1,HIGH);
  pinMode(pin_2,OUTPUT);
  digitalWrite(pin_2,LOW);
  pinMode(pin_3,INPUT);
  
  delay(slow);
  
  // LED 2
  pinMode(pin_1,OUTPUT);
  digitalWrite(pin_1,LOW);
  pinMode(pin_2,OUTPUT);
  digitalWrite(pin_2,HIGH);
  pinMode(pin_3,INPUT);
  
  delay(slow);
  
  // LED 3
  pinMode(pin_1,INPUT);
  pinMode(pin_2,OUTPUT);
  digitalWrite(pin_2,HIGH);
  pinMode(pin_3,OUTPUT);
  digitalWrite(pin_3,LOW);
  
  delay(slow);
  
  // LED 4
  pinMode(pin_1,INPUT);
  pinMode(pin_2,OUTPUT);
  digitalWrite(pin_2,LOW);
  pinMode(pin_3,OUTPUT);
  digitalWrite(pin_3,HIGH);
  
  delay(slow);
  
  // LED 5
  pinMode(pin_1,OUTPUT);
  digitalWrite(pin_1,HIGH);
  pinMode(pin_2,INPUT);
  pinMode(pin_3,OUTPUT);
  digitalWrite(pin_3,LOW);
  
  delay(slow);
  
  // LED 6
  pinMode(pin_1,OUTPUT);
  digitalWrite(pin_1,LOW);
  pinMode(pin_2,INPUT);
  pinMode(pin_3,OUTPUT);
  digitalWrite(pin_3,HIGH);
  
  delay(slow);
  
}