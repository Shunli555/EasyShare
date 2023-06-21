

#include "BroadCaster.h"
#include "NetConfig.h"

BroadCaster::BroadCaster() {
    initSockets();
}

void BroadCaster::start() {

}

void BroadCaster::stop() {

}

void BroadCaster::initSockets() {
    hostAddress = new QHostAddress(MULTICAST_ADDRESS);
    serverSocket = new QUdpSocket(this);
}

void BroadCaster::sendMsg(QString &data) {
    QByteArray datagram = data.toUtf8().data();
    serverSocket->writeDatagram(datagram, datagram.length(), *hostAddress, MULTICAST_PORT);
}
