/*  HAFTA 4 - GOZLE UYGULAMA 1.2
 *  KONU: LDR(Light Dependent Resistor, Isiga Bagimli Direnc) ile ortam isigini okuma.
 *  Amac: LDR ile okunan degerle LED yakma.
 */
#include <analogWrite.h>  //LDR sensorunden gelecek analog degerleri okuyabilmek icin bu kutuphane eklenmelidir! (Eger bu kutuphane yok vb bir hata alirsaniz: Arduino Menu > Araclar > Kutuphaneleri Yonet > "Arama kismina kutuphane adini yazarak ekleyin")

int led = D0;             //LED, digital 0 pinine bagli.
int ldr = A0;             //LDR, analog 0 pinine bagli.
int ldrdeger;             //LDRDEGER, ldr den okunan degerin tutulacagi degisken.

void setup() {
  pinMode(led,OUTPUT);    
  pinMode(ldr,INPUT);    

  Serial.begin(115200);
}

void loop() {
  ldrdeger = analogRead(ldr);                       //LDR, degeri okunur. Deger 0 ile 4095 arasinda analog veri okuyacaktir.
  ldrdeger = map(ldrdeger, 0, 4095, 0, 255);        //Okunan degerin 0-255 arasinda kaca denk geldigini buluyoruz.
  Serial.println(ldrdeger); 
  analogWrite(led,ldrdeger);                        //Okunup 0-255 arasina donusturulen analog deger ile led yakilir.
  delay(250);
}
