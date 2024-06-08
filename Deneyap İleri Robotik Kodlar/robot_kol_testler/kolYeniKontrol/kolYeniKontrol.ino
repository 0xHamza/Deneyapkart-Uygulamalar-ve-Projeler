#include <ESP32Servo.h>// Eğer bu kütüphane çalışmaz ise <ESP32Servo.h> kütüphanesi denenebilir.

#define b1_pin D0
#define b2_pin D1
#define x1_pin A0
#define y1_pin A1
#define x2_pin A4
#define Y2_pin A5

#define SERVOPIN1 D12
#define SERVOPIN2 D13
#define SERVOPIN3 D14
#define SERVOPIN4 D15

Servo servo1, servo2, servo3, servo4;

int adim = 10;

int y1_deger, x1_deger, x2_deger, y2_deger, b1_deger, b2_deger;

int derece_x1 = 90;
int derece_y1 = 90;
int derece_x2 = 90;
int derece_y2 = 90;

void setup() {
  servo1.attach(SERVOPIN1);
  servo2.attach(SERVOPIN2);
  servo3.attach(SERVOPIN3);
  servo4.attach(SERVOPIN4);

  pinMode(b1_pin, INPUT_PULLUP);
  pinMode(b2_pin, INPUT_PULLUP);

  Serial.begin(115200);
  Serial.println("Ready.");
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

    int derece_x1 = angle1.toInt();
    int derece_y1 = angle2.toInt();
    int derece_x2 = angle3.toInt();
    int derece_y2 = angle4.toInt();

    // Servo motorların açılarını ayarla
    servo1.write(degerSonKontrol(derece_x1));
    servo2.write(degerSonKontrol(derece_y1));
    servo3.write(degerSonKontrol(derece_x2));
    servo4.write(degerSonKontrol(derece_y2));

     
    Serial.print("X1:"); Serial.print(derece_x1);  Serial.print("° - "); Serial.println(x1_deger);
    Serial.print("Y1:"); Serial.print(derece_y1); Serial.print("° - "); Serial.println(y1_deger);
  
    Serial.print("X2:"); Serial.print(derece_x2);  Serial.print("° - "); Serial.println(x2_deger);
    Serial.print("Y2:"); Serial.print(derece_y2); Serial.print("° - "); Serial.println(y2_deger);
  
    Serial.println("");
  
    simulasyonFormati(x1_deger, y1_deger, x2_deger, y2_deger, b1_deger, b2_deger);

  }

  delay(500);
}

int degerSonKontrol(int deger){
  if(deger > 180)
    return 180;
  else if(deger < 0)
    return 0;
  else 
  return deger;
}

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
  Serial.print(b1_deger);
  Serial.print(",");
  Serial.print(b2_deger);
  Serial.println("]");
}
