#include "AssignHospitalController.h"
#include "mapwinctrl.h"

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

void AssignHospitalController::setXmlNewPatient(QString aHealthCardNum,QString aFName,QString aLName,QString aDateAdmitted,QString aDateWL,QString aReqCare,QString anOccCare,QString aFacilityId)
{
    QDateTime aDate = QDateTime::fromString("2003-05-30T09:00:00","yyyy-MM-dThh:mm:ss");

    //fake data
    aFacility = new Facility(-1,"TheFacility",4,2,4,5,0); //Will use the main facility list, but for now.LEt's assume 1 facility TO CHANGE

    QDateTime dateAdmitted = QDateTime::fromString(aDateAdmitted,"yyyy-MM-dThh:mm:ss");
    qDebug() << dateAdmitted;
    QDateTime datewl = QDateTime::fromString(aDateWL,"yyyy-MM-dThh:mm:ss");
    qDebug() << datewl;
    int req = aReqCare.toInt();
    int occ = anOccCare.toInt();
    Patient * aPatient = new Patient(aHealthCardNum,aFName,aLName,dateAdmitted,datewl, req,occ);
    //Now we have the patient, to access the facility, we have to find it. WE can do that by requesting list and looping through it.
    qDebug() << "half";
    MapWinCtrl::getinstance()->getFacilityFromid(aFacilityId,aFacility);
    //qDebug() << y;

  /*  if (req == 0)
        aFacility->addPatientAcute(aPatient);
    else
        if (req == 1)
            aFacility->addPatientComplex(aPatient);
        else
            if (req == 2)
                aFacility->addPatientLTC(aPatient);*/
}



