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
    
    










