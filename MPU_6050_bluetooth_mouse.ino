#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11,10);

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy,clik=0,clik1=0;/*, vxx,vy;*/
const int buttonPin = 5;     // the number of the pushbutton pin
const int button1Pin=6;
//const int ledPin =  13;      // the number of the LED pin
int buttonState = 0;
int button1State=0;
void setup() {
  bluetooth.begin(9600);
  Wire.begin();
   mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   
  pinMode(buttonPin, INPUT);
  pinMode(button1Pin,INPUT);
  
   vx=0;
   vy=0;
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
}

void loop() {
  
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
/*vxx=vx-gx-310;
  vyy=vy-gz+26;*/
  vx =-gx-310;
  vy =-gz+26;

/* if(vxx<100&&vxx>-100)
  { vx=0;
    }
    if(vyy<100&&vyy>-100)
    {vy=0;}*/

  bluetooth.print(vx/800);
  bluetooth.print(",");
  bluetooth.print(vy/500);  
  bluetooth.print(",");
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
 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  // if (millis()-cliktime>debound||(clik==0&&buttonState==LOW)) 
   //{
    
//    cliktime=millis();

// LEFT CLICK
    if (clik==0&&buttonState == LOW) {
   clik=1;
    // turn LED on:
    bluetooth.print("1,");
  } 
  else if (clik==1&&buttonState==HIGH){
    clik=0;
    // turn LED off:
   bluetooth.print("0,");
  }
  else {bluetooth.print("2,");}
  
  // RIGHT CLICK
   if (clik1==0&&button1State == LOW) {
   clik1=1;
    // turn LED on:
    bluetooth.println(1);
  } 
  else if (clik1==1&&button1State==HIGH){
    clik1=0;
    // turn LED off:
    bluetooth.println(0);
  }
  else {bluetooth.println(2);}
   //}
delay(0);
  
}
