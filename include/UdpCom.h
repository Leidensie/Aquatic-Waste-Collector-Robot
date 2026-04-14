#ifndef UDPCOM_H
#define UDPCOM_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

class UdpCom
{
private:
    const char* _ssid;
    const char* _password;
    char _package[255];

    //target IP adress 

    IPAddress _target_IP;
    uint16_t _target_port;

    uint16_t _port;
    WiFiUDP _udp;
    

public:

    UdpCom(const char* ssid, const char* password, uint16_t port );

    void start();

//    void stop();

    String listen();

    void send(String data);


};
#endif
