/*  HAFTA 3 - UYGULAMA 1.17
    KONU: KUP LED
    Amac: 3X3' kup led katlari yakilir gorsel led solen yapilir.
*/
int SutunPin[9] = {D0, D1, D4, D5, D6, D7, D10, D11, D15};

void setup() {

  for (int i = 0; i < 9; i++) {
    pinMode(SutunPin[i], OUTPUT);
    digitalWrite(SutunPin[i], LOW );
  }

  pinMode(D12, OUTPUT); //Kat 1
  pinMode(D13, OUTPUT); //Kat 2
  pinMode(D14, OUTPUT); //Kat 3
}

void loop() {
  son();
  delay(1000);
  kat1();
  delay(1000);
  kat2();
  delay(1000);
  kat3();
  delay(1000);
  tum_katlar();
  delay(1000);
  son();
  delay(1000);
  sirali();
}

void son() {    //Bu metod butun lambalari kapatir.
  digitalWrite(D12, LOW );
  digitalWrite(D13, LOW );
  digitalWrite(D14, LOW );

  for (int l = 0; l < 9; l++) {
    digitalWrite(SutunPin[l], LOW );
  }
}

void kat1() {   //Bu metod sadece kat1'i acar
  digitalWrite(D12, HIGH );
  digitalWrite(D13, LOW );
  digitalWrite(D14, LOW );
}

void kat2() {   //Bu metod sadece kat2'i acar
  digitalWrite(D12, LOW );
  digitalWrite(D13, HIGH );
  digitalWrite(D14, LOW );
}

void kat3() {   //Bu metod sadece kat3'u acar
  digitalWrite(D12, LOW );
  digitalWrite(D13, LOW );
  digitalWrite(D14, HIGH );
}

void tum_katlar() {   //Bu metod butun katlari acar
  digitalWrite(D12, HIGH );
  digitalWrite(D13, HIGH );
  digitalWrite(D14, HIGH );
}

void sirali() {     //Bu metod sirayla katlardaki lambalari acar kapatir.
  digitalWrite(D12, HIGH );
  digitalWrite(D13, HIGH );
  digitalWrite(D14, HIGH );

  for (int j = 0; j < 9; j++) {
    digitalWrite(SutunPin[j], HIGH );
  }

  for (int k = 0; k < 9; k = k + 2) {
    digitalWrite(SutunPin[k], LOW );
    delay(1000);
    digitalWrite(SutunPin[k], HIGH );
  }
}
