

#include "DeviceInfo.h"

DeviceInfo::DeviceInfo(QString *userName, QString *ip, int port) {
    setUserName(userName);
    setIP(ip);
    setPort(port);
}

QString *DeviceInfo::getDeviceId() {
    return deviceId;
}

QString *DeviceInfo::getUserName() {
    return userName;
}

QString *DeviceInfo::getIP() {
    return ip;
}

int DeviceInfo::getPort() {
    return port;
}

void DeviceInfo::setPort(int port) {
    this->port = port;
}

void DeviceInfo::setIP(QString *ip) {
    this->ip = ip;
}

void DeviceInfo::setUserName(QString *name) {
    this->userName = name;
}

QJsonObject DeviceInfo::toJson() {
    QJsonObject object;
    object["userName"] = *getUserName();
    object["ip"] = *getIP();
    object["deviceId"] = *getDeviceId();
    object["port"] = getPort();
    return object;
}
