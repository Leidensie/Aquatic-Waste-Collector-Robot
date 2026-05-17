#ifndef WATERSENSOR_H

#define WATERSENSOR_H

#include <Arduino.h>

class WaterSensor{

    //private:

    

    public:
uint8_t _waterpwm;
    WaterSensor(uint8_t waterpwm);

    void setup();
    bool isSink();

};



#endif