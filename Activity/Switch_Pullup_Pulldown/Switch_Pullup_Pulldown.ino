const int BUTTON_1 = 2;
const int BUTTON_2 = 3;
const int BUTTON_3 = 4;

const int LED_1 = 11;
const int LED_2 = 12;
const int LED_3 = 13;

int led1_flag =0;
int led2_flag =0;
int led3_flag =0;

void setup() {

  Serial.begin(9600);
  
  pinMode(BUTTON_1,INPUT); //
  pinMode(BUTTON_2,INPUT);
  pinMode(BUTTON_3,INPUT_PULLUP);
  
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
}

void loop() {

  int READ_SWICTH1 = digitalRead(BUTTON_1);
  int READ_SWICTH2 = digitalRead(BUTTON_2);
  int READ_SWICTH3 = digitalRead(BUTTON_3);

  if (READ_SWICTH1 == HIGH){
     
     if(led1_flag == 0){
      led1_flag = 1;
      digitalWrite(LED_1,HIGH);
     }
     else{
      led1_flag = 0;
      digitalWrite(LED_1,LOW);
     }
     delay(200);
  }

  if (READ_SWICTH2 == LOW){
     
     if(led2_flag == 0){
      led2_flag = 1;
      digitalWrite(LED_2,HIGH);
     }
     else{
      led2_flag = 0;
      digitalWrite(LED_2,LOW);
     }
     delay(200);
  }

  if (READ_SWICTH3 == LOW){
     
     if(led3_flag == 0){
      led3_flag = 1;
      digitalWrite(LED_3,HIGH);
     }
     else{
      led3_flag = 0;
      digitalWrite(LED_3,LOW);
     }
     delay(200);
  }
}