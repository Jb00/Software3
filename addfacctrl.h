#ifndef ADDFACCTRL_H
#define ADDFACCTRL_H

#include <QDialog>

#include <QList>
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QSqlTableModel>

#include "addfacility.h"
#include "Facility.h"
#include "genctrl.h"


class AddFacCtrl: public genCTRL
{
private :
        AddFacCtrl();
        static AddFacCtrl* anInstance;

        int id;
        QString facilityName;
        int x;
        int y;
        int AC;
        int CCC;
        int LTC;
        QString area;
        QList<Facility *> *facilityList;

public:


    static AddFacCtrl* getInstance();

    void addFacilityToMap(QString, QString, QString, QString, int, int, int, char);

    void invalid();

    void addToDb();
    void setId(int);
    void setX(int);
    void setY(int);
    void setAC(int);
    void setCCC(int);
    void setLTC(int);
    void setName(QString);
    void setArea(QString);
    void setList(QList<Facility *>*);
};

#endif // ADDFACCTRL_H

