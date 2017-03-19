
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy,clik=0,clik1=0,clik2=0;/*, vxx,vy;*/
const int buttonPin = 5;     // the number of the pushbutton pin
const int button1Pin=6;
const int button2Pin=7;
//const int ledPin =  13;      // the number of the LED pin
int buttonState = 0;
int button1State=0;
int button2State=0;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 1000;    // the debounce time; increase if the output flickers

void setup() {
//delay(5000);
//flush
Serial.begin(38400);
  Wire.begin();
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
   mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   
  pinMode(buttonPin, INPUT);
  pinMode(button1Pin,INPUT);
pinMode(button2Pin,INPUT);
pinMode(8,OUTPUT);
   vx=0;
   vy=0;
  mpu.initialize();
  while (!mpu.testConnection()) {
    Serial.print(2);
    }
}

void loop() {
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
/*vxx=vx-gx-310;
  vyy=vy-gz+26;*/
  vx =-gx-310; // "-310" because the x axis of gyroscope give values about +310 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy =-gz+26;//  same here about "+26"

/* if(vxx<100&&vxx>-100)
  { vx=0;
    }
    if(vyy<100&&vyy>-100)
    {vy=0;}*/

  Serial.print(vx/800);
  Serial.print(",");
  Serial.print(vy/500);  
  Serial.print(",");
  /*
  Serial.print(ax);
  Serial.print(" ");
  Serial.print(ay);
  
  Serial.print(" ");
  Serial.print(az);
  
  Serial.print(" ");
  Serial.print(gx);
  
  Serial.print(" ");
  Serial.print(gy);
  
  Serial.print(" ");
  Serial.print(gz);

   Serial.print(" ");
  Serial.print(vx);
    Serial.print(" ");
  Serial.println(vy);
*/

 buttonState = digitalRead(buttonPin);
 button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  // if (millis()-cliktime>debound||(clik==0&&buttonState==LOW)) 
   //{
    
//    cliktime=millis();

// LEFT CLICK
    if (clik==0&&buttonState == LOW) {
   clik=1;
    // turn LED on:
    Serial.print("1,");
  } 
  else if (clik==1&&buttonState==HIGH){
    clik=0;
    // turn LED off:
    Serial.print("0,");
  }
  else {Serial.print("2,");}
  
  // RIGHT CLICK
   if (clik1==0&&button1State == LOW) {
   clik1=1;
    // turn LED on:
    Serial.print("1,");
  } 
  else if (clik1==1&&button1State==HIGH){
    clik1=0;
    // turn LED off:
    Serial.print("0,");
  }
  else {Serial.print("2,");}

  // Reload button
if (clik2==0&&button2State ==LOW) {
   clik2=1;
    // turn LED on:
    Serial.println("1");
  } 
  else if (clik2==1&&button2State==HIGH){
    clik2=0;
    Serial.println("0");
  }
  else {Serial.println("2");}
  
if (buttonState==LOW)
{if ((millis() - lastDebounceTime) > debounceDelay){
 digitalWrite(8,HIGH);
 lastDebounceTime=millis();
  }}

delay(0);
  
}
