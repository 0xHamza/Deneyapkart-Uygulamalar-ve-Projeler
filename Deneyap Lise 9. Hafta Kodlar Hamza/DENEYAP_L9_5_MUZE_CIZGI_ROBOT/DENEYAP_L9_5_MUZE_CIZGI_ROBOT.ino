#include "deneyap.h"
#include "analogWrite.h"

#define SensorSol A0
#define SensorOrta A1
#define SensorSag A2

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 20, 4);

int hiz = 125;
int kosul = 0;

void setup() {
  pinMode (SensorSol, INPUT);
  pinMode (SensorOrta, INPUT);
  pinMode (SensorSag, INPUT);

  Serial.begin (115200);
  Serial.println("Cizgi Sensoru Test");
  delay (2000);

  pinMode (motorR1, OUTPUT);
  pinMode (motorR2, OUTPUT);
  pinMode (motorL1, OUTPUT);
  pinMode (motorL2, OUTPUT);

}
void loop() {
  Serial.print (digitalRead(SensorSol));
  Serial.print(", ");
  Serial.print (digitalRead(SensorOrta));
  Serial.print (", ");
  Serial.println (digitalRead(SensorSag));
  delay (300);

  if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0) {
    ileri ();
  }
  if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1) {
    sag();
  }
  if (digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0) {
    sol ();
  }

  if (digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1) {
    dur ();
    kosul = kosul + 1;

    if (kosul == 1) {
      lcd.init();
      lcd.backlight ();
      lcd.print("1. eser bilgisi");
      lcd.blink();
      delay (15000);
      lcd.noBlink ();
      lcd.clear();
      lcd.noDisplay();
      delay (2000);
      lcd.noBacklight ();
      delay (2000);
      ileri ();
      delay (1500);
    }

    if (kosul > 1) {
      lcd.init();
      lcd.backlight ();
      lcd.print("2. eser bilgisi");
      lcd.blink();
      delay (20000);
      lcd.noBlink();
      lcd.clear();
      lcd.home ();
      lcd.print("Gule Gule...");
      delay (2000);
      lcd.noDisplay();
      delay (2000);
      lcd.noBacklight ();
      delay (2000);
    }
  }

  if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0) {
    dur();
  }
}


void ileri() {
  digitalWrite (motorR1, HIGH);
  digitalWrite (motorR2, LOW);
  analogWrite (motorRE, hiz);
  digitalWrite (motorL1, HIGH);
  digitalWrite (motorL2, LOW);
  analogWrite (motorLE, hiz);
}
void sag() {
  digitalWrite (motorR1, HIGH);
  digitalWrite (motorR2, LOW);
  analogWrite (motorRE, 125);
  digitalWrite (motorL1, HIGH);
  digitalWrite (motorL2, LOW);
  analogWrite (motorLE, 150);
}
void sol () {
  digitalWrite (motorR1, HIGH);
  digitalWrite (motorR2, LOW);
  analogWrite (motorRE, 150);
  digitalWrite (motorL1, HIGH);
  digitalWrite (motorL2, LOW);
  analogWrite (motorLE, 125);
}
void dur () {
  digitalWrite (motorR1, HIGH);
  digitalWrite (motorR2, LOW);
  analogWrite (motorRE, 0);
  digitalWrite (motorL1, HIGH);
  digitalWrite (motorL2, LOW);
  analogWrite (motorLE, 0);
}
