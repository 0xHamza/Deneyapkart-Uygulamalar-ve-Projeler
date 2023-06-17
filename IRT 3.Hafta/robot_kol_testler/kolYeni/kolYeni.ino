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

  y1_deger = analogRead(y1_pin);
  x1_deger = analogRead(x1_pin);
  x2_deger = analogRead(x2_pin);
  y2_deger = analogRead(Y2_pin);
    b1_deger = digitalRead(b1_pin);
  b2_deger = digitalRead(b2_pin);

  if (x1_deger < 1000 and derece_x1 >= 0) derece_x1 += adim;
  if (x1_deger > 3700 and derece_x1 <= 180) derece_x1 -= adim;

  if (y1_deger < 1000 and derece_y1 >= 0) derece_y1 -= adim;
  if (y1_deger > 3500 and derece_y1 <= 180) derece_y1 += adim;

  if (x2_deger < 1000 and derece_x2 >= 0) derece_x2 -= adim;
  if (x2_deger > 3500 and derece_x2 <= 180) derece_x2 += adim;

  if (y2_deger < 1000 and derece_y2 >= 0) derece_y2 -= adim;
  if (y2_deger > 3500 and derece_y2 <= 180) derece_y2 += adim;


  derece_x1 = degerSonKontrol(derece_x1);
  derece_x2 = degerSonKontrol(derece_x2);
   derece_y1 = degerSonKontrol(derece_y1);
   derece_y2 = degerSonKontrol(derece_y2);
 


  Serial.print("X2:"); Serial.print(derece_x2);  Serial.print("° - "); Serial.println(x2_deger);
  Serial.print("Y2:"); Serial.print(derece_y2); Serial.print("° - "); Serial.println(y2_deger);


  Serial.print("X1:"); Serial.print(derece_x1);  Serial.print("° - "); Serial.println(x1_deger);
  Serial.print("Y1:"); Serial.print(derece_y1); Serial.print("° - "); Serial.println(y1_deger);

  Serial.println("");

  simulasyonFormati(x1_deger, y1_deger, x2_deger, y2_deger, b1_deger, b2_deger);

  servo1.write(derece_x1);
  servo2.write(derece_x2);
  servo3.write(derece_y1);
  servo4.write(derece_y2);


  delay(50);
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
