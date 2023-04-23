/*  HAFTA 4 - GOZLE UYGULAMA 1.12 HCS04 Led Park Sensoru 2
 *  KONU: HCSR04 sensoru ile Led Park Sensoru
 *  Amac: Bu kod onceki uzun kodun fonskiyonlar sayesinde dahada optimize edilmis bir halidir.
 */
#include "deneyap.h"
#include <HCSR04.h>   // Kullanilacak HCSR04 kutuphanesi eklenir.

#define trigPin D0
#define echoPin D1

long sure;
float mesafe;

int LED_DIZISI[] = {D4,D5,D6,D7,D12,D13,D14,D15};

UltraSonicDistanceSensor mesafeSensoru(trigPin,echoPin);  // Mesafe sensorunu kutuphane ile tanimlariz.

void yakLambalari(int lambaSayisi){           //SUREKLI TEKRAR EDEN AYNI ISLEVI YAPAN FOR DONGULERI BIR FONKSIYON ILE CAGIRILARAK OPTIMIZE EDILIR
  for (int i = 0; i < lambaSayisi; i++){
    digitalWrite(LED_DIZISI[i],HIGH);
    delay(50);
    digitalWrite(LED_DIZISI[i],LOW);
  }
}

void setup(){
  for(int i = 0;i<8;i++){
    pinMode(LED_DIZISI[i], OUTPUT);
  } 
  Serial.begin(115200);
}

void loop(){
  mesafe = mesafeSensoru.measureDistanceCm();// Mesafe kutuphanesi araciligi ile mesafe okunur.

  Serial.print("Mesafe: ");
  Serial.println(mesafe);

  if(mesafe <= 5){                     // (Mesafe <= 5) ise (1.) lambayi yak:             
    yakLambalari(1);
  }else if(mesafe <=10 && mesafe > 5){   // (5 < Mesafe <= 10) ise (1. 2.) lambalari yak:
    yakLambalari(2);
  }else if(mesafe <=15 && mesafe > 10){ // (10 < Mesafe <= 15) ise (1. 2. 3.) lambalari yak:
    yakLambalari(3);
  }else if(mesafe <=20 && mesafe > 15){// (15 < Mesafe <= 20) ise (1. 2. 3. 4.) lambalari yak:
    yakLambalari(4);
  }else if(mesafe <=25 && mesafe > 20){// (20 < Mesafe <= 25) ise (1. 2. 3. 4. 5.) lambalari yak:
    yakLambalari(5);
  }else if(mesafe <=30 && mesafe > 25){// (25 < Mesafe <= 30) ise (1. 2. 3. 4. 5. 6.) lambalari yak:
    yakLambalari(6);
  }else if(mesafe <=35 && mesafe > 30){// (30 < Mesafe <= 35) ise (1. 2. 3. 4. 5. 6. 7.) lambalari yak:
    yakLambalari(7);
  }else{                               // (35 < Mesafe) ise (1. 2. 3. 4. 5. 6. 7. 8.) lambalari yak:                                 
    yakLambalari(8);
  }
}
