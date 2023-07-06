#include "deneyap.h"
#include <ESP32Servo.h>
//ELENENLER: D8, D4 , D0 ,D14 , D1
#define soayakpin D11
#define saayakpin D10
#define sodizpin D13
#define sadizpin D15
#define sobacakpin D12
#define sabacakpin D9

Servo soayak, saayak, sodiz, sadiz, sobacak, sabacak;

Servo servolar[6];

int adim = 0;

void setup() {
  pinMode(D4, INPUT_PULLUP);

  soayak.attach(soayakpin);
  saayak.attach(saayakpin);
  sodiz.attach(sodizpin);
  sadiz.attach(sadizpin);
  sobacak.attach(sobacakpin);
  sabacak.attach(sabacakpin);



  Serial.begin(115200);

  servolar[0] = sabacak;
  servolar[1] = sadiz;
  servolar[2] = saayak;
  servolar[3] = sobacak;
  servolar[4] = sodiz;
  servolar[5] = soayak;

  hepsi(90);
  //allTest();
}

void loop() {

  int jX = analogRead(A0);
  int jY = analogRead(A1);
  int buton = digitalRead(D4);

  Serial.print("jX: ");
  Serial.print(jX);
  Serial.print(" / jY: ");
  Serial.print(jY);
  Serial.print(" / buton: ");
  Serial.println(buton);


  if (jY > 2100 || jY < 1600) {

    int aci = ((jY / 4095.0) * 90.0) + 40;

    saayak.write(aci);
    soayak.write(aci);

    Serial.print("Sag sol dondur: ");
    Serial.println(aci);

    delay(100);
  } else {
    saayak.write(90);
    soayak.write(90);
  }


  if (jX > 3800) {
    //ileri();

    testTekIleri();


  } else if (jX < 200) {
    //geri();

    testTekGeri();

  } else {
    /*Serial.println("HEPSI 90");
    hepsi(90);
    delay(1000);*/
  }

  if (buton == 0) {
    hepsi(90);
    delay(50);
  }

  delay(250);
}

void testTekIleri() {

  if (adim + 1 <= 5) {

    adim++;

    Serial.print("Testing Servo ");
    Serial.println(adim);

    Serial.print("3 2 1 ");
    delay(1500);
    Serial.println("Lets gooo!");

    test(servolar[adim]);
  } else if (adim + 1 == 6) {
    Serial.print("Testing Servo ALL!");
    delay(1500);
    testAll(hepsi);
  }
}

void testTekGeri() {
  if (adim - 1 >= 0) {
    adim--;

    Serial.print("Testing Servo ");
    Serial.println(adim);

    Serial.print("3 2 1 ");
    delay(1500);
    Serial.println("Lets gooo!");

    test(servolar[adim]);

    Serial.println("TEST BITTI!");
  } else if (adim - 1 == -1) {
    Serial.print("Testing Servo SAG!");
    delay(1500);
    testAll(sag);

    Serial.print("Testing Servo SOL!");
    delay(1500);
    testAll(sol);
  }
}