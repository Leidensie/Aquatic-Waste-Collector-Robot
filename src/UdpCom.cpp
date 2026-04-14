#include "UdpCom.h"

UdpCom::UdpCom(const char* ssid, const char* password, uint16_t port )

    : _ssid(ssid), _password(password), _port(port){

}

void UdpCom::start(){

    WiFi.softAP(_ssid, _password);
    _udp.begin(_port);

}

String UdpCom::listen(){

    if (_udp.parsePacket() > 0){

        _target_IP = _udp.remoteIP();
        _target_port = _udp.remotePort();

        int len = _udp.read(_package, 255);

        _package[len] = 0;

        return String(_package);

    }

    return "";




}

void UdpCom::send(String data){

if (_target_IP[0] == 0) {
        return; 
    }

    _udp.beginPacket(_target_IP, _target_port);
    
    _udp.print(data);
    
    _udp.endPacket();

}

