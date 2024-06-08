#define b1_pin D0
#define x1_pin A0
#define y1_pin A1
#define x2_pin A2
#define Y2_pin A3
#define b2_pin D1
int derece_x1=90;
int derece_y1=90;
int derece_x2=90;
int derece_y2=90;

int joy1_Y, joy1_X, joy2_X, joy2_Y;

void setup() {
  Serial.begin(115200);
}

void loop() {

  joy1_Y = analogRead(y1_pin);
  joy1_X = analogRead(x1_pin);
  joy2_Y = analogRead(Y2_pin);
  joy2_X = analogRead(x2_pin);

  derece_x1 = (joy1_X / 4095.0) * 180;
  derece_x2 = (joy2_X / 4095.0) * 180;
  derece_y1 = (joy1_Y / 4095.0) * 180;
  derece_y2 = (joy2_Y / 4095.0) * 180;

  Serial.print("X1:"); Serial.print(derece_x1);  Serial.print("° - "); Serial.println(joy1_X);
  Serial.print("Y1:");Serial.print(derece_y1); Serial.print("° - "); Serial.println(joy1_Y);


  Serial.print("X2:"); Serial.print(derece_x2);  Serial.print("° - "); Serial.println(joy2_X); 
  Serial.print("Y2:"); Serial.print(derece_y2); Serial.print("° - "); Serial.println(joy2_Y);

  Serial.println();

  delay(50);
}
