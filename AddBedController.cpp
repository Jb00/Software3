#include "AddBedController.h"

AddBedController* AddBedController::anInstance = NULL; // Global static pointer used to ensure a single instance of the class.



AddBedController::AddBedController()
{
}

AddBedController* AddBedController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddBedController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AddBedController::addtoBed(QString aNumberBed, QString aType, Facility *aFacility)
{

    bool ok; //to make sure the conversion String to number Worked;
    int numberBedInt; //To hold the String to int
    QString numberBed = aNumberBed;

 //   QString type = typeid(*aFacility).name();
 //   std::cout <<'\n'<< typeid(aFacility).name();


    numberBedInt = numberBed.toInt(&ok);

    //Verify if it is a integer. If it isn't, return -1;
    if (!ok)
    {
        return;
    }

    if(aType == "Acute")
    {
        if (numberBedInt < 0)
        {
            if(!aFacility->removeBedAcute(numberBedInt))
                return; //invalid
        }
        else
        {
            for (int i=0; i< numberBedInt ; i++)
            {
                aFacility->addBedAcute();
            }
        }
    }
    else
        if(aType == "Complex")
        {
            if (numberBedInt < 0) //Negative
            {
                if(!aFacility->removeBedComplex(numberBedInt))
                    return;
            }
            else
            {
                for (int i=0; i< numberBedInt ; i++)
                {
                    aFacility->addBedComplex();
                }
            }
        }
    else
        if(aType == "LTC")
        {
            if (numberBedInt < 0)
            {
                if(!aFacility->removeBedLTC(numberBedInt))
                    return;
            }
            else
            {
                for (int i=0; i< numberBedInt ; i++)
                {
                    aFacility->addBedLTC();
                }
            }
        }
}
