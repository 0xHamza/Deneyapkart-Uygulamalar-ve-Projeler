//SERVOYU KULLANABILMEMIZI SAGLAYAN KUTUPHANE EKLENMELI
#include <ESP32Servo.h>
//#include <Deneyap_Servo.h> 

Servo myservo;
int pos = 0;

#define trigPin D0
#define echoPin D1

float sure = 0;
float mesafe = 0;

void setup() {
  myservo.attach(D9);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(115200);
}

void loop() {
  for(pos = 0; pos<=180; pos+=1)
  {
    myservo.write(pos);
    MesafeHesaplama();

    Serial.print(pos); 
    Serial.print(","); 
    Serial.print(mesafe);
    Serial.print(".");

    delay(15);
  }
    
  for(pos = 180; pos >= 0; pos-=1)
  {
    myservo.write(pos);
    MesafeHesaplama();

    Serial.print(pos); 
    Serial.print(","); 
    Serial.print(mesafe);
    Serial.print(".");
    
    delay(15);
  }
}

void MesafeHesaplama(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure/58; //ya da (sure * 0,034 / 2) 
  delay(50);
}

/*
* PROJEYI GORSELLESTIRMEK ISTERSENIZ ASAGIDAKI KAYNAGI INCELEYIN
* Servo ve HCSR04 ile Sonar Yapma: https://www.youtube.com/watch?v=VhZ6pyCCdYw
* İnecek program: https://processing.org/
* Kodlar: https://drive.google.com/file/d/1aFBkZ1yPv8twaTu4UYF8UhXsHoR7S93u/view     bu olmazsa     https://github.com/ahmadlogs/arduino-ide-examples/tree/main/arduino-radar/processing_radar_gui
*/
