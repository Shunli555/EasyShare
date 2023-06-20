#ifndef EASYSHARE_MESSAGE_H
#define EASYSHARE_MESSAGE_H

#include "QStringList"
#include "QString"

enum MessageType {
    T_TEXT, T_IMAGE, T_AUDIO, T_VIDEO, T_FILE, T_DIRECTORY, T_GROUP, T_UNKNOWN
};

class DataGroup;

class Message {
public:
    Message(MessageType messageType, DataGroup *dataGroup = nullptr, QString *dataString = nullptr,
            QString *dataFile = nullptr);

    ~Message();

    /**
     * 确定当前传输文件的类型
     */
    MessageType messageType;
    /**
     * 仅当类型为T_GROUP时使用
     */
    DataGroup *dataGroup;
    /**
     * 仅当类型为T_TEXT时使用
     */
    QString *dataString;
    /**
     * 当类型为其它文件和文件夹时使用
     */
    QString *dataFile;
};

class DataGroup {
    QStringList *pathList;
    QString *baseDir;
};

#endif //EASYSHARE_MESSAGE_H
