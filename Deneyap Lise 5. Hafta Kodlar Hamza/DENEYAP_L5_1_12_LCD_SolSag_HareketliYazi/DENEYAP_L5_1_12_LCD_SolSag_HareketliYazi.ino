/*  HAFTA 5 - GOZLE UYGULAMA 1.12
    KONU: LCD Ekran Hareketli Yazi
    Amac: Ekranda hareketli metin gosterme
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
  lcd.clear(); //ekrani temizler
  lcd.setCursor(1,1); //imleci 3.sutun 1.satira tasir
  lcd.print("DENEYAP");
  lcd.setCursor(0,2); //imleci 1.sutun 1.satira tasir
  lcd.print("ATOLYELERI"); 

  for (int i = 1; i < 11; i++)
  {
    lcd.scrollDisplayRight();
    delay(250);
  }
  for (int j = 1; j < 11; j++)
  {
    lcd.scrollDisplayLeft();
    delay(250);
  }
}
