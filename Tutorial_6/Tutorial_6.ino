// C++ code
//

int pin_LED1 = 2;
int pin_LED2 = 3;
int pin_LED3 = 4;
int pin_LED4=  5;
int slow = 2000;

void setup()
{
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  pinMode(pin_LED3, OUTPUT);
  pinMode(pin_LED4, OUTPUT);
}

void loop()
{
  // Output = 0
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 1
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 2
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 3
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 4
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 5
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 6
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 7
  digitalWrite(pin_LED1,LOW);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 8
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 9
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 10
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 11
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,LOW);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 12
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 13
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,LOW);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
  
  // Output = 14
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,LOW);
  delay(slow);
  
  // Output = 15
  digitalWrite(pin_LED1,HIGH);
  digitalWrite(pin_LED2,HIGH);
  digitalWrite(pin_LED3,HIGH);
  digitalWrite(pin_LED4,HIGH);
  delay(slow);
}