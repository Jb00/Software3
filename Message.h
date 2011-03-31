#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include <QString>
#include <QMainWindow>
#include <QDialog>
#include <qobject.h>

class Message
{
private:
        QUdpSocket *udpSocket;
        QUdpSocket *udpReceive;
public:
    Message();
    void treceive();
    void tsend(QString);
};

#endif // MESSAGE_H
