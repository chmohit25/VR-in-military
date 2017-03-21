#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;/*, vxx,vy;*/
int receivedChar, lastshot;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 1000;    // the debounce time; increase if the output flickers

boolean newData = false;
void setup() {
  Serial.begin(38400);
   Wire.begin();
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //delay(5000);
    mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    vx=0;
    vy=0;
    mpu.initialize();
    if (!mpu.testConnection()) {
    while (1);
    }
    } 
  void loop()  {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

     vx=gy+245;
      
      Serial.println(vx/8000);
    if (Serial.available()) {
      receivedChar = (int)Serial.read();
      newData = true;
    }
    if (newData == true) {
      if (receivedChar == 49)
      {
        digitalWrite(4, HIGH);
        lastshot = 4;
        receivedChar = 0;
         lastDebounceTime=millis();
    }
      
      else if (receivedChar == 50)
      { digitalWrite(5, HIGH);
        lastshot = 5;
        receivedChar = 0;
         lastDebounceTime=millis();
      }
      else if (receivedChar ==51)
      { digitalWrite(6, HIGH);
        lastshot = 6;
         receivedChar = 0;
          lastDebounceTime=millis();
      }
      else if (receivedChar == 52)
      { digitalWrite(7, HIGH);
        lastshot = 7;
         receivedChar = 0;
          lastDebounceTime=millis();
      }
      else if (receivedChar == 53)
      { digitalWrite(8, HIGH);
        lastshot = 8;
        receivedChar = 0;
         lastDebounceTime=millis();
      }
      else if (receivedChar == 54)
      { digitalWrite(9, HIGH);
        lastshot = 9;
         receivedChar = 0;
          lastDebounceTime=millis();
      }
      else if (receivedChar == 55)
      { digitalWrite(10, HIGH);
        lastshot = 10;
        receivedChar = 0;
         lastDebounceTime=millis();
      }
      else if (receivedChar == 56)
      { digitalWrite(11, HIGH);
        lastshot = 11;
        receivedChar = 0;
         lastDebounceTime=millis();
      }
    }
    
     if ((millis() - lastDebounceTime) > debounceDelay) {
      digitalWrite(lastshot, LOW);
    }
}
