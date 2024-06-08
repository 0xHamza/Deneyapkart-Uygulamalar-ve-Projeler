/*
*   ServoMotorDondurme örneği, 
*   D9 pinine bağlanan servo motorun milinin 0-180 derece aralığında 15 derecelik adımlarla ileri geri dönmektedir. 
*/
#include <ESP32Servo.h>  // Deneyap Servo kütüphanesi eklenmesi

Servo myservo;  // Servo için class tanımlanması
Servo myservo2;
Servo myservo3;
Servo myservo4;

void setup() {
  myservo.attach(D12);  // Servo motorun D9 pinine bağlanması   /*attach(pin, channel=0, freq=50, resolution=12) olarak belirlenmiştir. Kullandığınız motora göre değiştirebilirsiniz */
  myservo2.attach(D13); 
  myservo3.attach(D14); 
  myservo4.attach(D15); 
  


}

void loop() {
  for (int pos = 0; pos <= 180; pos += 15) {  // 0'dan 180 dereceye 15 derece ile gitmesi
    myservo.write(pos);                   // servo motor milinin pos değerindeki dereceye gitmesi
    myservo2.write(pos);  
    myservo3.write(pos);  
    myservo4.write(pos);  
    
    
    delay(500);
  }
  for (int pos = 180; pos >= 0; pos -= 15) {  // 180'dan 0 dereceye 15 derece ile gitmesi
    myservo.write(pos);                   // servo motor milinin pos değerindeki dereceye gitmesi
    myservo2.write(pos);  
    myservo3.write(pos);  
    myservo4.write(pos);  
    delay(500);
  }
}
