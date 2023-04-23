#include <WiFi.h>
#include "HTTPClient.h"
#include "DHTesp.h"
#include <ESP32Servo.h>  // #include <Deneyap_Servo.h>
#include "HCSR04.h"
#include "analogWrite.h"

Servo servo; // Servo motor nesnesi

DHTesp dht11; 

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7

#define trigPin D12
#define echoPin D13

int hiz = 150;
int uzaklik=0, sure=0;
int sagUzaklik=0, solUzaklik=0, ortaUzaklik=0;
float nem, sicaklik;

const char* server = "api.thingspeak.com";
const char* ssid = "baglanilacak_ag_ismi";
const char* password = "baglanilacak_ag_sifresi";
String apiKey = "thinq_speak_adresinden_gelen_api_key";

WiFiClient client;
const int httPort = 80;

void setup() {
  dht11.setup(D11, DHTesp::DHT11);
  Serial.begin(115200);
  Serial.print(ssid);
  Serial.print(" kablosuz agina baglaniliyor");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Kablosuz aga baglanildi!");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(motorR1,OUTPUT);
  pinMode(motorR2,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);

  servo.attach(D9); 
}

void loop() {
  uzaklik = uzaklikHesapla();
  Serial.print("Uzaklik: ");
  Serial.print(uzaklik);

  sicaklik = dht11.getTemperature();
  Serial.print("Sicaklik    : ");
  Serial.println(sicaklik);
  nem = dht11.getHumidity();
  Serial.print("Nem         : %");
  Serial.println(nem);

  client.connect(server, httPort);
  String data1 = "&field1=" + String(sicaklik);
  String data2 = "&field2=" + String(nem);
  updateValue(data1+data2);
  
  delay(1000);

  servo.write(90);
  delay(50);

  ortaUzaklik = uzaklik;

  if(ortaUzaklik<20){
    dur();
    delay(500);

    servo.write(5);
    delay(1000);
    sagUzaklik = uzaklik;
    delay(500);

    servo.write(180);
    delay(1000);
    solUzaklik = uzaklik;
    delay(500);

    servo.write(90);
    delay(1000);

    if(sagUzaklik>solUzaklik){
      sag();
      delay(500);
    }else if(sagUzaklik<solUzaklik){
      sol();
      delay(500);
    }else if((sagUzaklik<=20) || (solUzaklik>=20)){
      geri();
      delay(2000);
    }else{
      ileri();
    }
  }else{
    ileri();
  }

}



void ileri() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, hiz);
}

void geri() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  analogWrite(motorLE, hiz);
}

void sag() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLE, hiz);
}

void sol() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRE, hiz);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  analogWrite(motorLE, hiz);
}

void dur() {
  analogWrite(motorRE, LOW);
  analogWrite(motorLE, LOW);
}
