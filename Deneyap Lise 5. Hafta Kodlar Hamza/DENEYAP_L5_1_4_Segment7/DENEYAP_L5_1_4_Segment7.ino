/*  HAFTA 5 - GOZLE UYGULAMA 1.4
 *  KONU: 7 Segment Display
 *  Amac: 7 Segment Display ile rakamları gosterme.
 */

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
}

void loop()
{
  digitalWrite(a, HIGH);
  delay(1000);
  digitalWrite(a, LOW);
  delay(1000);
  digitalWrite(b, HIGH);
  delay(1000);
  digitalWrite(b, LOW);
  delay(1000);
  digitalWrite(c, HIGH);
  delay(1000);
  digitalWrite(c, LOW);
  delay(1000);
  digitalWrite(d, HIGH);
  delay(1000);
  digitalWrite(d, LOW);
  delay(1000);
  digitalWrite(e, HIGH);
  delay(1000);
  digitalWrite(e, LOW);
  delay(1000);
  digitalWrite(f, HIGH);
  delay(1000);
  digitalWrite(f, LOW);
  delay(1000);
  digitalWrite(g, HIGH);
  delay(1000);
  digitalWrite(g, LOW);
  delay(1000);
  digitalWrite(dp, HIGH);
  delay(1000);
  digitalWrite(dp, LOW);
  delay(1000);

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, HIGH);
    delay(1000);
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
}
