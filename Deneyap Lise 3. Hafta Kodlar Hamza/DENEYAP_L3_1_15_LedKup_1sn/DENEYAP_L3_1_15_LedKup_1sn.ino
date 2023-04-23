/*  HAFTA 3 - UYGULAMA 1.15
    KONU: KUP LED
    Amac: 3X3' kup led katlari yakilir gorsel led solen yapilir.
*/
int SutunPin[9] = {D0,D1,D4,D5,D6,D7,D10,D11,D15};

void setup() {

  for(int i=0;i<9;i++){
    pinMode(SutunPin[i], OUTPUT);
    digitalWrite(SutunPin[i], LOW );
  }

  pinMode(D12, OUTPUT); //Kat 1
  pinMode(D13, OUTPUT); //Kat 2
  pinMode(D14, OUTPUT); //Kat 3
}

void loop() {
  digitalWrite(D12, HIGH );
  digitalWrite(D13, HIGH );
  digitalWrite(D14, HIGH );
  delay(1000);

  digitalWrite(D12, LOW );
  digitalWrite(D13, LOW );
  digitalWrite(D14, LOW );
  delay(1000);
}
