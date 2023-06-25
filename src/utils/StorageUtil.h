

#ifndef EASYSHARE_STORAGEUTIL_H
#define EASYSHARE_STORAGEUTIL_H

#endif //EASYSHARE_STORAGEUTIL_H

#include "QSettings"

class StorageUtil {
private:
    static QSettings *getSetting() {
        auto *settings = new QSettings;
        QSettings::setDefaultFormat(QSettings::IniFormat);
        return settings;
    }

public :
    static void savePrefString(const QString &key, const QString &value) {
        QSettings qSettings;
        qSettings.setValue(key, value);
    }

    static QString getPrefString(const QString &key) {
        QSettings qSettings;
        return qSettings.value(key).toString();
    }

    static int getPrefInt(const QString &key) {
        QSettings qSettings;
        return qSettings.value(key).toInt();
    }

    static void savePrefInt(const QString &key, const int &value) {
        QSettings qSettings;
        qSettings.setValue(key, value);
    }
};