#include "BluetoothSerial.h"
#include "analogWrite.h"

#define MotorR1 D1
#define MotorR2 D4
#define MotorRE D0
#define MotorL1 D6
#define MotorL2 D5
#define MotorLE D7

int hiz = 255;
char veri;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("DeneyapKart");
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
}
void loop() {

  while (SerialBT.available())
    veri = (char)SerialBT.read();


  switch (veri) {
    case 'W':
      {
        digitalWrite(MotorR1, HIGH);
        digitalWrite(MotorR2, LOW);
        analogWrite(MotorRE, hiz);

        digitalWrite(MotorL1, HIGH);
        digitalWrite(MotorL2, LOW);
        analogWrite(MotorRE, hiz);
        break;
      }
    case 'S': {
        digitalWrite(MotorR1, LOW);
        digitalWrite(MotorR2, HIGH);
        analogWrite(MotorRE, hiz);

        digitalWrite(MotorL1, LOW);
        digitalWrite(MotorL2, HIGH);
        analogWrite(MotorRE, hiz);
        break;
      }
    case 'A':
      {
        digitalWrite(MotorR1, HIGH);
        digitalWrite(MotorR2, LOW);
        analogWrite(MotorRE, hiz);

        digitalWrite(MotorL1, LOW);
        digitalWrite(MotorL2, LOW);
        analogWrite(MotorRE, hiz);
        break;
      }
    case 'D':
      {
        digitalWrite(MotorR1, LOW);
        digitalWrite(MotorR2, LOW);
        analogWrite(MotorRE, hiz);

        digitalWrite(MotorL1, HIGH);
        digitalWrite(MotorL2, LOW);
        analogWrite(MotorRE, hiz);
        break;
      }
    case 'F':
      {
        digitalWrite(MotorR1, LOW);
        digitalWrite(MotorR2, LOW);
        analogWrite(MotorRE, hiz);

        digitalWrite(MotorL1, LOW);
        digitalWrite(MotorL2, LOW);
        analogWrite(MotorRE, hiz);
        break;
      }
  }
}
