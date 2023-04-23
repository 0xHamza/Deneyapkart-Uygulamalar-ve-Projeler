#include "BluetoothSerial.h"
#include "analogWrite.h"

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7

int hiz = 150;
char veri;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("DeneyapToggAraba");

  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);

  Serial.println("Araba baslatiliyor!");
  SerialBT.println("Araba baslatiliyor!");
}

void loop() {

  if(SerialBT.available()){
    veri = (char) SerialBT.read();

    switch (veri) {
      case 'F': {
        Serial.println("ILERI");
        SerialBT.println("ILERI");
        ileri();
        break;
      }
      case 'B': {
        Serial.println("GERI");
        SerialBT.println("GERI");
        geri();
        break;
      }
      case 'L': {
        Serial.println("SOL");
        SerialBT.println("SOL");
        sol();
        break;
      }
      case 'R': {
              Serial.println("SAG");
        SerialBT.println("SAG");
        sag();
        break;
      }
    }
    delay(100); //bu süreyi uzatabilirsiniz
  }else{
    dur();
  }
}

void ileri() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, hiz);
}

void geri() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  analogWrite(motorLE, hiz);
}

void sag() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, 0);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, hiz);
}

void sol() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, 0);
}

void dur() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, 0);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, 0);
}
