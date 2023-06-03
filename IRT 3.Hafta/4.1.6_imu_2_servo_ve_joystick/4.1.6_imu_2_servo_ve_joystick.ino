#include <Deneyap_Servo.h>
#include "lsm6dsm.h"
#define SERVOPIN1 D14
#define SERVOPIN2 D9
#define X_pin A0
#define Y_pin A1

int X_Val, Y_Val;
int dly = 5;
int stp = 1;
int X_jys = 0, Y_jys = 0;
int teta1min = 0;
int teta1max = 180;
int teta2min = 0;
int teta2max = 180;

float accAngleX = 0.;
float accAngleY = 0.;
LSM6DSM IMU;
Servo myservo1;
Servo myservo2;
int pos1 = 90;
int pos2 = 90;

void setup()
{
  IMU.begin();
  myservo1.attach(SERVOPIN1);
  myservo2.attach(SERVOPIN2, 1);
  pinMode(BUILTIN_KEY, INPUT);
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDR, LOW); //Kırmızı led aktif
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

void loop()
{
  X_Val = analogRead(X_pin);
  Y_Val = analogRead(Y_pin);
  uint8_t buttonState = digitalRead(BUILTIN_KEY); // Buton durumu
  
  if (buttonState == LOW) // Butona basılma durumu
  {
    if (dly == 5) {
      dly = 10;
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, LOW);
    }
    else {
      if (dly == 10) {
        dly = 20;
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDB, LOW); //Mavi led aktif
      }
      else if (dly == 20) {
        dly = 5;
        digitalWrite(LEDR, LOW); //Kırmızı led aktif
        digitalWrite(LEDB, HIGH);
      }
    }
    delay(300);
  }
  if (X_Val < 1000 && pos1 > teta1min) X_jys -= stp;
  if (X_Val > 3000 && pos1 < teta1max) X_jys += stp;
  if (Y_Val < 1000 && pos2 > teta2min) Y_jys -= stp;
  if (Y_Val > 3000 && pos2 < teta2max) Y_jys += stp;
  
  accAngleX = atan(IMU.readFloatAccelX() / sqrt(pow(IMU.readFloatAccelY(), 2) + pow(IMU.readFloatAccelZ(), 2) + 0.001)) * 180 / PI;
  accAngleY = atan(-1 * IMU.readFloatAccelY() / sqrt(pow(IMU.readFloatAccelX(), 2) + pow(IMU.readFloatAccelZ(), 2) + 0.001)) * 180 / PI;
  pos1 = 90 + int(accAngleX) + X_jys;
  pos2 = 90 + int(accAngleY) + Y_jys;
  myservo1.write(pos1);
  myservo2.write(pos2);
  delay(dly);
}
