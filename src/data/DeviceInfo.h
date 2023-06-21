

#ifndef EASYSHARE_DEVICEINFO_H
#define EASYSHARE_DEVICEINFO_H

#include "QString"
#include "QJsonObject"

class DeviceInfo {
public:
    DeviceInfo(QString *userName, QString *ip, int port);

private:
    QString *deviceId;//generate an uuid
    QString *userName;//readable name
    QString *ip;//device ip
    qint16 port;//device port
public:
    QString *getDeviceId();

    QString *getUserName();

    QString *getIP();

    int getPort();

    void setPort(int port);

    void setIP(QString *ip);

    void setUserName(QString *name);

    QJsonObject toJson();
};


#endif //EASYSHARE_DEVICEINFO_H
