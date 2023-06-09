#include <ESP32Servo.h>                 // Eğer bu kütüphane çalışmaz ise <Deneyap_Servo.h> kütüphanesi denenebilir.

Servo servoMotor;

void setup() {
  servoMotor.attach(D14);
}

void loop() {
  
  for (int i = 0; i <= 180; i++) {
    servoMotor.write(i);               
    delay(15);
  }

  delay(1000);
  
  for (int i = 0; i <= 180; i++) {
    servoMotor.writeMicroseconds(i);  
    delay(15);                        
  }

  delay(3000);
}
