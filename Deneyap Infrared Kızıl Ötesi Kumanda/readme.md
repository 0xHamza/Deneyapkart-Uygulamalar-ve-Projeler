## Deneyapkart Infrared Kumanda Alıcı Uygulaması

Bu kod, Deneyapkart ile uyumlu çalışabilecek bir infrared kumanda alıcı uygulamasıdır.

### Gereklilikler

* **Kütüphane:** https://github.com/Arduino-IRremote/Arduino-IRremote/ kütüphanesini Arduino IDE'nizdeki "Libraries" bölümüne eklemeniz gerekiyor.
* **Infrared Sensör:** Deneyapkart'a bağlayacağınız bir infrared sensör.
* **Ana Kod:** [DENEYAP_Infrared_KizilOtesi.ino](DENEYAP_Infrared_KizilOtesi/DENEYAP_Infrared_KizilOtesi.ino)  Bu, infrared kumanda alıcı uygulamasının ana kod dosyasıdır. Infrared sinyalleri alır, işler ve buna göre eylemler gerçekleştirir.
* **Tus Tanımlamaları:** [tuslar.h](DENEYAP_Infrared_KizilOtesi/tuslar.h)Bu dosya, kızılötesi kumandadaki tuş adreslerini ve komut değerlerini tanımlar. Kullandığınız kumandanın tuş adreslerine göre bu dosya üzerinde düzenlemeler yapmanız gerekebilir.



### Kod Açıklaması

1. **Kütüphane Ekleme:**
   ```cpp
   #include <IRremote.h>
   #include "deneyap.h"
   #include "tuslar.h"
   ```
   * `IRremote.h`: Infrared sinyallerini almak ve göndermek için gerekli kütüphaneyi ekler.
   * `deneyap.h`: Deneyapkart ile ilgili tanımlamaları içeren dosyayı ekler.
   * `tuslar.h`: Kumanda tuşlarının adreslerini ve isimlerini içeren dosyayı ekler.

2. **Sensör Pinini Tanımlama:**
   ```cpp
   #define IR_RECEIVE_PIN D1
   ```
   * `IR_RECEIVE_PIN`: Infrared sensörün bağlı olduğu Deneyapkart pinini tanımlar.

3. **Kurulum (setup):**
   ```cpp
   void setup() {
     Serial.begin(115200);
     Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
     IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
   }
   ```
   * `Serial.begin(115200)`: Seri iletişimi başlatır (115200 baud hızında).
   * `Serial.println(...)`: Başlangıç mesajını ve kütüphane sürümünü seri porttan yazdırır.
   * `IrReceiver.begin(...)`: Infrared alıcıyı başlatır. `IR_RECEIVE_PIN` sensör pinini ve `ENABLE_LED_FEEDBACK` ise sensör aktif olduğunda LED'in yanmasını sağlar.

4. **Döngü (loop):**
   ```cpp
   void loop() {
     if (IrReceiver.decode()) {
       // Alınan verileri işleme
       // ...
       IrReceiver.resume();
     }
   }
   ```
   * `IrReceiver.decode()`: Infrared alıcıdan gelen verileri kontrol eder ve varsa çözmeye çalışır.
   * `IrReceiver.resume()`: Bir sonraki infrared sinyalini almak için alıcıyı hazırlar.

5. **Alınan Verileri İşleme:**
   ```cpp
   if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
     // Bilinmeyen protokol
   } else {
     // Alınan verileri yazdırma
     // ...
     // Alınan komuta göre eylemleri gerçekleştirme
     // ...
   }
   ```
   * `IrReceiver.decodedIRData.protocol`: Alınan infrared sinyalinin protokolünü belirtir.
   * `IrReceiver.decodedIRData.command`: Alınan komutun kodunu belirtir.
   * `IrReceiver.decodedIRData.address`: Alınan komutun adresini belirtir.
   * `IrReceiver.decodedIRData.decodedRawData`: Alınan komutun ham verisini belirtir.
   * `IrReceiver.printIRResultRawFormatted(...)`: Alınan verileri formatlanmış olarak seri porttan yazdırır.
   * `IrReceiver.resume()`: Bir sonraki infrared sinyalini almak için alıcıyı hazırlar.

6. **Eylemleri Gerçekleştirme:**
   ```cpp
   if (IrReceiver.decodedIRData.command == KUMANDA_TUS_ON_OFF) {
     // Açma/Kapama işlemi
   } else if (IrReceiver.decodedIRData.command == KUMANDA_TUS_SES_ARTTIR) {
     // Ses Artırma işlemi
   } // ... diğer komutlar için işlemler
   ```
   * `KUMANDA_TUS_ON_OFF`, `KUMANDA_TUS_SES_ARTTIR`, vb.: `tuslar.h` dosyasında tanımlanan kumanda tuşlarının adresleri.
   * Bu kısımda, her bir komut için yapılacak işlemler yazılır. Örneğin, "Açma/Kapama" tuşuna basıldığında bir LED'i açıp kapatmak gibi.

### `tuslar.h` Dosyası

* `tuslar.h` dosyasında, kumanda tuşlarının adresleri ve isimleri tanımlanır.
* Bu dosyayı kendi kumandanıza göre düzenlemeniz gerekir.
* Örneğin, "Açma/Kapama" tuşunun adresi `KUMANDA_TUS_ON_OFF` olarak tanımlanmıştır. Kendi kumandanızda bu tuşun adresi farklı olabilir.

### Önemli Notlar

* `IR_RECEIVE_PIN` tanımını, infrared sensörün bağlı olduğu Deneyapkart pinine göre değiştirmeniz gerekir.
* `tuslar.h` dosyasını kendi kumandanıza göre düzenlemeniz gerekir.
* Bu kod yalnızca infrared sinyallerini almayı ve işlemeyi sağlar. Ek işlemler (LED'i açmak, motoru çalıştırmak, vb.) sizin tarafınızdan eklenmelidir.

### Ek Bilgiler

* **Daha Fazla Bilgi:** Daha fazla bilgi için Github 0xhamza: https://github.com/0xHamza/Deneyapkart-Uygulamalar-ve-Projeler
* **Kütüphane Belgeleri:** https://github.com/Arduino-IRremote/Arduino-IRremote/ adresinden kütüphane belgelerine ulaşabilirsiniz.
* **Kütüphane Belgeleri:** https://github.com/Arduino-IRremote/Arduino-IRremote/ adresinden kütüphane belgelerine ulaşabilirsiniz.
