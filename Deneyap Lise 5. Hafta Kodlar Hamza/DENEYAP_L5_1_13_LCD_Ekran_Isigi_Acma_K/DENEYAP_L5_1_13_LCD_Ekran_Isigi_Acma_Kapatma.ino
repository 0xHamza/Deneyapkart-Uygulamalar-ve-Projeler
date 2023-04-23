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
  lcd.noBacklight();
  delay(2500);
  lcd.backlight();  
  lcd.display();
  lcd.home();
  lcd.clear(); //ekrani temizler
  delay(1000);
  lcd.print("Ekran aciliyor");
  delay(500);
  for (int i = 1; i < 4; i++)
  {
    lcd.print(".");
    delay(500);
  }
  lcd.blink();
  delay(2500);
  lcd.noBlink();
  lcd.clear();
  delay(1000);

  lcd.setCursor(7,1);
  lcd.print("DENEYAP");
  delay(2500);

  for (int j = 1; j < 6; j++)
  {
    lcd.noBacklight();
    delay(1000);
    lcd.backlight();
    delay(1000);
  }

  lcd.clear(); //ekrani temizler
  delay(1000);
  lcd.print("Ekran kapatiliyor");
  delay(1500);
  lcd.noDisplay();
  delay(1000);
  lcd.noBacklight();
  delay(2500);
}
