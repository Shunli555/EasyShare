

#ifndef EASYSHARE_SERVER_H
#define EASYSHARE_SERVER_H

#include "Client.h"
#include "qlist.h"

/**
 * 用来接收其它设备发送过来的信息,基于tcp
 */
class Server {
public:
    Server(int port);

    ~Server();

    void start();

    void stop();

    void sendMsg(QString &data);

    QList<Client> *clients;
};


#endif //EASYSHARE_SERVER_H
