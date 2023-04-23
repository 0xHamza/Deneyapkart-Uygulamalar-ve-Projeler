/*  HAFTA 5 - GOZLE UYGULAMA 1.11
    KONU: LCD Ekran Komutlar
    Amac: Ekranda metin gosterme
*/

#include <LiquidCrystal_I2C.h> //Mevcut kutuphane deneyap icerisinde zaten hazir gelmektedir.

LiquidCrystal_I2C lcd(0x27,20,4);  //lcd tanimlaniyor, 0x27 adresinde, 20 sutun 4 satirlik bir lcd oldugunu belirttik.

void setup()
{
  lcd.init();                   //lcd baslatildi
  lcd.backlight();              //lcd arka isigi yakildi
}

void loop()
{
  lcd.home(); //imleci yazilacak yazi baslangicini ekranin basina sol us koseye alir
  lcd.print("DENEYAP");
  lcd.setCursor(3,1); //imleci 3.sutun 1.satira tasir
  lcd.print("ATOLYELERI");
  lcd.setCursor(8,2); //imleci 3.sutun 1.satira tasir
  lcd.print("LISE");
  lcd.setCursor(9,3); //imleci 3.sutun 1.satira tasir
   lcd.print("EGITIMLERI");
   lcd.blink(); //yanip sonen imleci acar
   delay(5000);
}