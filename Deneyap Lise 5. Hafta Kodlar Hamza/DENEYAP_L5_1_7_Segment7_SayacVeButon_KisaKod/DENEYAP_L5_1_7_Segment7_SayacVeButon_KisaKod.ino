/*  HAFTA 5 - GOZLE UYGULAMA 1.7
    KONU: 7 Segment Display Sayac ve buton kisa kod
    Amac: 7 Segment Display 2 buton ile sayac yapip arttirma azaltma yapma.
*/

#define butonArti D12
#define butonEksi D13

int gosterge_ledler[] = {D0, D1, D4, D5, D6, D7, D9};

int sayac = 0;

byte dogruluk_tablosu[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, //0
  {0, 1, 1, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1}, //2
  {1, 1, 1, 1, 0, 0, 1}, //3
  {0, 1, 1, 0, 0, 1, 1}, //4
  {1, 0, 1, 1, 0, 1, 1}, //5
  {1, 0, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1}, //9
};

void setup()
{
  for (int i = 0; i < 7; i++)
  {
    pinMode(gosterge_ledler[i], OUTPUT);
  }

  pinMode(butonArti, INPUT);
  pinMode(butonEksi, INPUT);
}

void loop()
{
  if (digitalRead(butonArti) == 1)
  {
    sayac++;
  }

  if (digitalRead(butonEksi) == 1)
  {
    sayac--;
  }

  if (sayac > 9)
  {
    sayac = 0;
  }

  if (sayac < 0)
  {
    sayac = 9;
  }


  for (int j = 0; j < 7; j++)
  {
    digitalWrite(gosterge_ledler[j], dogruluk_tablosu[sayac][j]);
  }
  delay(250);
}
