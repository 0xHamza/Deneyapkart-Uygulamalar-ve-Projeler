//Joystick verileri servo dondurme
#include "deneyap.h"
#include "ESP32Servo.h"

#define SERVOPIN D9
#define X_pin A0
#define Y_pin A1

Servo myservo;

int X_Val, Y_Val;
int X_derece, Y_derece;

void setup() {
  Serial.begin(115200);
  myservo.attach(SERVOPIN);
}

void loop() {
  X_Val = analogRead(X_pin);
  Y_Val = analogRead(Y_pin);

  //JOYSTICK DEN GELEN 0-4095 ARASINDAKI DEGERIN SERVO ICIN 0-180 CEKILMESI
  X_derece = map(X_Val,0,4095,0,180);      //((optX / 4095.0) * (45+180))-45;
  Y_derece = ((Y_Val / 4095.0) * (180));
  
  myservo.write(X_derece);
  //myservo.write(Y_derece);
  
  Serial.print("Joystick: ");
  Serial.print(X_Val);
  Serial.print(", ");
  Serial.print(Y_Val);
  Serial.print(" => Servo Motor: ");
  Serial.print(X_derece);
  Serial.print("°, ");
  Serial.print(Y_derece);
  Serial.println("°");

  delay(100);  
}
