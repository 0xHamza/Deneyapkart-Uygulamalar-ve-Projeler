//Bu kod mesafe olcup ekrana yazmaktadır,
//Sizler bu koda ek olarak bir buzzer ekleyin ve 10cm altında buzzer ötsün

#define trig_pin D0   //ultrasonik sensör trigger pin bağlantısı
#define echo_pin D1   //ultrasonik sensör echo pin bağlantısı

long sure;
long uzaklik;

void setup() {

  Serial.begin(115200);         //serial monitör üzerinde uzaklık değerini görmek için

  pinMode(trig_pin, OUTPUT);    //ultrasonik sensör trigger pinini çıkış olarak ayarlıyoruz
  pinMode(echo_pin, INPUT);     //ultrasonik sensör echo pinini giriş olarak ayarlıyoruz

}

void loop() {

  digitalWrite(trig_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  sure = pulseIn(echo_pin, HIGH);

  uzaklik = sure * 0.034 / 2;




  Serial.print("Sure: ");
  Serial.print(sure);
  Serial.println(" Ms");

  if (uzaklik < 400) {

    Serial.print("Uzaklık: ");            //uzaklık değeri serial monitör ekranına yazdırılıyor.
    Serial.print(uzaklik);
    Serial.println(" cm");
  } else {
    Serial.println("Mesafe ölçülemiyor!");
  }
  delay(1000);
}
