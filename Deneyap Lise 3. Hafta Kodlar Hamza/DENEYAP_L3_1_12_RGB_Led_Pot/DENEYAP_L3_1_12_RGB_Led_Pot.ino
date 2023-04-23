/*  HAFTA 3 - UYGULAMA 1.12
    KONU: RGB Led ve POT;
      RGB led, uzerinde uc farkli renk bulunmaktadir. RedGreenBlue acilimindan ismi gelmektedir.
      Pot, analog veri okumamizi saglayan cevirmeli bir moduldur.
    Amac: Pot ile okudugumuz degerler ile RGB led isiklandirilacaktir.
*/
#include <analogWrite.h>     //Ara renk elde etmek icin pinlere farkli gerilimlerde guc uygulanmasi gerektigi icin bu kutuphane sayesinde istedigimiz analog degeri verebiliriz.

#define kirmizi D11
#define yesil D10
#define mavi D9

#define pot_k A0
#define pot_y A1
#define pot_m A2

int kirmizi_deger;
int yesil_deger;
int mavi_deger;

void setup() {
  pinMode(kirmizi, OUTPUT);     //Led'e guc verilip isiginin yanmasi istendigi icin modu OUTPUT veirlmistir.
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
}

void loop() {
  deger_oku();
  deger_yaz();
}

void deger_oku() {
  kirmizi_deger = analogRead(pot_k); //Pot ile belirli araliklarda farkli degerler okunacagi icin analogRead kullanilir, digitalRead sadece 1 ve 0 okur
  yesil_deger = analogRead(pot_y);
  mavi_deger = analogRead(pot_m);

  /* 10K ohm'luk bir pot 0-1023 arasında analog veri okuyabilir, ancak analogWrite metodu 0-255 arasi calisir,
   * Yani okunan 1023 degeri 255 e, 0 degeri 0 a, ornegin yarisi 511 degeri -> 127 analog degerini denk gelmektedi bu hesabi da map fonksiyonu biizm saglamaktadir.
   */

  kirmizi_deger = map(kirmizi_deger, 0, 1023, 0, 255);
  yesil_deger = map(yesil_deger, 0, 1023, 0, 255);
  mavi_deger = map(mavi_deger, 0, 1023, 0, 255);
}

void deger_yaz() {
  analogWrite(kirmizi, kirmizi_deger);
  analogWrite(yesil, yesil_deger);
  analogWrite(mavi, mavi_deger);
}
