#include <IRremote.h>
#include "deneyap.h"
#include "tuslar.h"

#define IR_RECEIVE_PIN D1

void setup() {
  Serial.begin(115200);

  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  /*
     Alınan verinin mevcut olup olmadığını kontrol edin ve mevcutsa kodunu çözmeye çalışın.
     Çözülen sonuç IrReceiver.decodedIRData yapısındadır.

     "komutun kodu"              : IrReceiver.decodedIRData.command içinde,
     "komutun adresi"            : IrReceiver.decodedIRData.address içinde,
     "komutun protokolu"            : IrReceiver.decodedIRData.protocol içinde,
     "komutun 32 bit raw datası" : IrReceiver.decodedIRData.decodedRawData içindedir
  */
  if (IrReceiver.decode()) {

    // Alınan verilerin bir özetini yazdırma, Ornegin hangi tus hangi komut,adres ...

    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println("Gürültü veya bilinmeyen (veya henüz etkinleştirilmemiş) bir protokol alındı");
      IrReceiver.printIRResultRawFormatted(&Serial, true);
      IrReceiver.resume();
    } else {
      IrReceiver.resume();                                    // Alınan verinin bir özetini yazdır
      Serial.print("Alınan Komut: ");
      Serial.print(IrReceiver.decodedIRData.command, HEX);
      Serial.print(" | Adres: ");
      Serial.print(IrReceiver.decodedIRData.address, HEX);
      Serial.print(" | Protokol: ");
      Serial.print(IrReceiver.decodedIRData.protocol);
      Serial.print(" | Raw Data: ");
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
    }
    Serial.println();




    // Alınan komuta göre eylemleri gerçekleştir
    if (IrReceiver.decodedIRData.command == KUMANDA_TUS_ON_OFF) {
      Serial.println("KUMANDA_TUS_ON_OFF (Açma/Kapama) basıldı!");
      // Açma/Kapama işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_SES_ARTTIR) {
      Serial.println("KUMANDA_TUS_SES_ARTTIR (Ses Artırma) basıldı!");
      // Ses Artırma işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_SES_AZALT) {
      Serial.println("KUMANDA_TUS_SES_AZALT (Ses Azaltma) basıldı!");
      // Ses Azaltma işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_KANAL_DEGIS) {
      Serial.println("KUMANDA_TUS_KANAL_DEGIS (Kanal Değiştirme) basıldı!");
      // Kanal Değiştirme işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_MENU) {
      Serial.println("KUMANDA_TUS_MENU (Menü) basıldı!");
      // Menü işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_SESSIZ) {
      Serial.println("KUMANDA_TUS_SESSIZ (Sessiz) basıldı!");
      // Sessiz işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_PROGRAM_REHBERI) {
      Serial.println("KUMANDA_TUS_PROGRAM_REHBERI (Program Rehberi) basıldı!");
      // Program Rehberi işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_GERI) {
      Serial.println("KUMANDA_TUS_GERI (Geri) basıldı!");
      // Geri işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_0) {
      Serial.println("KUMANDA_TUS_0 (0) basıldı!");
      // 0 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_1) {
      Serial.println("KUMANDA_TUS_1 (1) basıldı!");
      // 1 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_2) {
      Serial.println("KUMANDA_TUS_2 (2) basıldı!");
      // 2 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_3) {
      Serial.println("KUMANDA_TUS_3 (3) basıldı!");
      // 3 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_4) {
      Serial.println("KUMANDA_TUS_4 (4) basıldı!");
      // 4 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_5) {
      Serial.println("KUMANDA_TUS_5 (5) basıldı!");
      // 5 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_6) {
      Serial.println("KUMANDA_TUS_6 (6) basıldı!");
      // 6 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_7) {
      Serial.println("KUMANDA_TUS_7 (7) basıldı!");
      // 7 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_8) {
      Serial.println("KUMANDA_TUS_8 (8) basıldı!");
      // 8 tuşu işlemi
    } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_9) {
      Serial.println("KUMANDA_TUS_9 (9) basıldı!");
      // 9 tuşu işlemi
    } else {
      Serial.println("Bilinmeyen komut alındı!");
    }

    // Bir sonraki IR sinyali için alıcıyı hazırla
    IrReceiver.resume();
  }
}
