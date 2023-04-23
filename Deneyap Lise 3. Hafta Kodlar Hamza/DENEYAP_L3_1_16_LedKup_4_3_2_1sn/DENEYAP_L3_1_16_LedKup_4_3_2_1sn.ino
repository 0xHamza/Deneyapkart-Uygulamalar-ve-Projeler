/*  HAFTA 3 - UYGULAMA 1.16
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
   * Buradaki for ile j=4 den baslayarak 0 a kadar(0 dahil degil) her dongu asamasinda j yi 1 azalitir.
   * Boylece delay(j*1000) sirayla 4*1000,3*1000,2*1000,1*1000 degerlerini almis olur.
   */
  for(int j=4;j>0;j--){
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
