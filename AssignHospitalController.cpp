#include "AssignHospitalController.h"

AssignHospitalController* AssignHospitalController::anInstance =NULL;

AssignHospitalController::AssignHospitalController()
{
}

AssignHospitalController::~AssignHospitalController()
{
}

AssignHospitalController* AssignHospitalController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AssignHospitalController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AssignHospitalController::addtoBed(Patient * aPatient, Facility * aFacility,QString aType)
{

    if(aType == "Complex")
    {
            if (aFacility->NUsedBedComplex())
            {
                std::cout <<"COMPLEX";
                aFacility->addPatientComplex(aPatient);

            }
    }
    else
        if(aType == "Acute")
        {
             if (aFacility->NUsedBedAcute())
             {
                 std::cout <<"SUPER INSIDE"<<std::endl;
                 aFacility->addPatientAcute(aPatient);
             }
        }
        else
            std::cout<<"ERROR";                                         //Test only , should not happens.
}



