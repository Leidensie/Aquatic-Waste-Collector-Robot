#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pwm)

    : _pwm(pwm)
{};

void MotorDriver::setup(){

    pinMode( _pwm ,OUTPUT);
    digitalWrite(_pwm, LOW);
};

void MotorDriver::setThrust(int speed){

    if (speed >255){
        speed = 255;
    };
    analogWrite(_pwm, speed);
};

void MotorDriver::stop(){

    digitalWrite(_pwm,LOW);
};