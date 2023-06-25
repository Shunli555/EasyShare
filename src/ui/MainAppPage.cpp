
#include "MainAppPage.h"
#include "QtCore"
#include "QFileDialog"

MainAppPage::MainAppPage(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("快传");
    auto *rootWidget = new QWidget;
    setCentralWidget(rootWidget);

    this->rootLayout = new QHBoxLayout(rootWidget);
    rootLayout->setContentsMargins(QMargins(0, 0, 20, 0));
    rootLayout->setSpacing(0);

    this->deviceList = new QListView;
    QSizePolicy deviceListPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    deviceListPolicy.setHorizontalStretch(1);
    this->deviceList->setSizePolicy(deviceListPolicy);

    auto *infoPaneWidget = new QWidget();
    this->infoPaneLayout = new QVBoxLayout(infoPaneWidget);
    infoPaneLayout->setContentsMargins(QMargins(0, 0, 0, 10));
    infoPaneLayout->setSpacing(0);

    this->chatList = new QListView();
    QSizePolicy chatListPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    chatListPolicy.setVerticalStretch(3);
    chatList->setSizePolicy(chatListPolicy);

    this->chatArea = new QTextEdit();
    QSizePolicy chatAreaPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    chatAreaPolicy.setVerticalStretch(1);
    chatArea->setSizePolicy(chatAreaPolicy);

    this->sendButton = new QPushButton("发送");

    this->sendButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    selectFileButton = new QPushButton("选择文件");
    selectFileButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    auto *sendParent = new QHBoxLayout;
    sendParent->addStretch();
    sendParent->addWidget(selectFileButton);
    sendParent->addSpacing(10);
    sendParent->addWidget(sendButton);
    sendParent->setContentsMargins(0, 10, 0, 10);


    this->infoPaneLayout->addWidget(this->chatList);
    this->infoPaneLayout->addSpacing(20);
    this->infoPaneLayout->addWidget(this->chatArea);
    this->infoPaneLayout->addLayout(sendParent);

    QSizePolicy infoPanePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    infoPanePolicy.setHorizontalStretch(3);
    infoPaneWidget->setSizePolicy(infoPanePolicy);

    this->rootLayout->addWidget(deviceList);
    this->rootLayout->addWidget(infoPaneWidget);

    initSlots();
    qDebug("scanner started");
}

MainAppPage::~MainAppPage() {

}

void MainAppPage::sendMsg() {
    qDebug("i am clicked");
}

void MainAppPage::initSlots() {
    connect(sendButton, SIGNAL(clicked(bool)), this, SLOT(sendMsg()));
    connect(selectFileButton, &QPushButton::clicked, this, &MainAppPage::selectFile);
}

void MainAppPage::selectFile() {
    const QString &fileName = QFileDialog::getOpenFileName(this->centralWidget(), "选择一个文件", Q_NULLPTR,
                                                           "所有文件(*.*)");
    if (fileName.isEmpty()) {
        qDebug("File is invalid");
        return;
    }
    qDebug() << "File is %s:" << fileName;
}
