#include <analogWrite.h>

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7
int hiz = 150;


void setup() {
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  for(int i=0; i<4;i++){
	ileri();
	delay(1500);
	dur();
	delay(1500);
	
	sag();
	delay(1500);
	dur();
	delay(1500);
  }
}

void ileri (){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, hiz);
}

void sag (){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, 0);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, hiz);
}

void sol (){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, 0);
}

void dur (){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, 0);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, 0);
}

void geri (){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  analogWrite(motorLE, hiz);
}
