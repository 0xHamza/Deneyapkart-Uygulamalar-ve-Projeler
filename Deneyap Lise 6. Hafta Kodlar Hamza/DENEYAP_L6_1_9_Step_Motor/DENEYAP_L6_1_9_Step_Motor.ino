#include <Stepper.h>

const int adim = 2048;
int hiz;

Stepper myStepper(adim,D12,D13,D14,D15);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    hiz = Serial.read();
    Serial.print("Step Motor icin hiz girisi yapiniz: ");
    Serial.println(hiz);
  }

  myStepper.setSpeed(hiz);
  Serial.println("Saat yonunde donus.");
  myStepper.step(adim);
  delay(500);
  myStepper.setSpeed(hiz);
  Serial.println("Saat yonunde donus.");
  myStepper.step(-adim);
  delay(500);
}
