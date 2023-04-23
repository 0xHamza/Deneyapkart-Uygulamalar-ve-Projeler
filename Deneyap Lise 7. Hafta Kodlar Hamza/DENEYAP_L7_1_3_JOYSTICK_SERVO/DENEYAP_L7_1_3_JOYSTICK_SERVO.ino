//SERVOYU KULLANABILMEMIZI SAGLAYAN KUTUPHANE EKLENMELI
#include <ESP32Servo.h>
//#include <Deneyap_Servo.h> 

const int xPin = A0; // Joystick'un X pininin tanımlanması
const int servoPin = D9; // Servo motorun bağlı olduğu pin
Servo servo; // Servo motor nesnesi

void setup() {
  Serial.begin(9600); // Seri haberleşme hızını 9600 baud olarak ayarla
  servo.attach(servoPin); // Servo motor pinini çıkış olarak ayarla
}

void loop() {

  int xValue = analogRead(xPin);   // Joystick'ten X ekseninden okunan değerleri oku
  int servoAngleX = map(xValue, 0, 1023, -90, 90);  // X değerini -90 ile 90 aralığına dönüştür

  servo.write(servoAngleX + 90);  // Servo motoru hareket ettir

  Serial.print("X değeri: ");
  Serial.println(xValue);
  Serial.print("Servo değeri: ");
  Serial.println(servoAngleX);
  delay(100);
}
