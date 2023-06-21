#include "qmainwindow.h"
#include "QListView"
#include "QTextEdit"
#include "QPushButton"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"

#ifndef EASYSHARE_MAINAPPWINDOW_H
#define EASYSHARE_MAINAPPWINDOW_H

#endif //EASYSHARE_MAINAPPWINDOW_H
#include "../sockio/PartnerScanner.h"

class MainAppPage : public QMainWindow {
Q_OBJECT

public:
    MainAppPage(QWidget *parent = nullptr);

    ~MainAppPage();
    PartnerScanner scanner;

    //设备对应的列表
    QListView *deviceList;
    //聊天信息列表
    QListView *chatList;
    QTextEdit *chatArea;
    QPushButton *sendButton;
    QHBoxLayout *rootLayout;
    QVBoxLayout *infoPaneLayout;
private slots:

    void sendMsg();

private:
    void initSlots();
};