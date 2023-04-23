/*  HAFTA 3 - UYGULAMA 1.7
 *  KONU: Buzzer led ve-veya uygulamasi, amac ve kosullari iceren kod sagidadir.
 *  Amac: Devrede bulunan 2 adet buzzer ve button ile butonlarin basilma durumlarina gore 2 led yanacak veya sonecektir
 *  Kosullar: 1)Iki butona birden basilirsa her iki led yanacak,
 *            2)Butonlardan herhangi birine birine basilirsa sol led
 *            3)Butonlara basilmazsa ledler sonecektir.
 *  EK: Bu uygulama daha da nasil gelistirilebilinir? 
 *      -Sol buton basarsa sol led, sag buton basarsa sag led, basmazsa hicbiri, iki buton basarsa iki led yansin.
 */
const int BUTTON1 = D11;
const int BUTTON2 = D10;
const int LED1 = D1;
const int LED2 = D0;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;

void setup() {
  pinMode(BUTTON1, INPUT);      //Butonlardan veri okunacagi icin 'INPUT' giris olarak pin modu belirlenir
  pinMode(BUTTON2, INPUT);
  pinMode(LED1, OUTPUT);        //Led'e guc verilecegi icin 'OUTPUT' cikis olarak pin modu belirlenir 
  pinMode(LED2, OUTPUT);
}
void loop() {
  BUTTONstate1 = digitalRead(BUTTON1);  //Bu sayede butona basilip basilmadigini anlariz.
  //Bu komut pin den 0 ve 1 degerlerini okur, eger pine guc geliyorsa 1 pine gelen bir guc yok veya gnd bagliysa 0 okunur.                    
  BUTTONstate2 = digitalRead(BUTTON2);

  if (BUTTONstate1 == HIGH && BUTTONstate2 == HIGH) {     //Iki butona da basilimi?
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }
  if (BUTTONstate1 == HIGH || BUTTONstate2 == HIGH) {     //Button1 veya Button2'ye basilimi?
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
  else {                                                  //Her iki butona'da basili degilse.
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }
}
