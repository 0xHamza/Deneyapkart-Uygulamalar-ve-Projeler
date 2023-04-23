// Joystick'un X ve Y pinleri ve buton pini
const int xPin = A0;
const int yPin = A1;
const int buttonPin = 2;

// Buton durumu
bool buttonState = false;

void setup() {
  // Seri haberleşme hızını 9600 baud olarak ayarla
  Serial.begin(9600);

  // Buton pini giriş olarak ayarla
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // X ve Y pinlerinden okunan değerleri oku
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);

  // Buton durumunu oku
  buttonState = digitalRead(buttonPin);

  // Okunan değerleri ve buton durumunu seri ekrana yazdır
  Serial.print("X değeri: ");
  Serial.print(xValue);
  Serial.print(" | Y değeri: ");
  Serial.print(yValue);
  Serial.print(" | Buton durumu: ");
  Serial.println(buttonState);

  // 100ms bekle
  delay(100);
}
