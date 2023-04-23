#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h> 

#define trigPin D0
#define echoPin D1
#define buzzerPin D4

LiquidCrystal_I2C lcd(0x27,20,4);
Servo myservo;

int pos = 0;
int deger;

float sure = 0;
float mesafe = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  myservo.attach(D9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  deger = analogRead(A0);
  pos = map(deger, 0,4095,0,180);
  myservo.write(pos);
  MesafeHesaplama();

  if(mesafe < 5.00)
    digitalWrite(buzzerPin,HIGH);
  else
    digitalWrite(buzzerPin,LOW);

    lcd.home();
    lcd.print(mesafe);
    lcd.setCursor(10,0);
    lcd.println(".cm mesafede cisim vardir");
    delay(100);
}
void MesafeHesaplama(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    sure = pulseIn(echoPin, HIGH);
    mesafe = sure/58; //ya da (sure * 0,034 / 2) 
  Serial.print(mesafe);
  Serial.println(" .cm de cisim vardır.");
  delay(50);
}