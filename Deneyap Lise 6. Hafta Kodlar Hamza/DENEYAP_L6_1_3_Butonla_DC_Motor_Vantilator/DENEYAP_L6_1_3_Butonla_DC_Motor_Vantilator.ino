#include <analogWrite.h>

#define motor D0
#define button D1

int deger = 0;
int eski_deger = 0;
int durum = 0;

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  deger = digitalRead(button);

  if(deger == HIGH && eski_deger == LOW) {
    durum = 1 - durum;
  }

  eski_deger = deger;

  if(durum==1) {
    //analogWrite(motor,255);
    digitalWrite(motor, HIGH);
  }else {
    //analogWrite(motor,0);
    digitalWrite(motor, LOW);
  }
}
