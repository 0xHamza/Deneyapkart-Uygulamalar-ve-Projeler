/*  HAFTA 5 - GOZLE UYGULAMA 1.10
    KONU: LCD Ekran
    Amac: Ekranda metin gosterme
*/

#include <LiquidCrystal_I2C.h> //Mevcut kutuphane deneyap icerisinde zaten hazir gelmektedir.

LiquidCrystal_I2C lcd(0x27,20,4);  //lcd tanimlaniyor, 0x27 adresinde, 20 sutun 4 satirlik bir lcd oldugunu belirttik.

void setup()
{
  lcd.init();                   //lcd baslatildi
  lcd.backlight();              //lcd arka isigi yakildi
  lcd.print("MERHABA DUNYA");   //ekrana 'merhaba dunya' yazildi
}

void loop()
{

}