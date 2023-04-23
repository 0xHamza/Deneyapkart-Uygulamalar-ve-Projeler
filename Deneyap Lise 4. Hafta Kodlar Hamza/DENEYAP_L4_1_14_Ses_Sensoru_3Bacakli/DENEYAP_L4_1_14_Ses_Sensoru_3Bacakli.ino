/*  HAFTA 4 - GOZLE UYGULAMA 1.14 Ses Sensoru
 *  KONU: KY038 Ses Sensoru.
 *  Amac: Ses sensoru ile gurultu algilama. Gurultu 85 den buyukse led yak, kucukse kapat.
 */

int analogPin = A0;
int LED = D1;

float analogSesDegeri;

void setup() {
  pinMode(analogPin, INPUT);    
  pinMode(LED, OUTPUT); 
  Serial.begin(115200);
}

void loop() {

  analogSesDegeri = analogRead(analogPin); //Gurultu duzeyini analog olarak okuyoruz. 

  Serial.print("Gurultu Duzeyi: ");
  Serial.println(analogSesDegeri, 2);      // '2' degeri yazdirilacak sayinin sifirdan sonra 2 basamaginin gosterilmesini saglar orn 3.14598 yerine 3.14 gozukecektir

  if(analogSesDegeri >= 85){
    Serial.println("Gurultu seviyesi AŞILDI, YUKSEK!");
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
  }else{
    Serial.println("Gurultu seviyesi AŞILMADI, DUSUK.");
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }
}
