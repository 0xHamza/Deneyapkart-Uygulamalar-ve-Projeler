/*  HAFTA 5 - GOZLE UYGULAMA 1.6
 *  KONU: 7 Segment Display Geri Sayim
 *  Amac: 7 Segment Display ile rakamları gosterme.
 */

#define buzzer_pin D11

#define a D0
#define b D1
#define c D4
#define d D5
#define e D6
#define f D7
#define g D9
#define dp D10

void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
  dokuz();
  off();
  delay(250);

  sekiz();
  off();
  delay(250);

  yedi();
  off();
  delay(250);
  
  alti();
  off();
  delay(250);

  bes();
  off();
  delay(250);
  
  dort();
  off();
  delay(250);
  
  uc();
  off();
  delay(250);
  
  iki();
  off();
  delay(250);
  
  bir();
  off();
  delay(250);
  
  sifir();
  off();
  delay(250);

  nokta();
  digitalWrite(buzzer_pin, HIGH);
  delay(1000);
  off();
  digitalWrite(buzzer_pin, LOW);
  delay(500);

  nokta();
  digitalWrite(buzzer_pin, HIGH);
  delay(500);
  off();
  digitalWrite(buzzer_pin, LOW);
  delay(250);

  nokta();
  digitalWrite(buzzer_pin, HIGH);
  delay(250);
  off();
  digitalWrite(buzzer_pin, LOW);
  delay(125);

  nokta();
  digitalWrite(buzzer_pin, HIGH);
  delay(125);
  digitalWrite(buzzer_pin, LOW);
  delay(75);
  off();

  nokta();
  digitalWrite(buzzer_pin, HIGH);
  delay(75);
  off();
  digitalWrite(buzzer_pin, LOW);
  delay(250);
}

void sifir(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    delay(1000);
}

void bir(){
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    delay(1000);
}

void iki(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void uc(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void dort(){
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void bes(){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void alti(){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void yedi(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    delay(1000);
}

void sekiz(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void dokuz(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    delay(1000);
}

void nokta(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, HIGH);
    delay(1000);
}

void off(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    delay(1000);
}