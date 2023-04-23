/*  HAFTA 4 - GOZLE UYGULAMA 1.12 HCS04 Led Park Sensoru 3
 *  KONU: HCSR04 sensoru ile Led Park Sensoru
 *  Amac: Bu kod onceki uzun kodun fonskiyonlar sayesinde dahada optimize edilmis bir halinin, 
 *        IF kosullarinin matematize edilerek cok daha optimize edilmis bir halidir.
 */
#include "deneyap.h"
#include <HCSR04.h>   // Kullanilacak HCSR04 kutuphanesi eklenir.
#include <math.h>      // ceil() fonksiyonunu kullanabilmek icin bu kutphane eklenmeli

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

  int yanacakLedSayisi = ceil(mesafe / 5.0);  

  if(yanacakLedSayisi > 8){
    yanacakLedSayisi = 8;
  }
  
  yakLambalari(yanacakLedSayisi);
}


 /*  Bir onceki kodda asagidaki if kosullari vardi ve 8 tane kosulun degerinin kontrolu if le saglamak kodun performansini dusurmekte.
    *  Eger Mesafeye bagli yanacak led sayisini fromulize edersek bu if probleminden kurtuluruz! 

         (Mesafe <= 5)       ise (1.) lambayi yak: Lamba sayisi 1
         (5 < Mesafe <= 10)  ise (1. 2.) lambalari yak: Lamba sayisi 2
         (10 < Mesafe <= 15) ise (1. 2. 3.) lambalari yak: Lamba sayisi 3
         (15 < Mesafe <= 20) ise (1. 2. 3. 4.) lambalari yak: Lamba sayisi 4
         (20 < Mesafe <= 25) ise (1. 2. 3. 4. 5.) lambalari yak: Lamba sayisi 5
         (25 < Mesafe <= 30) ise (1. 2. 3. 4. 5. 6.) lambalari yak: Lamba sayisi 6
         (30 < Mesafe <= 35) ise (1. 2. 3. 4. 5. 6. 7.) lambalari yak: Lamba sayisi 7
         (35 < Mesafe)       ise (1. 2. 3. 4. 5. 6. 7. 8.) lambalari yak: Lamba sayisi 8

    *  If kosulumuzdan anlasilan mesafeye bagli yanacak led sayisi belirleniyor.
    *  Yanacak led sayisi, mesafe degerinin 5 rakamının katlarına bagli 5er 5er artan sekilde oldugunu goruyoruz.
    *  Ayrica mesafe 0-40 cm araliginda oldugunda 8 adet lambadan uygun sayida yakilir, mesafe 35 den buyukse hepsi yanar
    *  
    *  ÇÖZÜM:
    *   Mesade degerimizin 5e bolumu bize neyi verir? 
    *       Ornek: mesafe 10 ise 10/5 = 2
    *       Ornek: mesafe 5 ise 5/5 = 1
    *       Ornek: mesafe 20 ise 20/5 = 4
    *       Ornek: mesafe 40 ise 40/5 = 8
    *  Bu sekilde bakarsak biraz cozume yaklastik gibi. Peki mesafe tam bolunmez sagidaki gibi sonuclar gelebilir! 
    *       Ornek: mesafe 2 ise ? 2/5 = 0.4            0.4 Tane lamba yansin diyemeyiz dogru cevabimiz 1 olmaliydi
    *       Ornek: mesafe 2 ise ? 8/5 = 1.6            1.6 Tane lamba yansin diyemeyiz dogru cevabimiz 2 olmaliydi
    *       Ornek: mesafe 29 ise ? 29/5 = 5.8          5.8 Tane lamba yansin diyemeyiz dogru cevabimiz 6 olmaliydi
    *       Ornek: mesafe 37 ise ? 37/5 = 7.4          7.4 Tane lamba yansin diyemeyiz dogru cevabimiz 8 olmaliydi
    * Formulumuz 5e tam bolunmeyen sayilarda ondalikli yanlis degerler donduruyor bunu cozmek icin:
    * Bulunan ondalikli sayilarimizi bir ust basamga yuvarlarsak ne oldugna bakin:
    *     uste yuvarla (0.4) = 1
    *     uste yuvarla (1.6) = 2
    *     uste yuvarla (5.8) = 1
    *     uste yuvarla (7.4) = 8
    * Artik dogru sonuca ulastik o halde formulumuz:
    *     sonuc = usteYuvarla(mesafe / 5.0)
    *     usteYuvarla ma fonksiyonu ceil() dir "math" kutuphanesi icerisinden gelmektedir.
    * Bitti diye dusunurken yaniliyor olabilirsiniz peki mesafe 80 gelseydi ? yanmasi gereken lamba sayisini 10 olarak elde ediyoruz!
    * Ama bizim 8 adet lambamiz var bu bize LED_DIZISI[] DIZISINDE sinir asma problemi verir,
    * Dizi 8 elemen barindiriyor 10 yazarsak hata aliriz o zaman bunu da bir if ile kontrol edelim ve 8 den buyuk gelirse sonuc hep 8 kalsin diyerek cozeriz
    *       if(sonuc > 8)
    *         sonuc = 8
  */      
