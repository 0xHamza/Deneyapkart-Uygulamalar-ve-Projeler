#include <analogWrite.h>

int enA = D13;
int in1 = D14;
int in2 = D15;
int buttonPin = D12;
int potPin = A0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int hiz = analogRead(potPin) / 4;
  boolean kontrol = digitalRead(buttonPin);

  if(kontrol == true){
    //DUZ DONER
    analogWrite(enA, hiz);
    digitalWrite(in1, HIGH); //HIGH
    digitalWrite(in2, LOW); //LOW
    delay(5000);
    //DURUR
    analogWrite(enA, 0); //LOW
    delay(3000);
    //TERSINE DONER
    analogWrite(enA, hiz);
    digitalWrite(in1, 0); //LOW
    digitalWrite(in2, 1); //HIGH
    delay(5000);
    //DURUR
    analogWrite(enA, LOW); //LOW
    delay(3000);
  }
}
