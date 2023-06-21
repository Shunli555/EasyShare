

#include "PartnerScanner.h"
#include "NetConfig.h"

PartnerScanner::PartnerScanner() : address(QHostAddress(MULTICAST_ADDRESS)) {
    initSocket();
}

void PartnerScanner::initSocket() {
    scanner.bind(QHostAddress::AnyIPv4, MULTICAST_PORT,
                 QUdpSocket::ShareAddress);
    scanner.joinMulticastGroup(address);
    connect(&scanner, &QUdpSocket::readyRead, this, &PartnerScanner::onReadyToRead);
    qDebug("configure scanner");
}

void PartnerScanner::stop() {
    scanner.leaveMulticastGroup(address);
    scanner.abort();
}

void PartnerScanner::onReadyToRead() {
    qDebug("get info");
    auto *socket = dynamic_cast<QUdpSocket *>(sender());
    while (socket->hasPendingDatagrams()) {
        const QNetworkDatagram &datagram = socket->receiveDatagram();
        qInfo() << QString(datagram.data()) << datagram.senderAddress() << datagram.senderPort();
    }
}

PartnerScanner::~PartnerScanner() {
    qDebug("dead");
}
