#include <TinyWireM.h>
#include <LSM303_tiny.h>
#include <TinyDebugSerial.h>

#define PI_FLOAT     3.14159265f
#define PIBY2_FLOAT  1.5707963f

LSM303_Tiny compass;

double pitch, roll;
int fRoll, fPitch;
const float alpha = 0.2;
double fXg = 0;
double fYg = 0;
double fZg = 0;
TinyDebugSerial mySerial;

void setup() {



  mySerial.begin( 9600 );

  //Start I2C
  TinyWireM.begin();
  //initialize as a LSM303DLHC
  compass.init(2);
  compass.enableDefault();

}


void loop() {
  
 
    //read lsm303dlhc values
     compass.read();
     
    //lowpass filter on 
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
  
   //Make sure the pitch and roll are between 0-180 to be used with the servos
    if(fRoll < 0)
    {
      fRoll = 0;
    }else if(fRoll > 180)
    {
      fRoll = 180;
    }    
 
    if(fPitch <0)
    {
      fPitch = 0;
    }else if(fPitch > 180)
    {
       fPitch = 180;
    }    
    
    //write the data in csv format
    mySerial.print(compass.a.x);
    mySerial.print(",");
    mySerial.print(compass.a.y);
    mySerial.print(",");
    mySerial.print(compass.a.z);
    mySerial.print(",");
    mySerial.print(fXg);
    mySerial.print(",");
    mySerial.print(fYg);
    mySerial.print(",");
    mySerial.print(fZg);
    mySerial.print(",");
    mySerial.print(fPitch);
    mySerial.print(",");
    mySerial.print(fRoll);
    mySerial.println();
    
   delay(50);
  
} 
