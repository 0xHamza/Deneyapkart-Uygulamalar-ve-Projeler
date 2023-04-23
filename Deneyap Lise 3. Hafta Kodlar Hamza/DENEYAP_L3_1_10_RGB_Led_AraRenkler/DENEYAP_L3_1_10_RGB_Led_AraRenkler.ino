/*  HAFTA 3 - UYGULAMA 1.10
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
  purple();
  delay(1000);
  turqois();
  delay(1000);
  white();
  delay(1000);
}

void purple(){
  analogWrite(red_light_pin,128);
  analogWrite(green_light_pin,0);
  analogWrite(blue_light_pin,128);
}

void turqois(){
  analogWrite(red_light_pin,64);
  analogWrite(green_light_pin,224);
  analogWrite(blue_light_pin,208);
}

void white(){                  //Beyaz, kirmizi-yesil-mavi rengin birlesimiyle olustugundan hepsini yakarsak birlesimi beyaz ortaya cikacaktir.
  digitalWrite(red_light_pin,1);    
  digitalWrite(green_light_pin,1);  
  digitalWrite(blue_light_pin,1);
}
