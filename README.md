Tiny85 LSM303
===========

### Description
This library is a port from the Pololu LSM303 library to be used with atmega Attiny85 using the Arduino bootloader.

It was designed to be used in small and affordable devices that don't require many GPIO but would benefict from the use of a
lsm303dlhc sensor. 

It can be used to interface with our LSM303DLHC breakout board: http://www.dronetech.eu/store/index.php?route=product/product&product_id=51

---

### Dependencies

* TinyWire library: http://playground.arduino.cc/Code/USIi2c
* One of the arduino cores: http://hlt.media.mit.edu/?p=1695 or https://code.google.com/p/arduino-tiny/

### Wiring Example


    LSM303DLHC    Attiny85
    LREF      ->  5V (assuming your attiny is working at 5V)
    VCC       ->  3.3V (regulated)
    GND       ->  GND
    SDA       ->  PB0
    SCL       ->  PB2
    
### Instalation 

Unzip this folder to the Arduino Libraries folder. 
    
### Code Examples description

---

### TinyHeading

Sends the current heading to the serial port using TinyDebugSerial

    Wiring
    Attiny85
    PB3     ->  Serial RX 
    PB0     ->  SDA 
    PB2     ->  SCL
    
*note: since it uses the TinyDebugSerial it can only be used with the tiny-core
    
### TinySerialData

Sends raw and filtered accelerometer data to serial port in csv format.

    Wiring
    Attiny85
    PB3     ->  Serial RX 
    PB0     ->  SDA 
    PB2     ->  SCL
    
*note: since it uses the TinyDebugSerial it can only be used with the tiny-core
*note2: it can be visualized with the DTSerialChart available here: https://github.com/Dronetech/DTSerialChart
    
### TinyStabilizer

Drives two micro servos compensating the pitch and roll of the board. 

It uses only accelerometer data with a low pass filter. Slow and noisy but effective.

    Wiring
    Attiny85
    PB3     ->  Servo
    PB1     ->  Servo
    PB0     ->  SDA 
    PB2     ->  SCL
    
*note: this example requires de Servo8bit library available here: https://github.com/fri000/Servo8Bit

    
    










