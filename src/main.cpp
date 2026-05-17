#include <Arduino.h>
#include "UdpCom.h"
#include "DistanceControl.h"
#include "MotorDriver.h"
#include "WaterSensor.h"

UdpCom comm("BetterStrongerFaster", "12345678", 4210);
DistanceControl dist;
MotorDriver solMotor(26); 
MotorDriver sagMotor(32); 
WaterSensor doesboat(34);
unsigned long sensor_timer = 0;
int forward = 0;
int direction = 0;
float sonMesafe = 100.0;

void setup() {
    Serial.begin(115200);
    comm.start();
    solMotor.setup();
    sagMotor.setup();
    doesboat.setup();
}

void loop() {
    String message = comm.listen();
    if (message != "") {
        sscanf(message.c_str(), "%d,%d", &forward, &direction);
    }

    if (millis() - sensor_timer >= 100) {
        sensor_timer = millis(); 
        
        sonMesafe = dist.CalDistance(); 
        String telemetri = "DIST:" + String(sonMesafe);
        comm.send(telemetri);

        if(doesboat.isSink()){
            Serial.println("ALARM: Boat is sinking!");
            
            Serial.print("Su Miktari: ");
            Serial.println(analogRead(34)); 
        }
    }

    int solHiz = forward + direction;
    int sagHiz = forward - direction;

    solMotor.setThrust(solHiz);
    sagMotor.setThrust(sagHiz);
    
    delay(10); 
}