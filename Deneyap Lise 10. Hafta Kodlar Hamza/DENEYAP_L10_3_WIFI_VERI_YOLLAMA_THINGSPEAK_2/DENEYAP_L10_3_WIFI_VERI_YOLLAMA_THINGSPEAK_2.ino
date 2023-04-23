#include <WiFi.h>
#include "HTTPClient.h"
#include "DHTesp.h"

DHTesp dht11;
float nem, sicaklik;

const char* server = "api.thingspeak.com";
const char* ssid = "baglanilacak_ag_ismi";
const char* password = "baglanilacak_ag_sifresi";
String apiKey = "thinq_speak_adresinden_gelen_api_key";

WiFiClient client;

const int httPort = 80;

void setup() {
  Serial.begin(115200);
  dht11.setup(D0, DHTesp::DHT11);

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

  // Sicaklik degerleri olculuyor
  sicaklik = dht11.getTemperature();
  Serial.print("Sicaklik    : ");
  Serial.println(sicaklik);
  nem = dht11.getHumidity();
  Serial.print("Nem         : %");
  Serial.println(nem);

  // Sicaklik degerleri web adresine gonderiliyor
  client.connect(server, httPort);

  
  String data1 = "&field1=" + String(sicaklik);
  String data2 = "&field2=" + String(nem);
  
  updateValue(data1+data2);

  delay(1000);
}

void updateValue(String data)
{
  data += "\r\n\r\n";
  String newData = apiKey + data;
  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(newData.length());
  client.print("\n\n");
  client.print(newData);

  if (client.connected()) {
    Serial.println("Connecting to ThingSpeak...");
    Serial.println();
  }else{
    Serial.println("Connecting to ThingSpeak ERROR!");
    Serial.println();
  }
}

