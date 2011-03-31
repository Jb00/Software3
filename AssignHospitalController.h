#ifndef ASSIGNHOSPITALCONTROLLER_H
#define ASSIGNHOSPITALCONTROLLER_H
#include <QString>
#include "Patient.h"
#include "Facility.h"

class AssignHospitalController
{

private :
        AssignHospitalController();
        static AssignHospitalController* anInstance;

public:
        static AssignHospitalController* getInstance();
        void addtoBed(Patient*,Facility*,QString);
        ~AssignHospitalController();

};

#endif // ASSIGNHOSPITALCONTROLLER_H
