/*  HAFTA 3 - UYGULAMA 1.8
 *  KONU: RGB Led, RGB led uzerinde uc farkli renk bulunmaktadir. RedGreenBlue acilimindan ismi gelmektedir.
 *  Amac: RGB led iceirsindeki kirmizi ledi yakarak sadece kirmizi isik elde ediniz.
 */
int red_light_pin = D11;
int green_light_pin = D10;
int blue_light_pin = D9;

void setup() {
  pinMode(red_light_pin, OUTPUT);     //Led'e guc verilip isiginin yanmasi istendigi icin modu OUTPUT veirlmistir.
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  digitalWrite(red_light_pin,1);    //1: HIGH anlamina gelmektedir, kirmizi rengi 1 (HIGH) yaparsak kirmizi renge guc gidecegi icin kirmizi isik rgb uzerinde gorulecektir.
  digitalWrite(green_light_pin,0);  //0: LOW anlamina gelmektedir, kirmizi rengi elde etmek icin diger renklerin sonmesi gereklidir. Bu yuzden green pin LOW yapilir.
  digitalWrite(blue_light_pin,0);   //0: LOW anlamina gelmektedir, kirmizi rengi elde etmek icin diger renklerin sonmesi gereklidir. Bu yuzden blue pin LOW yapilir.
}
