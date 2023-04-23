#include "BluetoothSerial.h"

BluetoothSerial SerialBT;   
char veri;
int led = D12;
void setup() {
  
  Serial.begin(115200);

  SerialBT.begin("TOGG");
  Serial.println("\nDeneyapKart'a Bağlanıldı") ;
  pinMode(led,OUTPUT);
}

void loop() {
  
  if(SerialBT.available())
  {
    veri = SerialBT.read();
    if(veri == '1'){
      digitalWrite(led,HIGH);
      SerialBT.println("IRONMAN! YANDI");
    }
    if(veri == '0'){
      digitalWrite(led,LOW);
      SerialBT.println("IRONMAN! SONDU");
    }
    delay(500);
  }

}
