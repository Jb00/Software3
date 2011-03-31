#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include <QString>
#include <QQueue>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include "Message.h"


class MessageController : public QThread
{
    Q_OBJECT
private :
 //       Message * aMessage;
        MessageController();
        static MessageController* anInstance; //The instance of the Singleton

        QQueue<QString> theMessages;

public:
        static MessageController* getInstance();
        void toSend(QString);
        ~MessageController();
        void run();

private slots:
   // void sendMessage();
   void setStuff();

signals :
        void mySignal();
};

#endif // MESSAGECONTROLLER_H
