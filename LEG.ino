#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;/*, vxx,vy;*/
void setup() {
//delay(5000);
//flush
Serial.begin(75000);
  Wire.begin();
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
   mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   vx=0;
   vy=0;
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
    delay(5000);
}

void loop() {
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx =-gx-310; // "-310" because the x axis of gyroscope give values about +310 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy =-gz+26;//  same here about "+26"

  Serial.print(vx/800);
  Serial.print(",");
  Serial.println(vy/500);  

delay(0);
  
}

