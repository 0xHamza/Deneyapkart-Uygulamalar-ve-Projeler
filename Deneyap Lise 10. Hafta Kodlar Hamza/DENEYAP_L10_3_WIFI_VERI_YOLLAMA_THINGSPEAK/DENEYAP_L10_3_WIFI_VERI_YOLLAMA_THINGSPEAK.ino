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

  String data_to_send = apiKey;
  data_to_send += "&field1=";
  data_to_send += String(sicaklik);
  data_to_send += "&field2=";
  data_to_send += String(nem);
  data_to_send += "\r\n\r\n";

  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(data_to_send.length());
  client.print("\n\n");
  client.print(data_to_send);

  delay(1000);
}
