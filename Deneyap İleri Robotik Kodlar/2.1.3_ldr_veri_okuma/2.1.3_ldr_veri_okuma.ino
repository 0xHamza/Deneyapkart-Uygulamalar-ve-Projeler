//2.1.3 LDR Veri Okuma, Dijital ve Analog

#define L1_pin D12 
#define L2_pin A0 

int digital, analog;

void setup() {
  Serial.begin(115200);
  pinMode(L1_pin, INPUT);
}

void loop() {
  
  digital = digitalRead(L1_pin); //sağ ışık sensöründen gelen dijital verinin okunması
  analog = analogRead(L2_pin); //sol ışık sensöründen gelen dijital verinin okunması

  Serial.print("Digital: ");
  Serial.println(digital);

  
  Serial.print("Analog: ");
  Serial.println(analog);
  delay(1000);
}
