#include "lsm6dsm.h"
LSM6DSM IMU;

float accAngleX;
float accAngleY;

void setup() {
  Serial.begin(115200);
  IMU.begin();
}
void loop() {
  Serial.print("accel_x: ");
  Serial.println(IMU.readFloatAccelX());
  Serial.print("accel_y: ");
  Serial.println(IMU.readFloatAccelY());
  Serial.print("accel_z: ");
  Serial.println(IMU.readFloatAccelZ());
  delay(50);

  accAngleX = atan(IMU.readFloatAccelX() / sqrt(pow(IMU.readFloatAccelY(), 2) + pow(IMU.readFloatAccelZ(), 2)+0.001)) * 180 / PI;
  accAngleY = atan(-1 * IMU.readFloatAccelY() / sqrt(pow(IMU.readFloatAccelX(), 2) + pow(IMU.readFloatAccelZ(), 2)+0.001)) * 180 / PI;
  Serial.print("accAngleX: ");
  Serial.println(accAngleX);
  Serial.print("accAngleY: ");
  Serial.println(accAngleY);

}