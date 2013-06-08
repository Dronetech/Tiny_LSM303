#include <TinyWireM.h>
#include <LSM303_tiny.h>
#include <TinyDebugSerial.h>

LSM303_Tiny compass;
TinyDebugSerial mySerial;

void setup() {
  mySerial.begin(9600);
  TinyWireM.begin();
  compass.init(2);
  compass.enableDefault();
 
  // Calibration values. Use the Calibrate example program to get the values for
  // your compass.
  compass.m_min.x = -520; compass.m_min.y = -570; compass.m_min.z = -770;
  compass.m_max.x = +540; compass.m_max.y = +500; compass.m_max.z = 180;

}

void loop() {
  compass.read();
  int heading = compass.heading((LSM303_Tiny::vector){0,-1,0});
  mySerial.println(heading);
  delay(100);
}