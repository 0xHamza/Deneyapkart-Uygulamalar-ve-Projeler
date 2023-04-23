/*  HAFTA 4 - GOZLE UYGULAMA 1.12 HCS04 Led Park Sensoru
 *  KONU: HCSR04 sensoru ile Led Park Sensoru
 *  Amac: HCSR04 ile, kutuphane kullanarak mesafe degerini oku ve mesafeye bagli ledleri yak.
 */
#include "deneyap.h"
#include <HCSR04.h>   // Kullanilacak kutuphane eklenir.

#define trigPin D0
#define echoPin D1

long sure;
float mesafe;

int LED_DIZISI[] = {D4,D5,D6,D7,D12,D13,D14,D15};

UltraSonicDistanceSensor mesafeSensoru(trigPin,echoPin);  // Mesafe sensorunu kutuphane ile tanimlariz.

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

  if(mesafe <= 5){                          // Mesafe <= 5 ise (1.) lambayi yak:
    digitalWrite(LED_DIZISI[0],HIGH);
    delay(50);
    digitalWrite(LED_DIZISI[0],LOW);
  }else if(mesafe <=10 && mesafe > 5){      // 5 < Mesafe <= 10 ise (1. 2.) lambalari yak:
    for(int j = 0; j<2; j++){
      digitalWrite(LED_DIZISI[j],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[j],LOW);
    }
  }else if(mesafe <=15 && mesafe > 10){     // 10 < Mesafe <= 15 ise (1. 2. 3.) lambalari yak:
    for(int k = 0; k<3; k++){
      digitalWrite(LED_DIZISI[k],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[k],LOW);
    }
  }else if(mesafe <=20 && mesafe > 15){     // 15 < Mesafe <= 20 ise (1. 2. 3. 4.) lambalari yak:
    for(int l = 0; l<4; l++){
      digitalWrite(LED_DIZISI[l],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[l],LOW);
    }
  }else if(mesafe <=25 && mesafe > 20){     // 20 < Mesafe <= 25 ise (1. 2. 3. 4. 5.) lambalari yak:
    for(int m = 0; m<5; m++){
      digitalWrite(LED_DIZISI[m],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[m],LOW);
    }
  }else if(mesafe <=30 && mesafe > 25){     // 25 < Mesafe <= 30 ise (1. 2. 3. 4. 5. 6.) lambalari yak:
    for(int n = 0; n<6; n++){
      digitalWrite(LED_DIZISI[n],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[n],LOW);
    }
  }else if(mesafe <=35 && mesafe > 30){     // 30 < Mesafe <= 35 ise (1. 2. 3. 4. 5. 6. 7.) lambalari yak:
    for(int p = 0; p<7; p++){
      digitalWrite(LED_DIZISI[p],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[p],LOW);
    }
  }else {
    for(int r = 0; r<8; r++){              // 35 < Mesafe ise (1. 2. 3. 4. 5. 6. 7. 8.) lambalari yak:
      digitalWrite(LED_DIZISI[r],HIGH);
      delay(50);
      digitalWrite(LED_DIZISI[r],LOW);
    }
  }
}
