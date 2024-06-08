#include "ESP32Servo.h"

#define potPin A0
#define servo1Pin D14


Servo servo1;


int potdegeri=0;

void setup() {
  Serial.begin(115200);
  servo1.attach(servo1Pin);
}

void loop() {
  potdegeri = analogRead(potPin);
  potdegeri = potdegeri/4095*180;
  servo1.write(potdegeri);  
  Serial.println(potdegeri);
  delay(10);
}
