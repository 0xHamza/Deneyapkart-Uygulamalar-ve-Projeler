/*  HAFTA 3 - UYGULAMA 1.8
 *  KONU: RGB Led, RGB led uzerinde uc farkli renk bulunmaktadir. RedGreenBlue acilimindan ismi gelmektedir.
 *  Amac: RGB led iceirsindeki mavi ledi yakarak sadece mavi isik elde ediniz.
 */
int red_light_pin = D11;
int green_light_pin = D10;
int blue_light_pin = D9;

void setup() {
  //Led'e guc verilip isiginin yanmasi istendigi icin modu OUTPUT verilmistir.
  pinMode(red_light_pin, OUTPUT);     
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  /* 0: LOW anlamina gelmektedir, mavi rengi elde etmek icin diger renklerin
   *    sonmesi gerektiginden red-green pin LOW yapilir.
   * 1: HIGH anlamina gelmektedir, mavi rengi 1 (HIGH) yaparsak mavi renge
   *    guc gidecegi icin mavi isik rgb uzerinde gorulecektir.
   */
  digitalWrite(red_light_pin,0);
  digitalWrite(green_light_pin,0); 
  digitalWrite(blue_light_pin,1);   
}
