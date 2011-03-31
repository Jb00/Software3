#include "addfacctrl.h"

AddFacCtrl* AddFacCtrl::anInstance =NULL;


AddFacCtrl::AddFacCtrl()
{
    //Set value to meaningless value
    id = -1;
    facilityName ="";
    x= -1;
    y= -1;
    AC= -1;
    CCC= -1;
    LTC =-1;
    area ="";
}

AddFacCtrl* AddFacCtrl::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddFacCtrl; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}



void AddFacCtrl::addFacilityToMap(QString name, QString id, QString x, QString y, int acute, int complex, int longTerm, char type){

    switch(type){

    case 'h':

        break;

    case 'n':

        break;

    default:

        break;

    }
}

void AddFacCtrl::invalid(){

}




void AddFacCtrl::addToDb()
{
    if (!(facilityName == ""))
    {
        qDebug() <<"BEFORE";
        qDebug() <<facilityList->size();

        Facility * aFacility = new Facility(id, facilityName,x,y,AC,CCC,LTC); //Create the facility to add
        facilityList->append(aFacility); //Append it to the list of facility
        qDebug() <<"AFTER";
        qDebug() <<facilityList->size();
        facilityList=NULL;


    QSqlQuery query;
    QString queryText;

    //MISS AREA AND FACILITY ID UNSURE YET


    //the main insert script
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    queryText = "INSERT INTO facility (facilityID, name, coordinateX, coordinateY, AC, CCC,LTC)"
                " VALUES (:id, :facilityName, :x, :y, :AC, :CCC, :LTC)";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    query.prepare(queryText);

    //binding the variables from the form to the query
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    query.bindValue(":facilityID", id);
    query.bindValue(":facilityName", facilityName);
    query.bindValue(":x", x);
    query.bindValue(":y", y);
    query.bindValue(":AC", AC);
    query.bindValue(":CCC", CCC);
    query.bindValue(":LTC", LTC);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    query.exec(); //executing the query

    //checking if the facility was added correctly and if not an error is produced
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*   if(query.numRowsAffected() > 0){
        QMessageBox::information( this, "Add Facility Popup",
        "Facility " + facilityName + "has been added sucessfully!!");
    }
    else{
        QMessageBox::information( this, "error",
       "An error has occured while adding " + facilityName + " to the database");
    }
*/


//db.close();
}
    id = -1;
    facilityName ="";
    x= -1;
    y= -1;
    AC= -1;
    CCC= -1;
    LTC =-1;
    area ="";
}

void AddFacCtrl::setId(int anId)
{
    id = anId;
}

void AddFacCtrl::setX(int aX)
{
    x = aX;
}

void AddFacCtrl::setY(int aY)
{
    y= aY;
}

void AddFacCtrl::setAC(int anAC)
{
    AC = anAC;
}

void AddFacCtrl::setCCC(int aCCC)
{
    CCC =aCCC;
}

void AddFacCtrl::setLTC(int aLTC)
{
    LTC=  aLTC;
}

void AddFacCtrl::setName(QString aName)
{
        facilityName = aName;
}

void AddFacCtrl::setArea(QString anArea)
{
    area =anArea;
}

void AddFacCtrl::setList(QList<Facility *> *aFacilityList)
{
    facilityList = aFacilityList;
}
