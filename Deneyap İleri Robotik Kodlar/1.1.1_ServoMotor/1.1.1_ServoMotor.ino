/*
*   ServoMotor örneği, Servo motorları hareket ettirmek için gereken PWM pinleri deneyap kartın butun Dijital pinlerinden desteklenmektedir bu yüzden bağlantıda hehangi bir dijital pin kullanılabilir.
*   D15 pinine bağlanan servo motorun mili 0 deredeceden 180 dereceye dönmektedir.
*/

#include <Deneyap_Servo.h>      // Deneyap Servo kütüphanesi eklenmesi
//#include <ESP32Servo.h>       //Ustteki kutuphane calismazsa bu kullanılabilir

Servo deney;                  // Servo için class tanımlanması

void setup() {  
  deney.attach(D15);           // Servo motorun D9 pinine bağlanması  /*attach(pin, channel=0, freq=50, resolution=12) olarak belirlenmiştir. Kullandığınız motora göre değiştirebilirsiniz */
}

void loop() { 
  deney.write(0);            // Servo motorun milinin 60 derece dönmesi
  delay(1000);
  deney.write(180);
  delay(1000);
}
