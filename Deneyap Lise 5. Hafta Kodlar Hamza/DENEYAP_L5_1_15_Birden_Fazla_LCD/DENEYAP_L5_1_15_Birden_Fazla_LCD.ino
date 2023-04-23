/*  HAFTA 5 - GOZLE UYGULAMA 1.12
    KONU: LCD Ekran Hareketli Yazi
    Amac: Ekranda hareketli metin gosterme
*/

#include <LiquidCrystal_I2C.h> //Mevcut kutuphane deneyap icerisinde zaten hazir gelmektedir.

LiquidCrystal_I2C lcd1(0x27,20,4);  //lcd tanimlaniyor, 0x27 adresinde, 20 sutun 4 satirlik bir lcd oldugunu belirttik.
LiquidCrystal_I2C lcd2(0x21,16,2);  //lcd tanimlaniyor, 0x21 adresinde, 16 sutun 2 satirlik bir lcd oldugunu belirttik.

void setup()
{
  lcd1.init();                   //lcd1 baslatildi
  lcd2.init();                   //lcd1 baslatildi
  
  lcd1.backlight();              //lcd1 arka isigi yakildi
  lcd2.backlight();              //lcd2 arka isigi yakildi

  lcd1.clear(); //lcd 1 ekrani temizler
  lcd2.clear(); //lcd 2 ekrani temizler

  lcd1.home(); 
  lcd2.home(); 

  lcd1.print("MERHABA DUNYA"); //lCD1 e yazi yazma
  lcd2.print("HELLO WORLD"); //lCD2 ye yazi yazma
}

void loop()
{

}