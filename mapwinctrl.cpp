#include "mapwinctrl.h"

MapWinCtrl::MapWinCtrl()
{
    QDate aDate(1998,2,3);

    //fake data
    aFacility2 = new Facility(5,"TheFacility",4,2,4,5,0); //Will use the main facility list, but for now.LEt's assume 1 facility TO CHANGE
    aFacility3 = new Facility(8,"ttt",4,50,0,0,6); //Will use the main facility list, but for now.LEt's assume 1 facility TO CHANGE
    aFacility4 = new Facility(9,"eeee",70,2,80,5,0); //Will use the main facility list, but for now.LEt's assume 1 facility TO CHANGE

    aPatient15 = new Patient ("12e","Bob","Henry",aDate,aDate,7,8);
    aPatient16 = new Patient ("12e","Bob","Henry",aDate,aDate,7,8);
    aPatient17 = new Patient ("12e","Bob","Henry",aDate,aDate,7,8);


   setupFacility(); //Where in reality our Db will only contains 1 facility ? So only the first facility will be set there.
   setupPatients(); //Put all patients inside the facility
//   listOfPatient.append(aPatient15);listOfPatient.append(aPatient16);listOfPatient.append(aPatient17);
   listOfFacility.append(aFacility2);listOfFacility.append(aFacility3);listOfFacility.append(aFacility4);
   MessageController::getInstance()->start();


}
MapWinCtrl::~MapWinCtrl(){}


void MapWinCtrl::goToAddUser()
{
    addUserWin = new AddUserWindow();
    addUserWin->show();
    AddUserCtrl::getInstance()->setList(&listOfUser);
    genCTRL::center(*addUserWin);
}

void MapWinCtrl::goToAddFac()
{
    addFac = new AddFacility();
    addFac->show();
    AddFacCtrl::getInstance()->setList(&listOfFacility);
    genCTRL::center(*addFac);
}

void MapWinCtrl::gotoFacility()
{
    aFacilityView = new FacilityWindow();
    aFacilityView->show();
    aFacilityView->setUI(listOfFacility.at(0));
  //  AddFacCtrl::getInstance()->setList(&listOfFacility);
  //  genCTRL::center(*addFac);
}


//Put from DB to our list the patients

void MapWinCtrl::setupPatients()
{
    QSqlQuery query;
    QString HealthCardNum;
    QString firstName ;
    QString lastName;
    QDate dateAdmitted ;
    QDate datePlacedOnWaitingList;
    int reqCare;
    int occCare;

     query.exec("SELECT dateAdmitted,datePlacedOnWaitingList,firstName,healthCardNum, lastName ,occCare,reqCare FROM patient ");

     while (query.next()) {
         HealthCardNum =query.value(3).toString();
         firstName = query.value(2).toString();
         lastName = query.value(4).toString();
         datePlacedOnWaitingList = query.value(1).toDate();
         dateAdmitted = query.value(0).toDate();
         occCare = query.value(5).toInt();
         reqCare = query.value(6).toInt();

         Patient * aPatient = new Patient(HealthCardNum, firstName,lastName,dateAdmitted,datePlacedOnWaitingList,reqCare,occCare);
         if(occCare == 0){
             if (listOfFacility.at(0)->NUsedBedAcute())
             {
                 listOfFacility.at(0)->addPatientAcute(aPatient);
             }
         }

         else if (occCare == 1){
             if (listOfFacility.at(0)->NUsedBedComplex())
             {
                 listOfFacility.at(0)->addPatientComplex(aPatient);
             }
         }

         else{
                 if (listOfFacility.at(0)->NUsedBedLTC())
                 {
                     listOfFacility.at(0)->addPatientLTC(aPatient);
                 }
             }

  //       listOfPatient.append(aPatient);
     }
     query.clear();
}

void MapWinCtrl::setupUser()
{
     QSqlQuery query;
     QString userName ;
     QString password;
     QString type;

     query.exec("SELECT password,permissionLvl,username FROM user");

     while (query.next()) {
         userName =query.value(0).toString();
         password = query.value(1).toString();
         type = query.value(2).toString();

         User * aUser = new User(password,userName,type);
         listOfUser.append(aUser);
     }
}


void MapWinCtrl::setupFacility()
{
    int id,x,y,AC,CCC,LTC,i;
    QString facilityName;
    QSqlQuery query;
    query.exec("SELECT AC,CCC,coordinateX,coordinateY,facilityID,LTC,name FROM facility ");

    int temp=0;

    while (query.next()) {
        AC = query.value(0).toInt();
        CCC = query.value(1).toInt();
        x = query.value(2).toInt();
        y = query.value(3).toInt();
        id = query.value(4).toInt();
        LTC = query.value(5).toInt();
        facilityName = query.value(6).toString();


        Facility * aFacility = new Facility(id,facilityName,x,y,AC,CCC,LTC);
        listOfFacility.append(aFacility);



        //Add The right number of bed for the right number that was stored in the database.
        if (AC > 0) //There is AC # bed to add to the facility
        {
            //IF TO ADD SET FACILITY TYPE, IT WOULD BE HERE
            for(i =0;i<AC;i++)
            {
            listOfFacility.at(temp)->addBedAcute();
            }
        }
        if (CCC > 0) //There is CCC # bed to add to the facility
        {
            for(i =0;i<CCC;i++)
            {
            listOfFacility.at(temp)->addBedComplex();
            }
        }
        if (LTC > 0) //There is LTC # bed to add to the facility
        {
            for(i =0;i<LTC;i++)
            {
            listOfFacility.at(temp)->addBedLTC();
            }
        }

        temp++;
    }
    query.clear();
}

