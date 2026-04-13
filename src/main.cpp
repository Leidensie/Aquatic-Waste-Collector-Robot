#include <Arduino.h>
#include "UdpCom.h"
#include "DistanceControl.h"
#include "MotorDriver.h"

DistanceControl dist;
UdpCom comm("BetterStrongerFaster", "12345678", 4210);

unsigned long sonSensorOkumaZamani = 0; 

void setup() {
    Serial.begin(115200);
    Serial.println("\n Lettuce Begin.");
    comm.start();
}

void loop() {
    String mesaj = comm.listen();
    if (mesaj != "") {
        Serial.print("Gelen Mesaj: ");
        Serial.println(mesaj);
    }

    if (millis() - sonSensorOkumaZamani >= 50) {
        sonSensorOkumaZamani = millis(); 
        
        float distance = dist.CalDistance();
        
        Serial.print("Mesafe: ");
        Serial.println(distance);
    }
}