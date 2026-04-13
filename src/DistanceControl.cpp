#include "DistanceControl.h"

DistanceControl::DistanceControl() {
    m_trigpin = 5;
    m_echopin = 18;
    m_sonMesafe = 100.0; 
    
    pinMode(m_trigpin, OUTPUT);
    pinMode(m_echopin, INPUT);
}

float DistanceControl::CalDistance() {
    digitalWrite(m_trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(m_trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trigpin, LOW);

    float distance = pulseIn(m_echopin, HIGH, 30000) * 0.034 / 2.0;
    
    if (distance == 0.0 || distance > 400.0) {
        return m_sonMesafe; 
    }

    m_sonMesafe = distance;
    return distance;
}