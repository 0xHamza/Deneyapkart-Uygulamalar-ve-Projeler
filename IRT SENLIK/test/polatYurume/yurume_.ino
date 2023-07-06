#include "deneyap.h"
#include <ESP32Servo.h>
//ELENENLER: D8, D4 , D0 ,D14 , D1
#define soayakpin D12
#define saayakpin D13
#define sodizpin D11
#define sadizpin D15
#define sobacakpin D10
#define sabacakpin D9

Servo soayak, saayak, sodiz, sadiz, sobacak, sabacak;

void setup() {
  soayak.attach(soayakpin);
  saayak.attach(saayakpin);
  sodiz.attach(sodizpin);
  sadiz.attach(sadizpin);
  sobacak.attach(sobacakpin);
  sabacak.attach(sabacakpin);
}

void loop() {

  int jX = analogRead(A0);
  if (jX > 3800)
  {
    Serial.println("ILERI Sag");
    saayak.write(90);
    sabacak.write(120);
    sadiz.write(60);
    delay(500);

    Serial.println("ILERI Sol");
    soayak.write(90);
    sobacak.write(120);
    sodiz.write(60);
    delay(500);
  } else if (jX < 200) {
    Serial.println("GERI Sag");
    saayak.write(90);
    sabacak.write(60);
    sadiz.write(120);
    delay(500);

    Serial.println("GERI Sol");
    soayak.write(90);
    sobacak.write(60);
    sodiz.write(120);
    delay(500);
  } else {
    Serial.println("DUR SAG");
    saayak.write(90); delay(100);
    sabacak.write(90); delay(100);
    sadiz.write(90);
    delay(500);

    Serial.println("DUR Sol");
    soayak.write(90); delay(100);
    sobacak.write(90); delay(100);
    sodiz.write(90);
    delay(500);
  }
}
