#include "MessageController.h"


MessageController* MessageController::anInstance =NULL; // Global static pointer used to ensure a single instance of the class.


MessageController::MessageController()
    : QThread()
{
    connect(this,SIGNAL(mySignal()),this,SLOT(setStuff()));
   moveToThread(this);

}

MessageController::~MessageController()
{

}

void MessageController::run()
{
   // QTimer::singleShot(0,this,SLOT(setStuff()));

   emit(mySignal());
}

MessageController* MessageController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new MessageController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

/*void MessageController::sendMessage()
{
    message->tsend("test");

    while(!theMessages.empty())
    {

    }
}*/

void MessageController::setStuff()
{
    Message * message = new Message;
    while(1)
    {
        message->treceive();
   //     sendMessage();
        message->tsend("bitch");
    }
}

void MessageController::toSend(QString aMessage)
{
    theMessages.enqueue(aMessage);
}


