/*  HAFTA 3 - UYGULAMA 1.8
 *  KONU: RGB Led, RGB led uzerinde uc farkli renk bulunmaktadir. RedGreenBlue acilimindan ismi gelmektedir.
 *  Amac: RGB led iceirsindeki kirmizi+yesil ledi yakarak sadece sari isik elde ediniz.
 */
int red_light_pin = D11;
int green_light_pin = D10;
int blue_light_pin = D9;

void setup() {
  pinMode(red_light_pin, OUTPUT);    
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  digitalWrite(red_light_pin,1);   
  digitalWrite(green_light_pin,1); 
  digitalWrite(blue_light_pin,0);   
}
