#include <TinyWireM.h>
#include <LSM303_tiny.h>
#include <Servo8Bit.h>


#define PI_FLOAT     3.14159265f
#define PIBY2_FLOAT  1.5707963f

LSM303_Tiny compass;
Servo8Bit  sRoll, sPitch;
int oldRoll, oldPitch;
double pitch, roll;
int fRoll, fPitch;
const float alpha = 0.2;
double fXg = 0;
double fYg = 0;
double fZg = 0;


void setup() {

  
  TinyWireM.begin();
  compass.init(2);
  compass.enableDefault();
  sRoll.attach(1);
  sPitch.attach(3);

  sRoll.write(90);
  sPitch.write(90);
  delay(1000);
  sRoll.write(0);
  sPitch.write(0);
  delay(1000);
  sRoll.write(180);
  sPitch.write(180);
  delay(1000);
  

}



void loop() {
  
 
    compass.read();
    
  
  //lowpass
  fXg = compass.a.x * alpha + (fXg * (1.0 - alpha));
  fYg = compass.a.y * alpha + (fYg * (1.0 - alpha));
  fZg = compass.a.z * alpha + (fZg * (1.0 - alpha));
   
 //Roll & Pitch Equations
 roll  = (atan2(-fYg, fZg)*180.0)/M_PI;
 pitch = (atan2(fXg, sqrt(fYg*fYg + fZg*fZg))*180.0)/M_PI;
  

  fRoll = (-1*roll + 90) * alpha + (fRoll * (1.0 - alpha));
  fRoll = floor(fRoll);
  fPitch = (-1*pitch + 90) * alpha + (fPitch * (1.0 - alpha));
  fPitch = floor(fPitch);
  
 
    if(fRoll < 0)
    {
      fRoll = 0;
    }else if(fRoll > 180)
    {
      fRoll = 180;
    }
    
    sRoll.write(fRoll);
   
  
  
    if(fPitch <0)
    {
      fPitch = 0;
    }else if(fPitch > 180)
    {
       fPitch = 180;
    }    
    
    sPitch.write(fPitch);
    delay(50);
  
} 
