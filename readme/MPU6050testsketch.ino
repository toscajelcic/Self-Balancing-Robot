#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial) delay(10);

  mpu.initialize();

  Serial.println(mpu.testConnection() ? "MPU6050 connected!" : "MPU6050 connection failed!");
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("AccelX: "); Serial.print(ax);
  Serial.print(" AccelY: "); Serial.print(ay);
  Serial.print(" AccelZ: "); Serial.println(az);

  delay(200);
}