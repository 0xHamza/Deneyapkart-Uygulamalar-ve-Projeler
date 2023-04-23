/*  HAFTA 5 - GOZLE UYGULAMA 1.12
    KONU: LCD Ekran Hareketli Yazi
    Amac: Ekranda hareketli metin gosterme
*/

#include <LiquidCrystal_I2C.h> //Mevcut kutuphane deneyap icerisinde zaten hazir gelmektedir.

LiquidCrystal_I2C lcd(0x27,20,4);  //lcd tanimlaniyor, 0x27 adresinde, 20 sutun 4 satirlik bir lcd oldugunu belirttik.

byte surat[8] = {
                B00000,
                B01010,
                B00100,
                B01010,
                B00000,
                B10001,
                B01110,
                B00000,
                };

byte ok[8] = {
                B00000,
                B00100,
                B00010,
                B11111,
                B00010,
                B00100,
                B00000,
                B00000,
                };

byte kalp[8] = {
                B00000,
                B01010,
                B11111,
                B11111,
                B11111,
                B01110,
                B00100,
                B00000,
                };


void setup()
{
  lcd.init();                   //lcd baslatildi
  lcd.backlight();              //lcd arka isigi yakildi
  lcd.createChar(1,surat);
  lcd.createChar(2,ok);
  lcd.createChar(3,kalp);
}

void loop()
{
  lcd.clear(); //ekrani temizler
  delay(1000);

  lcd.setCursor(4,1);
  lcd.write(byte(1));
  delay(1000);

  lcd.setCursor(7,1);
  lcd.print("DENEYAP");
  delay(1000);

  lcd.setCursor(16,1);
  lcd.write(byte(1));
  delay(2500);

  lcd.setCursor(0,2);
  for (int i = 1; i < 4; i++)
  {
    lcd.write(byte(2));
    delay(500);
  }

  lcd.setCursor(6,2);
  lcd.print("ATOLYELERI");
  delay(2500);

  lcd.setCursor(10,3);
  lcd.write(byte(3));
  delay(5000);
}
