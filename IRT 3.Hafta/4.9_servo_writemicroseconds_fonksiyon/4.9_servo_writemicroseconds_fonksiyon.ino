#include <ESP32Servo.h>               // Eğer bu kütüphane çalışmaz ise <Deneyap_Servo.h> kütüphanesi denenebilir.

Servo servoMotor;

void setup() {
  servoMotor.attach(D14);
}

void loop() {
  for (int i = 0; i <= 180; i++) {
    writeAngleToMicro(i);                             // servo motor 0-180 derece aralığında hareket ettirilir
    delay(15);                                        // 15 milisaniye bekle
  }
  
  for (int i = 180; i >= 0; i--) {
    writeAngleToMicro(i);                                // servo motor 180-0 derece aralığında hareket ettirilir
    delay(15);                                            // 15 milisaniye bekle
  }
}

void writeAngleToMicro(int derece) {
  int pulseWidth = derece * 3000 / 180;               // 0-180 derece aralığındaki açı değeri mikrosaniye sinyal değerine dönüştürülür
  servoMotor.writeMicroseconds(pulseWidth);            // servo motor hareket ettirilir
}
