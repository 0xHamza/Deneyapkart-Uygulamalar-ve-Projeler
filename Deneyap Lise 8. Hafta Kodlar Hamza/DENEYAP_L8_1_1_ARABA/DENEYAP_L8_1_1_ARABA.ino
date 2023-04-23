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
  
  Serial.println("ILERI");
  ileri();
  delay(2000);
  Serial.println("ILERI DURDU");
  dur();
  delay(2000);

  Serial.println("GERI");
  geri();
  delay(2000);
  dur();
  Serial.println("GERI DURDU");
  delay(2000);
  

  Serial.println("SAG");
  sag();
  delay(2000);
  Serial.println("SAG DURDU");
  dur();
  delay(2000);

  Serial.println("SOL");
  sol();
  delay(2000);
  Serial.println("SOL DURDU");
  dur();
  delay(2000);
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
