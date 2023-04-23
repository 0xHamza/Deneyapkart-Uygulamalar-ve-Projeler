/*  HAFTA 3 - UYGULAMA 1.14
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

  /*
   * For dongusu sirali islemleri sayi arttirimlari gibi dongu islemleri yapar.
   * Buradaki for ile j=1 den baslayarak 5 e kadar(5 dahil degil) her dongu asamasinda j yi 1 arttirir.
   * Boylece delay(j*1000) sirayla 1*1000,2*1000,3*1000,4*1000 degerlerini almis olur.
   */
  for(int j=1;j<5;j++){
    digitalWrite(D12, HIGH );
    digitalWrite(D13, HIGH );
    digitalWrite(D14, HIGH );
    delay(j*1000);
  
    digitalWrite(D12, LOW );
    digitalWrite(D13, LOW );
    digitalWrite(D14, LOW );
    delay(j*1000);
  }
}
