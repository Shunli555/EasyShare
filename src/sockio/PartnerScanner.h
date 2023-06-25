

#ifndef EASYSHARE_PARTNERSCANNER_H
#define EASYSHARE_PARTNERSCANNER_H

#include <QtNetwork>
#include "qwidget.h"

/**
 * 用来搜索同一局域网内其它用户
 */
class PartnerScanner : public QWidget {
Q_OBJECT

public:
    QUdpSocket scanner;
    QHostAddress address;
public:
    PartnerScanner();

    ~PartnerScanner();

    void initSocket();

    void stop();

private slots:

    void onReadyToRead();
};


#endif //EASYSHARE_PARTNERSCANNER_H
