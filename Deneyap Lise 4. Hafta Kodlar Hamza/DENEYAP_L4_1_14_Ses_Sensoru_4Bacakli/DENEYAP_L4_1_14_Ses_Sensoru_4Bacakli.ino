/*  HAFTA 4 - GOZLE UYGULAMA 1.14 Ses Sensoru
 *  KONU: KY038 Ses Sensoru.
 *  Amac: Ses sensoru ile gurultu algilama. Gurultu 85 den buyukse led yak, kucukse kapat.
 */

int sesSensor = D0;
int analogPin = A0;
int LED = D1;

int sensorDurum;
float analogSensor;

void setup() {
  pinMode(sesSensor, INPUT);    
  pinMode(analogPin, INPUT);    
  pinMode(LED, OUTPUT); 
  Serial.begin(115200);
}

void loop() {

  sensorDurum = digitalRead(sesSensor); //Sensorun ses algilayip algilamaigi bilgisi 1-0 gelir
  analogSensor = analogRead(analogPin); //Gurultu duzeyini analog olarak okuyoruz. 

  Serial.print("Sensor durum: ");
  Serial.println(sensorDurum); 

  Serial.print("Gurultu Duzeyi: ");
  Serial.println(analogSensor, 2);      // '2' degeri yazdirilacak sayinin sifirdan sonra 2 basamaginin gosterilmesini saglar orn 3.14598 yerine 3.14 gozukecektir

  if(analogSensor >= 85){
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
