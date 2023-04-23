/*  HAFTA 4 - GOZLE UYGULAMA 1.12 HCSR04
 *  KONU: HCSR04 sensoru ile mesafe olcme.
 *  Amac: HCSR04 ile, kutuphane kullanmadan mesafeyi okuyup ekranda yazdir.
 */
#include "deneyap.h"          

#define trigPin D0
#define echoPin D1

int sure, mesafe;

void setup() {
  pinMode(trigPin,OUTPUT);    
  pinMode(echoPin,INPUT);    

  Serial.begin(115200);
}

void loop() {
  // HCSR04 mesafe sensörü için tetik pinini hazırla ve mesafeyi hesapla:
  digitalWrite(trigPin, LOW);     // Tetik pinini düşük seviyede ayarla, bu sensörün çalışması için gerekli
  delayMicroseconds(2);           // 2 mikrosaniyelik bir bekleme yap (tetikleme düzgün çalışması için)
  digitalWrite(trigPin, HIGH);    // Tetik pinini yüksek seviyede ayarla, bu sensörün ölçüm yapmasını başlatır
  delayMicroseconds(10);          // 10 mikrosaniyelik bir bekleme yap (ölçüm tamamlanması için)
  digitalWrite(trigPin, LOW);     // Tetik pinini tekrar düşük seviyede ayarla, ölçüm tamamlandıktan sonra sensörü devre dışı bırakır
    
  sure = pulseIn(echoPin, HIGH);  // Eko sinyalinin gelme süresini ölç, bu değer mesafeyi hesaplamak için kullanılacak
  mesafe = sure/58;               // Eko sinyal süresini kullanarak mesafeyi hesapla (mesafe = süre / hız = süre / 58) (58 yerine sure*0,034/2 de kullanilabilirdi)

  if(mesafe >= 200 || mesafe <= 0)
  {
    Serial.println("Guvenli mesafe");
  }else{
    Serial.println("Uzaklik: ");
    Serial.print(mesafe);
    Serial.println(" cm");
  }
  delay(500);
}
