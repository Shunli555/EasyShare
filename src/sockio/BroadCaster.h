

#ifndef EASYSHARE_BROADCASTER_H
#define EASYSHARE_BROADCASTER_H

#include "QtNetwork"
#include "NetConfig.h"

/**
 * 用来广播自身的ip及port等信息，便于处于同一局域网的其它设备搜索和连接
 */
class BroadCaster : public QObject {
Q_OBJECT

public:
    QUdpSocket *serverSocket;

    QHostAddress *hostAddress;
public:
    BroadCaster();

    void initSockets();

    void start();

    void stop();

    void sendMsg(QString &data);

public slots:

    void onReadReady();
};


#endif //EASYSHARE_BROADCASTER_H
