//1.4. Uygula: İki Motorlu Bir Sistemin Joystick ile Kontrolü

#include <Deneyap_Servo.h>

#define SERVOPIN1 D14
#define SERVOPIN2 D9
#define SW_pin D0
#define X_pin A0
#define Y_pin A1

Servo myservo1, myservo2;

int X_Val, Y_Val;
int pos1 = 0, pos2 = 0;
int dly = 10;
int stp = 1;
int Dig_Val = 0;
int teta1min = 0;
int teta1max = 180;
int teta2min = 0;
int teta2max = 180;

void setup() {
  Serial.begin(115200);
  myservo1.attach(SERVOPIN1);
  myservo2.attach(SERVOPIN2, 1);
  pinMode(SW_pin, INPUT_PULLUP);
  digitalWrite(SW_pin, HIGH);
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);
}

void loop() {
  X_Val = analogRead(X_pin);
  Y_Val = analogRead(Y_pin);
  Dig_Val = digitalRead(SW_pin);

  Serial.print("X val: "); Serial.println(X_Val);
  Serial.print("Y val: "); Serial.println(Y_Val);
  Serial.print("Buton: "); Serial.println(Dig_Val);
  
  if (Dig_Val < 1) {
    if (dly == 5) dly = 10;
    else {
      if (dly == 10) dly = 20;
      else if (dly == 20) dly = 5;
    }
    delay (500);
  }
  if (X_Val < 1000 && pos1 > teta1min) pos1 -= stp;
  if (X_Val > 3000 && pos1 < teta1max) pos1 += stp;
  if (Y_Val < 1000 && pos2 > teta2min) pos2 -= stp;
  if (Y_Val > 3000 && pos2 < teta2max) pos2 += stp;
  
  myservo1.write(pos1);
  myservo2.write(pos2);
  delay (dly);
}
