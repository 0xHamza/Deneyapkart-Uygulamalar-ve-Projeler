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

  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();

    // Açı değerleri "," karakteri ile ayrılmıştır
    String angle1 = data.substring(0, data.indexOf(","));
    data = data.substring(data.indexOf(",") + 1);
    String angle2 = data.substring(0, data.indexOf(","));
    data = data.substring(data.indexOf(",") + 1);
    String angle3 = data.substring(0, data.indexOf(","));
    data = data.substring(data.indexOf(",") + 1);
    String angle4 = data;

    int angle1_int = angle1.toInt();
    int angle2_int = angle2.toInt();
    int angle3_int = angle3.toInt();
    int angle4_int = angle4.toInt();

    // Servo motorların açılarını ayarla
    servo1.write(angle1_int);
    servo2.write(angle2_int);
    servo3.write(angle3_int);
    servo4.write(angle4_int);
  }

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
