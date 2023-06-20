#include <QApplication>
#include <QPushButton>
#include "ui/MainAppPage.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *appPage = new MainAppPage(nullptr);
    appPage->resize(800, 600);
    appPage->show();
    return QApplication::exec();
}
