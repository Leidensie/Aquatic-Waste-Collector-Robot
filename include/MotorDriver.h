#ifndef MOTORDRIVER.H 
#define MOTORDRIVER.H 
#include <Arduino.h>

class MotorDriver{

    private:

    uint8_t _pwm;

    public:

    MotorDriver(uint8_t pwm);

    void setup();
    void setThrust(int speed);
    void stop();

};

#endif