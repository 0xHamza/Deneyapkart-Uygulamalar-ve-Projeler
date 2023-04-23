/*
 # DENEYAP 10. HAFTA DHT11 SENSORU NEM VE SICAKLIK OKUMA #

 # Programi DeneyapKart ile calistirabilmek icin asagida belirttigim kutuphaneyi ister kutuphane yoneticisinden isterse manuel github linkinden kurmaniz gerekli!
 -> Kutuphane Adi: " DHT sensor library for ESPx "
 -> Kutuphane Link: " https://github.com/beegee-tokyo/DHTesp "
  
  Copyright (C) 2023, Hamza CELIK
*/

#include <DHTesp.h>

DHTesp dht11;

float sicaklik, nem;

void setup() {
  Serial.begin(115200);
  dht11.setup(D0, DHTesp::DHT11);
}

void loop() {
  Serial.println("-------- OLCUMLER --------");
  sicaklik = dht11.getTemperature();
  nem = dht11.getHumidity();

  Serial.print("Sicaklik    : ");
  Serial.println(sicaklik);
  Serial.print("Nem         : %");
  Serial.print(nem);
  delay(1000);
}
