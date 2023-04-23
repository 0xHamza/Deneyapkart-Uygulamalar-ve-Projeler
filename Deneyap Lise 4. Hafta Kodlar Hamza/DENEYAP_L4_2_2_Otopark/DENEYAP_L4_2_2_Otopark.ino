/*  HAFTA 4 - GOZLE UYGULAMA 2.2 Otopark Sensoru Sistemi
 *  KONU: Mesafe sensoru buzzer ile arac park ederken cikan sistem.
 *  Amac: Mesafeye bagli arabalardaki gibi oten buzzer ve yanan led kodu.
 */
const int trigPin = D6;
const int echoPin = D7;
const int buzzerPin = D5;
const int kLED = D0;
const int sLED = D1;
const int yLED = D4;

long sure ;
long zaman ;
float mesafe ;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(kLED, OUTPUT);
  pinMode(sLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  Serial.begin(115200);
}

void loop(){
    // HCSR04 mesafe sensörü için tetik pinini hazırla ve mesafeyi hesapla:
    digitalWrite(trigPin, LOW);     // Tetik pinini düşük seviyede ayarla, bu sensörün çalışması için gerekli
    delayMicroseconds(2);           // 2 mikrosaniyelik bir bekleme yap (tetikleme düzgün çalışması için)
    digitalWrite(trigPin, HIGH);    // Tetik pinini yüksek seviyede ayarla, bu sensörün ölçüm yapmasını başlatır
    delayMicroseconds(10);          // 10 mikrosaniyelik bir bekleme yap (ölçüm tamamlanması için)
    digitalWrite(trigPin, LOW);     // Tetik pinini tekrar düşük seviyede ayarla, ölçüm tamamlandıktan sonra sensörü devre dışı bırakır
    sure = pulseIn(echoPin, HIGH);  // Eko sinyalinin gelme süresini ölç, bu değer mesafeyi hesaplamak için kullanılacak
    mesafe = sure/58;               // Eko sinyal süresini kullanarak mesafeyi hesapla (mesafe = süre / hız = süre / 58)

    if(mesafe <= 10){
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(kLED, HIGH);
    }else if(mesafe <= 25 && mesafe > 10){
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(kLED, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(kLED, LOW);
      zaman = mesafe * 10;
      delay(zaman);
    }else if(mesafe <= 45 && mesafe > 25){
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(sLED, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(sLED, LOW);
      zaman = mesafe * 10;
      delay(zaman);
    }else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(yLED, HIGH);
      delay(50);
      digitalWrite(yLED, LOW);
    }
}
