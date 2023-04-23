/*
 KURULACAK KUTUPHANE  "ThingSpeak.h"

*/


#include <WiFi.h>
#include "HTTPClient.h"
#include "DHTesp.h"
#include "ThingSpeak.h"

DHTesp dht11;
float nem, sicaklik;

int statusCode = 0;
unsigned long counterChannelNumber = 1607122;
const char * myCounterReadAPIKey = "FRTSZPPLN9M5LGLZ";

const char* server = "api.thingspeak.com";
const char* ssid = "Wokwi-GUEST";
const char* password = "";

WiFiClient client;

const int httPort = 80;

void setup() {
  Serial.begin(115200);
  dht11.setup(15, DHTesp::DHT22);
  ThingSpeak.begin(client);

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
}

void loop() {

  long temp = ThingSpeak.readLongField(counterChannelNumber, 1, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("Temperature: ");
    Serial.println(temp);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(100);

  long nem = ThingSpeak.readLongField(counterChannelNumber, 2, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("Nem: ");
    Serial.println(nem);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }

  delay(1000);
}
