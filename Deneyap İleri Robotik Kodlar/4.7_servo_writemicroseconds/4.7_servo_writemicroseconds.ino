#include <ESP32Servo.h>               // Eğer bu kütüphane çalışmaz ise <Deneyap_Servo.h> kütüphanesi denenebilir.

Servo servoMotor;

void setup() {
  servoMotor.attach(D14);
  servoMotor.writeMicroseconds(1500);   //0-3000 aralıgı 0-180 aralıgına denk geldiginden 90 dereceye ayarlanır
}

void loop() {
  for (int i = 0; i <= 3000; i++) {
    servoMotor.writeMicroseconds(i);    // servo motor hareket ettirilir
    delay(15);                        // 15 milisaniye bekle
  }
}
