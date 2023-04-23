/*  HAFTA 3 - UYGULAMA 1.11
 *  KONU: RGB Led, RGB led uzerinde uc farkli renk bulunmaktadir. RedGreenBlue acilimindan ismi gelmektedir.
 *  Amac: RGB led icerisindeki rgb renkleri ile ara renkleri elde etme.
 */
#include <analogWrite.h>     //Ara renk elde etmek icin pinlere farkli gerilimlerde guc uygulanmasi gerektigi icin bu kutuphane sayesinde istedigimiz analog degeri verebiliriz.

int red_light_pin = D11;
int green_light_pin = D10;
int blue_light_pin = D9;

void setup() {
  pinMode(red_light_pin, OUTPUT);     //Led'e guc verilip isiginin yanmasi istendigi icin modu OUTPUT veirlmistir.
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  RGB_color(255,0,0);   //Kirmizi
  delay(1000);
  RGB_color(0,0,255);   //Mavi
  delay(1000);
  RGB_color(255,255,0); //Sari
  delay(1000);
  RGB_color(0,128,0);   //Yesil
  delay(1000);
  RGB_color(0,0,128);   //Lacivert
  delay(1000);
  RGB_color(80,0,80);   //Mor
  delay(1000);
  RGB_color(255,255,255);   //Beyaz
  delay(1000);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value){
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
