/*2.1.5 Uygula: LDR Sensörünün ANALOG GİRİŞİ ile Servo Motor Kontrolü
-> Analog çıkışta okunan değer ortamdaki ışık şiddetini vermektedir. Bu uygulamada Uygulama da farklı
   olarak gösterge ibresinin ara değerleri de göstermesi sağlanacaktır. 
   Sağ ve sol LDR sensörlerinin her ikisine düşen ışık yüzdesine bağlı olarak ibre konumlandırılacaktır.
*/

#include <Deneyap_Servo.h>  //Servo motor kütüphanesinin programa eklenmesi, calismazsa: #include "ESP32Servo.h"

#define SERVOPIN D0  //servo motor bağlantısı
#define L1_pin A0    //sağ ışık sensörü bağlantısı, Analog Giriş 0
#define L2_pin A1    //sol ışık sensörü bağlantısı, Analog Giriş 1

Servo myservo;

int sensor1, sensor2;
int pos = 0;

void setup() {
  myservo.attach(SERVOPIN);
  pinMode(L1_pin, INPUT);
  pinMode(L2_pin, INPUT);
}

void loop() {

  sensor1 = (1024 - analogRead(L1_pin)) * 90 / 1024;  //ışık miktarının analog değer olarak tespiti
  sensor2 = (1024 - analogRead(L2_pin)) * 90 / 1024;

  if (sensor1 > sensor2)  //sağ LDR’ye düşen ışık > sol LDR’ye düşen ışık
  {
    pos = (sensor1 - sensor2) + 90;  //LDRlere düşen ışık miktarı farkına göre konum belirlenir.
    myservo.write(pos);
  } else if (sensor2 > sensor1) 
  {
    pos = -1 * (sensor2 - sensor1) + 90;
    myservo.write(pos);
  }
  delay(5);
}
