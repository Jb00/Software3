#include "AddWLController.h"

AddWLController* AddWLController::anInstance =NULL; // Global static pointer used to ensure a single instance of the class.

AddWLController::AddWLController()
{
}


AddWLController* AddWLController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddWLController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AddWLController::addWaitingList(Patient * aPatient,Facility * aLTC)
{
    QDate today;

    today.currentDate();
    QDateTime anowDate(today);
    aPatient->setdateWL(anowDate);
    aLTC->addWaitingList(aPatient);
}

int AddWLController::getSize(Facility * aLTC)
{
    return aLTC->getSizeWL();
}


