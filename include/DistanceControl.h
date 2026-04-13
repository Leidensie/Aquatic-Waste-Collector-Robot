#ifndef DISTANCE_CONTROL_H
#define DISTANCE_CONTROL_H

#include <Arduino.h>

class DistanceControl {
  private:
    uint8_t m_trigpin;
    uint8_t m_echopin;
    float m_sonMesafe;

  public:
    DistanceControl();
    float CalDistance();
};

#endif