#include <Arduino.h>
#include "UdpCom.h"

UdpCom comm("BetterStrongerFaster","12345678", 4210);
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
}
