/* Bu kod, pin numaralarını isimlendirir ve değişkenleri tanımlar.
  - setup() fonksiyonu, buton pinlerini INPUT_PULLUP olarak ayarlar ve analog pinleri INPUT olarak ayarlar.
  - loop() fonksiyonu, analog ve buton pinlerinden okunan değerleri değişkenlere atar ve seri porta yazdırır. Ayrıca, simulasyonFormati() fonksiyonunu kullanarak okunan değerleri simulasyon formatına uygun şekilde seri porta yazdırır.
  - simulasyonFormati() fonksiyonu, okunan değerleri simulasyon formatına uygun şekilde seri porta yazdırır.
  - github.com/0xhamza
*/

// Pin numaralarını isimlendir
#define SW1_pin D0        //JOYSTICK 1 BUTON PINI 
#define SW2_pin D1        //JOYSTICK 2 BUTON PINI 
#define x1_pin A0         //JOYSTICK 1 X PINI
#define y1_pin A1         //JOYSTICK 1 Y PINI
#define x2_pin A4         //JOYSTICK 2 X PINI 
#define y2_pin A5         //JOYSTICK 2 Y PINI 
#define x3_pin A2         //TEST AMACLI EKRANDA GORMEK ICIN
#define y3_pin A3         //TEST AMACLI EKRANDA GORMEK ICIN

// Joystıickden okunacak degerlerin tutulmasi icin Değişkenleri tanımla
int x1_deger, y1_deger, x2_deger, y2_deger, x3_deger, y3_deger, b1_deger, b2_deger;

void setup() {
  // Seri haberleşme hızını 115200 baud olarak ayarla
  Serial.begin(115200);

  // Buton pinlerini INPUT_PULLUP olarak ayarla
  pinMode(SW1_pin, INPUT_PULLUP);
  pinMode(SW2_pin, INPUT_PULLUP);

  // Analog pinleri INPUT olarak ayarla
  pinMode(x1_pin, INPUT);
  pinMode(x2_pin, INPUT);
  pinMode(y1_pin, INPUT);
  pinMode(y2_pin, INPUT);

  // Analog pinleri okumadan önce tanımla
  pinMode(x3_pin, INPUT);
  pinMode(y3_pin, INPUT);
}

void loop() {
  // Analog pinlerden okunan değerleri değişkenlere ata
  x1_deger = analogRead(x1_pin);
  y1_deger = analogRead(y1_pin);
  x2_deger = analogRead(x2_pin);
  y2_deger = analogRead(y2_pin);
  x3_deger = analogRead(x3_pin);
  y3_deger = analogRead(y3_pin);

  // Buton pinlerinden okunan değerleri değişkenlere ata
  b1_deger = digitalRead(SW1_pin);
  b2_deger = digitalRead(SW2_pin);

  // Okunan değerleri seri porta yazdır
  Serial.print("X1: ");
  Serial.println(x1_deger);
  Serial.print("Y1: ");
  Serial.println(y1_deger);
  Serial.print("X2: ");
  Serial.println(x2_deger);
  Serial.print("Y2: ");
  Serial.println(y2_deger);
  Serial.print("X3: ");
  Serial.println(x3_deger);
  Serial.print("Y3: ");
  Serial.println(y3_deger);
  Serial.print("B1: ");
  Serial.println(b1_deger);
  Serial.print("B2: ");
  Serial.println(b2_deger);

  // Okunan değerleri simulasyonFormati() fonksiyonuna gönder
  simulasyonFormati(x1_deger, y1_deger, x2_deger, y2_deger, b1_deger, b2_deger);

  // 1 saniye bekle
  delay(1000);
}

// Simulasyon formatına uygun şekilde okunan değerleri seri porta yazdır
void simulasyonFormati(int x1_deger, int y1_deger, int x2_deger, int y2_deger, int b1_deger, int b2_deger) {
  Serial.print("[");
  Serial.print(x1_deger);
  Serial.print(",");
  Serial.print(y1_deger);
  Serial.print(",");
  Serial.print(x2_deger);
  Serial.print(",");
  Serial.print(y2_deger);
  Serial.print(",");
  Serial.print(x3_deger);
  Serial.print(",");
  Serial.print(y3_deger);
  Serial.print(",");
  Serial.print(b1_deger);
  Serial.print(",");
  Serial.print(b2_deger);
  Serial.println("]");
}
