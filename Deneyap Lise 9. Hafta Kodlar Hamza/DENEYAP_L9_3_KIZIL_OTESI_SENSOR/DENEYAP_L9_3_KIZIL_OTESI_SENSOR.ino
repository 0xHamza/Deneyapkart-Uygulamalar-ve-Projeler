#include "deneyap.h"
#include "analogWrite.h"

#define SensorSol A0
#define SensorOrta A1
#define SensorSag A2

void setup() {
  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);

  Serial.begin(115200);
  Serial.println("Cizgi Sensoru Deneme");
  delay(2000);
}

void loop() {
  Serial.print(digitalRead(SensorSol));
  Serial.print(", ");
  Serial.print(digitalRead(SensorOrta));
  Serial.print(", ");
  Serial.println(digitalRead(SensorSag));
  delay(300);
}
