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

        int len = _udp.read(_package, 255);

        _package[len] = 0;

        return String(_package);

    }

    return "";




}

