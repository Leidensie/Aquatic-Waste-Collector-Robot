#include "WaterSensor.h"

WaterSensor::WaterSensor(uint8_t pwm){

    _waterpwm = pwm;
};

void WaterSensor::setup(){

    pinMode(_waterpwm,INPUT);
};
bool WaterSensor::isSink(){

    if (analogRead(_waterpwm) > 1000 ){

        return true;
    }
    else{
        return false;
    }

};