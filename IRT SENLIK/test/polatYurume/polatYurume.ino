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
  for(int i = 0; i<180; i++){

  saayak.write(i);
  sabacak.write(i);
  sadiz.write(i);
  soayak.write(i);
  sabacak.write(i);
  sadiz.write(i);
  delay(15);

   if(i==90){
     delay(5000);
    }
 }
  for(int i = 180; i>0; i--){

  saayak.write(i);
  sabacak.write(i);
  sadiz.write(i);
  soayak.write(i);
  sabacak.write(i);
  sadiz.write(i);
  delay(15);

   if(i==90){
     delay(5000);
    }
 }


}
