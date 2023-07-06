
void test(Servo& ser) {
  Serial.print("Derece 0->180: ");
  for (int i = 0; i < 180; i++) {
    Serial.print(i);
    yaz(ser, i);
    Serial.print(",");

    if (i == 90)
      delay(1500);
  }
  Serial.print("\nDerece 180->0: ");
  for (int i = 180; i > 0; i--) {
    Serial.print(i);
    yaz(ser, i);
    Serial.print(",");

    if (i == 90)
      delay(1500);
  }
  Serial.println("\nTest Bitti Servo 90");
  yaz(ser, 90);
  delay(1000);
}

void yaz(Servo& ser, int aci) {
  int res = ser.read();
  Serial.print("\nMevcut: ");
  Serial.print(res);
  Serial.print(" Hedef: ");
  Serial.println(aci);

  if (res <= 180 && res >= 0) {
    Serial.println(" YAVAS GIDIS");
    if (res < aci) {
      for (int i = res; res <= aci; res++) {
        ser.write(res);
        delay(5);
      }
    } else {
      for (int i = res; res >= aci; res--) {
        ser.write(res);
        delay(5);
      }
    }
  } else {
    Serial.println(" HIZLI GIDIS");
    ser.write(aci);
  }
}


void testAll(void (*fonksiyon)(int)) {
  Serial.print("Derece 0->180: ");
  for (int i = 0; i < 180; i++) {
    Serial.print(i);
    fonksiyon(i);
    Serial.print(",");

    if (i == 90)
      delay(1500);
    else
      delay(15);
  }
  Serial.print("\nDerece 180->0: ");
  for (int i = 180; i > 0; i--) {
    Serial.print(i);
    fonksiyon(i);
    Serial.print(",");

    if (i == 90)
      delay(1500);
    else
      delay(15);
  }
  Serial.println("\nTest Bitti Servo 90");
  fonksiyon(90);
  delay(1000);
}

void ileri() {
  Serial.println("ILERI Sag");
  saayak.write(90);
  sabacak.write(120);
  sadiz.write(60);
  delay(500);

  Serial.println("ILERI Sol");
  soayak.write(90);
  sobacak.write(120);
  sodiz.write(60);
  delay(500);
}

void geri() {
  Serial.println("GERI Sag");
  saayak.write(90);
  sabacak.write(60);
  sadiz.write(120);
  delay(500);

  Serial.println("GERI Sol");
  soayak.write(90);
  sobacak.write(60);
  sodiz.write(120);
  delay(500);
}

void hepsi(int aci) {
  sag(aci);
  sol(aci);
}

void hepsiEs(int aci) {
  sag(aci);
  sol(180 - aci);
}

void sag(int aci) {
  saayak.write(aci);
  sabacak.write(aci);
  sadiz.write(aci);
}

void sol(int aci) {
  soayak.write(aci);
  sobacak.write(aci);
  sodiz.write(aci);
}

void allTest() {
  Serial.println("Test: soayak");
  test(soayak);

  Serial.println("Test: saayak");
  test(saayak);

  Serial.println("Test: sadiz");
  test(sadiz);

  Serial.println("Test: sodiz");
  test(sodiz);

  Serial.println("Test: sabacak");
  test(sabacak);

  Serial.println("Test: sobacak");
  test(sobacak);
}