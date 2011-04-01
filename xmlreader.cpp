#include <QtXml/QDomDocument>
#include "xmlreader.h"
#include <QDebug>
#include <qlist.h>
#include <QtSql>
#include <QMessageBox>


XMLReader::XMLReader()
{



    xmlHeader = "<?xml version=\"1.0\" encoding=\"utf-8\"?>";

    xmlRequest = "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
    xmlRequest.append("<Delete remote=\"true\">");
          xmlRequest.append("<Area ID=\"5\">");
                 xmlRequest.append("<Facility ID=\"7\">");
                xmlRequest.append("<PatientList>");
                           xmlRequest.append("<Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                           xmlRequest.append("<Patient firstName=\"Jim\" lastName=\"Doe\" healthCardNumber=\"4444333223\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                           xmlRequest.append("<Patient firstName=\"Joe\" lastName=\"Doe\" healthCardNumber=\"4444333224\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                           xmlRequest.append("<Patient firstName=\"James\" lastName=\"Doe\" healthCardNumber=\"4444333225\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
               xmlRequest.append("</PatientList>");
                 xmlRequest.append("</Facility>");
           xmlRequest.append("</Area>");
           xmlRequest.append("<Area ID=\"6\">");
                  xmlRequest.append("<Facility ID=\"6\">");
                     xmlRequest.append("<PatientList>");
                                xmlRequest.append("<Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                                xmlRequest.append("<Patient firstName=\"Jim\" lastName=\"Doe\" healthCardNumber=\"4444333223\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                                xmlRequest.append("<Patient firstName=\"Joe\" lastName=\"Doe\" healthCardNumber=\"4444333224\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                                xmlRequest.append("<Patient firstName=\"James\" lastName=\"Doe\" healthCardNumber=\"4444333225\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                    xmlRequest.append("</PatientList>");
                  xmlRequest.append("</Facility>");
                  xmlRequest.append("<Facility ID=\"33\">");
                     xmlRequest.append("<PatientList>");
                                xmlRequest.append("<Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                                xmlRequest.append("<Patient firstName=\"Jim\" lastName=\"Doe\" healthCardNumber=\"4444333223\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                                xmlRequest.append("<Patient firstName=\"Joe\" lastName=\"Doe\" healthCardNumber=\"4444333224\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                                xmlRequest.append("<Patient firstName=\"James\" lastName=\"Doe\" healthCardNumber=\"4444333225\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"2\" occCare=\"2\"/>");
                    xmlRequest.append("</PatientList>");
                  xmlRequest.append("</Facility>");
            xmlRequest.append("</Area>");
     xmlRequest.append("</Delete>");


     /* xmlRequest.append("<Delete remote=\"true\">");
             xmlRequest.append("<Area ID=\"5\">");
               xmlRequest.append("<WaitingList>");
                 xmlRequest.append("<Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333333\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
                 xmlRequest.append("<Patient firstName=\"Jim\" lastName=\"Doe\" healthCardNumber=\"4444333334\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
                 xmlRequest.append("<Patient firstName=\"Joe\" lastName=\"Doe\" healthCardNumber=\"4444333335\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
                 xmlRequest.append("<Patient firstName=\"James\" lastName=\"Doe\" healthCardNumber=\"4444333336\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
               xmlRequest.append("</WaitingList>");
             xmlRequest.append("</Area>");
             xmlRequest.append("<Area ID=\"6\">");
               xmlRequest.append("<WaitingList>");
                 xmlRequest.append("<Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333333\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
                 xmlRequest.append("<Patient firstName=\"Jim\" lastName=\"Doe\" healthCardNumber=\"4444333334\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
                 xmlRequest.append("<Patient firstName=\"Joe\" lastName=\"Doe\" healthCardNumber=\"4444333335\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
                 xmlRequest.append("<Patient firstName=\"James\" lastName=\"Doe\" healthCardNumber=\"4444333336\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/>");
               xmlRequest.append("</WaitingList>");
             xmlRequest.append("</Area>");
       xmlRequest.append("</Delete>"); */

     /* xmlRequest.append("<Add remote=\"true\">");
         xmlRequest.append("<Area ID=\"5\">");
             xmlRequest.append("<Facility ID=\"7\" CCC=\"10\"/>");
             xmlRequest.append("<Facility ID=\"4010\" AC=\"10\"/>");
        xmlRequest.append("</Area>");
        xmlRequest.append("<Area ID=\"6\">");
            xmlRequest.append("<Facility ID=\"4005\" AC=\"10\"/>");
       xmlRequest.append("</Area>");
       xmlRequest.append("<Area ID=\"7\">");
           xmlRequest.append("<Facility ID=\"4005\" LTC=\"10\"/>");
      xmlRequest.append("</Area>");
     xmlRequest.append("</Add>"); */

    /* xmlRequest.append("<Request ID=\"3\">");
         xmlRequest.append("<Report startDate=\"2011-03-31T23:21:29\" endDate=\"2011-03-32T23:21:29\">");
             xmlRequest.append("<FacilityRecord>");
                 xmlRequest.append("<Facility ID=\"7\"/>");
                 xmlRequest.append("<Facility ID=\"22\"/>");
                 xmlRequest.append("<ACRecord occupied=\"0\"/>");
             xmlRequest.append("</FacilityRecord>");
         xmlRequest.append("</Report>");
     xmlRequest.append("</Request>"); */

    /* xmlRequest.append("<Request ID=\"7\">");
         xmlRequest.append("<Report startDate=\"X\" endDate=\"Y\">");
             xmlRequest.append("<WaitingListRecord>");
                 xmlRequest.append("<Patient dateAdded=\"1920-03-02T11:15:32\" dateAdmitted=\"1920-03-02T11:15:32\" />");
                 xmlRequest.append("<Patient dateAdded=\"1920-03-02T11:15:32\" dateAdmitted=\"1920-03-02T11:15:32\" />");
                 xmlRequest.append("<Patient dateAdded=\"1920-03-02T11:15:32\" dateAdmitted=\"1920-03-02T11:15:32\" />");
                 xmlRequest.append("<Patient dateAdded=\"1920-03-02T11:15:32\" dateAdmitted=\"1920-03-02T11:15:32\" />");
             xmlRequest.append("</WaitingListRecord>");
         xmlRequest.append("</Report>");
     xmlRequest.append("</Request>"); */

 /*     xmlRequest.append("<Request ID=\"7\">");
          xmlRequest.append("<Report startDate=\"1920-03-02T11:15:32\" endDate=\"2011-03-32T23:21:29\">");
              xmlRequest.append("<WaitingListRecord>");
                  xmlRequest.append("<Patient dateAdded=\"0\" dateAdmitted=\"0\" />");
              xmlRequest.append("</WaitingListRecord>");
          xmlRequest.append("</Report>");
      xmlRequest.append("</Request>");*/

    /* xmlRequest.append("<Request ID=\"12\">");
         xmlRequest.append("<Report startDate=\"1983-03-02T11:15:32\" endDate=\"2011-03-32T23:21:29\">");
             xmlRequest.append("<WaitingListRecord listSize=\"425\" />");
         xmlRequest.append("</Report>");
     xmlRequest.append("</Request>"); */



    /* xmlRequest.append("<Request ID=\"5\">");
         xmlRequest.append("<Report startDate=\"1983-03-02T11:15:32\" endDate=\"2011-03-32T23:21:29\">");
             xmlRequest.append("<FacilityRecord>");
                 xmlRequest.append("<Facility ID=\"3\"/>");
                 xmlRequest.append("<Facility ID=\"7\"/>");
                 xmlRequest.append("<CCCRecord occupiedByLTC=\"0\" />");
             xmlRequest.append("</FacilityRecord>");
         xmlRequest.append("</Report>");
     xmlRequest.append("</Request>"); */

}


QString XMLReader::readRequest(QString aRequest)
{
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();

       qDebug() << "m.attribute: " << m.attribute("remote");

       QString type = root.tagName();

       //adding and deleting
        if((type == "Add" || type == "Delete") && root.attribute("remote") == "true") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.firstChild().toElement();

            if(m.tagName() == "Facility") {
                if (m.attributes().count() > 1){
                    return readAddRemoveBeds(xmlRequest, type);
                }
                else{
                    return readAddorDeleteToFacility(xmlRequest, type);
                }
            }
            else if(m.tagName() == "WaitingList") {
                return readAddorDeleteToWaitingList(xmlRequest, type);
            }
        }

        //requests
        if(type == "Request") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.toElement();

            qDebug() << m.tagName();

            if(m.tagName() == "Report") {
                n = n.firstChild();
                m = n.toElement();
                if(m.tagName() == "FacilityRecord") {
                    return reportBeds(xmlRequest);
                }
                else if(m.tagName() == "WaitingListRecord") {
                    if (m.attributes().count() > 0){
                        return reportWaitingListSize(xmlRequest);
                    }
                    else{
                       return reportWaitingList(xmlRequest);
                    }
                }
            }
        }

        return "-1";
    }
}


QString XMLReader::readAddorDeleteToFacility(QString aRequest, QString addOrDelete){
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();

        QString areaID;
        QString facilityID;

        while (!n.isNull() ){
            if(m.tagName() == "Area") {
                areaID = m.attribute("ID");
                QDomNode facilityNode = n.firstChild();
                QDomElement facilityElement = facilityNode.toElement();
                while(!facilityNode.isNull()){
                    qDebug() << m.tagName();
                    if(facilityElement.tagName() == "Facility") {
                        facilityID = facilityElement.attribute("ID");
                        if (facilityID == "7"){
                            QDomNode patientListNode = facilityNode.firstChild();
                            QDomElement patientListElement = patientListNode.toElement();
                            if(patientListElement.tagName() == "PatientList") {
                                QDomNode patients = patientListNode.firstChild();
                                QDomElement patientsElement = patients.toElement();
                                while(!patients.isNull()){
                                    if(patientsElement.tagName() == "Patient") {
                                        QString firstName = patientsElement.attribute("firstName");
                                        QString lastName = patientsElement.attribute("lastName");
                                        QString healthCardNumber = patientsElement.attribute("healthCardNumber");
                                        QString dateAdmitted = patientsElement.attribute("dateAdmitted");
                                        QString dateAdded = patientsElement.attribute("dateAdded");
                                        QString reqCare = patientsElement.attribute("reqCare");
                                        QString occCare = patientsElement.attribute("occCare");

                                        //probably want to make this a "patient" object and then add or delete it to the db
                                        if (addOrDelete =="Delete")
                                        {
                                            qDebug() <<"lol";
                                            AssignHospitalController::getInstance()->setXmlNewPatient(healthCardNumber,firstName,lastName,dateAdmitted,dateAdded, reqCare,occCare,facilityID);
                                        }
                                        qDebug() << firstName << lastName << healthCardNumber << dateAdmitted << dateAdded << reqCare << occCare << addOrDelete << "areaID:" << areaID << "facilityID" << facilityID;

                                        //add patient to db
                                         patients = patients.nextSibling();
                                         patientsElement = patients.toElement();
                                    }
                                }
                            }
                        }
                    }
                    facilityNode = facilityNode.nextSibling();
                    facilityElement = facilityNode.toElement();
                }
            }

            n = n.nextSibling();
            m = n.toElement();
        }
        if(addOrDelete == "Add"){return "patients added to facility";}
        else {return "patients deleted from facility";}
        }
    return "-1";
}

QString XMLReader::readAddorDeleteToWaitingList(QString aRequest, QString addOrDelete){
    //area
        //waitinglist
            //patient
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();

        QString areaID;
        while (!n.isNull() ){
            if(m.tagName() == "Area") {
                areaID = m.attribute("ID");
                QDomNode waitinglistNode = n.firstChild();
                QDomElement waitinglistElement = waitinglistNode.toElement();
                if (waitinglistElement.tagName() == "WaitingList"){
                    QDomNode patientListNode = waitinglistNode.firstChild();
                    QDomElement patientListElement = patientListNode.toElement();
                    if(patientListElement.tagName() == "Patient") {
                        while(!patientListNode.isNull()){
                            if(patientListElement.tagName() == "Patient") {
                                QString firstName = patientListElement.attribute("firstName");
                                QString lastName = patientListElement.attribute("lastName");
                                QString healthCardNumber = patientListElement.attribute("healthCardNumber");
                                QString dateAdmitted = patientListElement.attribute("dateAdmitted");
                                QString dateAdded = patientListElement.attribute("dateAdded");
                                QString reqCare = patientListElement.attribute("reqCare");
                                QString occCare = patientListElement.attribute("occCare");

                                //probably want to make this a "patient" object and then add it to the db
                                qDebug() << firstName << lastName << healthCardNumber << dateAdmitted << dateAdded << reqCare << occCare << addOrDelete << "areaID" << areaID;

                                //add patient to db
                                 patientListNode = patientListNode.nextSibling();
                                 patientListElement = patientListNode.toElement();
                            }
                        }
                    }
                }
            }
            n = n.nextSibling();
            m = n.toElement();
        }
        if(addOrDelete == "Add"){return "patients added to waitingList";}
        else {return "patients deleted from waitingList";}
    }
    return "-1";
}

QString  XMLReader::readAddRemoveBeds(QString aRequest, QString type){
    //area
        //Facility
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();

        QString areaID;
        while (!n.isNull() ){
            if(m.tagName() == "Area") {
                areaID = m.attribute("ID");
                QDomNode facilityNode = n.firstChild();
                QDomElement facilityElement = facilityNode.toElement();
                if (facilityElement.tagName() == "Facility"){
                    while(!facilityNode.isNull()){
                        QString CCC = facilityElement.attribute("CCC");
                        QString AC = facilityElement.attribute("AC");
                        QString LTC = facilityElement.attribute("LTC");
                        QString facilityID = facilityElement.attribute("ID");


                        //probably want to make this a "patient" object and then add it to the db
                        qDebug() << CCC << AC << LTC << facilityID << areaID << type;

                        //add patient to db
                         facilityNode = facilityNode.nextSibling();
                         facilityElement = facilityNode.toElement();
                        }
                    }
                }
            n = n.nextSibling();
            m = n.toElement();
        }
        if(type == "Add"){return "patients added to waitingList";}
        else {return "patients deleted from waitingList";}
    }
    return "-1";
}




QString XMLReader::reportBeds(QString aRequest){
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();
        QString requestID;

       QString type = root.tagName();
       requestID = root.attribute("ID");

       QList<QString> facilityIDs;
       QString AC;
       QString CCC;
       QString LTC;
       QString startDate;
       QString endDate;
       QString typeOf;

       bool mismatch;

        //request and responses
        if(type == "Request") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.toElement();

            if(m.tagName() == "Report") {
                startDate = m.attribute("startDate");
                endDate = m.attribute("endDate");
                n = n.firstChild();
                m = n.toElement();
                if(m.tagName() == "FacilityRecord") {
                    n = n.firstChild();
                    m = n.toElement();
                    while(!n.isNull()) {
                        if(m.tagName() == "Facility") {
                            facilityIDs.append(m.attribute("ID"));
                        }
                        if(m.tagName() == "ACRecord") {
                            if (m.attribute("occupiedByLTC").length() > 0){
                                typeOf = "LTC";
                                mismatch = true;
                            }
                            if (m.attribute("occupiedByCCC").length() > 0){
                                typeOf = "CCC";
                                mismatch = true;
                            }
                            if (m.attribute("occupiedByAC").length() > 0){
                                typeOf = "AC";
                                mismatch = true;
                            }
                            AC = "1";
                        }
                        if(m.tagName() == "CCCRecord") {
                            if (m.attribute("occupiedByLTC").length() > 0){
                                typeOf = "LTC";
                                mismatch = true;
                            }
                            if (m.attribute("occupiedByCCC").length() > 0){
                                typeOf = "CCC";
                                mismatch = true;
                            }
                            if (m.attribute("occupiedByAC").length() > 0){
                                typeOf = "AC";
                                mismatch = true;
                            }
                            CCC = "1";
                        }
                        if(m.tagName() == "LTCRecord") {
                            if (m.attribute("occupiedByLTC").length() > 0){
                                typeOf = "LTC";
                                mismatch = true;
                            }
                            if (m.attribute("occupiedByCCC").length() > 0){
                                typeOf = "CCC";
                                mismatch = true;
                            }
                            if (m.attribute("occupiedByAC").length() > 0){
                                typeOf = "AC";
                                mismatch = true;
                            }
                            LTC = "1";
                        }
                   qDebug() << m.attribute("ID");
                   n = n.nextSibling();
                   m = n.toElement();
                }

            }
                if (AC == ""){AC = "0";}
                if (CCC == ""){CCC = "0";}
                if (LTC == ""){LTC = "0";}


                QString str;
                bool weReport = false;
                 foreach (str, facilityIDs)
                {
                    if (str == "7")
                        weReport = true;

                 }

                 QString response;
                 if (weReport == true && mismatch == false){
                     response = buildBedReportResponse(requestID, CCC, AC, LTC, startDate, endDate);
                 }
                 else if(weReport == true && mismatch == true){
                     response = buildBedMismatchReportResponse(requestID, CCC, AC, LTC, startDate, endDate, typeOf);
                 }

                 return response;
        }
    }
  }
    return "-1";
}


QString XMLReader::reportWaitingList(QString aRequest){
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();
        QString requestID;

       QString type = root.tagName();
       requestID = root.attribute("ID");

       QString dateAdded;
       QString dateAdmitted;
       QString reportStartDate;
       QString reportEndDate;


        //request and responses
        if(type == "Request" || type == "Response") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.toElement();

            if(m.tagName() == "Report") {
                reportStartDate = m.attribute("startDate");
                reportEndDate = m.attribute("endDate");
                n = n.firstChild();
                m = n.toElement();
                if(m.tagName() == "WaitingListRecord") {
                    n = n.firstChild();
                    m = n.toElement();
                        if(m.tagName() == "Patient") {
                            dateAdded = m.attribute("dateAdded");
                            dateAdmitted = m.attribute("dateAdmitted");
                            QString response = buildWaitingListResponse(requestID,reportStartDate,reportEndDate);
                            return response;
                        }
                }

            }
        }
    }
    return "-1";
  }


void XMLReader::readReportWaitingLisSizeResponse(QString aRequest){
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();
        QString requestID;

       QString type = root.tagName();
       requestID = root.attribute("ID");

       QString dateAdded;
       QString dateAdmitted;
       QString reportStartDate;
       QString reportEndDate;


        //request and responses
        if(type == "Request" || type == "Response") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.toElement();

            if(m.tagName() == "Report") {
                reportStartDate = m.attribute("startDate");
                reportEndDate = m.attribute("endDate");
                n = n.firstChild();
                m = n.toElement();
                if(m.tagName() == "WaitingListRecord") {
                    n = n.firstChild();
                    m = n.toElement();
                        if(m.tagName() == "Patient") {
                            dateAdded = m.attribute("dateAdded");
                            dateAdmitted = m.attribute("dateAdmitted");

                            //add to db
                            qDebug() << requestID << dateAdded << dateAdmitted << "Report Start Date: " << reportStartDate << "Report End date: " << reportEndDate ;
                        }
                }

            }
        }
    }
  }




QString XMLReader::reportWaitingListSize(QString aRequest){
    QDomDocument doc("xmldocument");
    if (doc.setContent(aRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();
        QString requestID;

       QString type = root.tagName();
       requestID = root.attribute("ID");

       QString dateAdded;
       QString dateAdmitted;
       QString reportStartDate;
       QString reportEndDate;


        //request and responses
        if(type == "Request" || type == "Response") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.toElement();

            if(m.tagName() == "Report") {
                reportStartDate = m.attribute("startDate");
                reportEndDate = m.attribute("endDate");
                n = n.firstChild();
                m = n.toElement();
                if(m.tagName() == "WaitingListRecord") {
                            return buildWaitingListSizeResponse(requestID,reportStartDate,reportEndDate);
                            qDebug() << requestID << dateAdded << dateAdmitted << "Report Start Date: " << reportStartDate << "Report End date: " << reportEndDate ;
                }

            }
        }
    }

}

QString XMLReader::buildBedReportResponse(QString requestID, QString CCC, QString AC, QString LTC, QString startDate, QString endDate){

    QString responseString;
    responseString.append(this->xmlHeader);
    responseString.append(this->buildResponseID(requestID));
    responseString.append(this->buildResponseDate(startDate, endDate));

         QSqlQuery query;
         query.exec("SELECT AC, CCC, LTC, date FROM bed_hist WHERE date >= '" + startDate.left(10) + "' and date <= '" + endDate.left(10) +  "';");

         QString facilityRecord = buildFacilityRecord(AC, CCC, LTC, startDate);

            responseString.append(facilityRecord);

           QString ACT ;
           QString CCCT ;
           QString LTCT ;

           QString date;

         while (query.next()) {
              ACT = query.value(0).toString();
              CCCT = query.value(1).toString();
              LTCT = query.value(2).toString();
              date = query.value(3).toString();

              responseString.append(buildFacilityRecordDifference(ACT, CCCT, LTCT, AC, CCC, LTC, date));

          }

              responseString.append("</Report>");
              responseString.append("</Response>");

    return responseString;
}

QString XMLReader::buildResponseID(QString ID){
    return "<Response ID=\"" + ID + "\">";
}

QString XMLReader::buildRequestID(QString ID){
    return "<Request ID=\"" + ID + "\">";
}

QString XMLReader::buildResponseDate(QString startdate, QString enddate){
       return "<Report startDate=\"" + startdate  + "\" endDate=\""  + enddate + "\">" ;
}

QString XMLReader::buildFacilityRecord(QString AC, QString CCC, QString LTC, QString date){
    QString returnString;
    returnString.append("<FacilityRecord dateTime=\"" + date + "\">");
    returnString.append("<Facility ID=\"7\"/>");

    QSqlQuery query;
    query.exec("SELECT SUM(AC), SUM(CCC), SUM(LTC) FROM bed_hist WHERE date <= '" + date.left(10) + "';");

    query.first();

    if (AC == "1"){
        QString ACVal = query.value(0).toString();
        if (ACVal == 0){
          returnString.append("<ACRecord occupied=\"0\"/>");
        }
        else{
            returnString.append("<ACRecord occupied=\"" + query.value(0).toString() + "\"/>");
        }
    }
    if (CCC == "1"){
        QString ACVal = query.value(1).toString();
        if (ACVal == 0){
            returnString.append("<CCCRecord occupied=\"0\"/>");
        }
        else{
            returnString.append("<CCCRecord occupied=\"" + query.value(1).toString() + "\"/>");
        }

    }
    if (LTC == "1"){
        QString ACVal = query.value(1).toString();
        if (ACVal == 0){
            returnString.append("<LTCRecord occupied=\"0\"/>");
        }
        else{
            returnString.append("<LTCRecord occupied=\"" + query.value(2).toString() + "\"/>");
        }
    }

    returnString.append("</FacilityRecord>");
    return returnString;
}

QString XMLReader::buildFacilityRecordDifference(QString ACT, QString CCCT, QString LTCT, QString AC, QString CCC, QString LTC, QString date){
    QString returnString;
    returnString.append("<FacilityRecordDifference dateTime=\"" + date + "\">");

    if (AC == "1"){
        returnString.append("<ACRecord occupied=\"" + ACT + "\"/>");
    }
    if (CCC == "1"){
        returnString.append("<CCCRecord occupied=\"" + CCCT + "\"/>");
    }
    if (LTC == "1"){
        returnString.append("<LTCRecord occupied=\"" + LTCT + "\"/>");
    }

    returnString.append("</FacilityRecordDifference>");
        return returnString;
}

QString XMLReader::buildWaitingListResponse(QString requestID, QString reportStartDate, QString reportEndDate)
{
    QString responseString;
    responseString.append(this->xmlHeader);
    responseString.append(this->buildResponseID(requestID));
    responseString.append(this->buildResponseDate(reportStartDate, reportEndDate));
    responseString.append("<WaitingListRecord>");

         QSqlQuery query;
         QString queryText;

         queryText.append("SELECT dte_added, dte_admitted FROM waitingList ");
         queryText.append("WHERE dte_admitted >=  '" + reportStartDate.left(10) + "' and dte_admitted <= '" + reportEndDate.left(10) +  "';");

         query.exec(queryText);

           QString patientString = "Patient";
           QString dte_added;
           QString dte_admitted;

         while (query.next()) {
              dte_added = query.value(0).toString();
              dte_admitted = query.value(1).toString();

              responseString.append(buildWaitingListRecord(dte_added,dte_admitted));

          }

              responseString.append("</WaitingListRecord>");
              responseString.append("</Report>");
              responseString.append("</Response>");

    return responseString;
}

QString XMLReader::buildWaitingListRecord(QString dte_added, QString dte_admitted){
    QString record;
    record.append("<Patient dateAdded=\"" + dte_added + "\" dateAdmitted=\"" + dte_admitted + "\" />");
    return record;
}

QString XMLReader::buildWaitingListSizeResponse(QString requestID, QString reportStartDate, QString reportEndDate)
{
    QString responseString;
    responseString.append(this->xmlHeader);
    responseString.append(this->buildResponseID(requestID));
    responseString.append(this->buildResponseDate(reportStartDate, reportEndDate));
    responseString.append(buildWaitingListSizeRecord(reportStartDate));


     QSqlQuery query;
     QString queryText;

     queryText.append("SELECT date, waitingListSize FROM waitinglist_hist ");
     queryText.append("WHERE date >=  '" + reportStartDate.left(10) + "' and date <= '" + reportEndDate.left(10) +  "';");

     query.exec(queryText);

       QString wlString = "WaitingListRecordDifference";
       QString date;
       QString listSize;

     while (query.next()) {
          date = query.value(0).toString();
          listSize = query.value(1).toString();

          responseString.append("<" + wlString + " dateTime=\"" + date + "\" listSize=\"" + listSize + "\" />");
      }

          responseString.append("</Report>");
          responseString.append("</Response>");

    return responseString;
}

QString XMLReader::buildWaitingListSizeRecord(QString date){
    QString returnString;
    QSqlQuery query;

    query.exec("SELECT SUM(waitingListSize) FROM waitinglist_hist WHERE date <= '" + date.left(10) + "';");
    query.first();

    QString val = query.value(0).toString();

    returnString.append("<WaitingListRecord dateTime=\"" + date + "\" listSize=\"" + val + "\" />");

    return returnString;
}

QString XMLReader::buildBedMismatchReportResponse(QString requestID, QString CCC, QString AC, QString LTC, QString startDate, QString endDate, QString type)
{
        QString responseString;
        responseString.append(this->xmlHeader);
        responseString.append(this->buildResponseID(requestID));
        responseString.append(this->buildResponseDate(startDate, endDate));

         QSqlQuery query;
         query.exec("SELECT occCare, reqCare, datePlacedOnWaitingList FROM patient WHERE datePlacedOnWaitingList >=  '" + startDate.left(10) + "' and datePlacedOnWaitingList <= '" + endDate.left(10) + "' and occCare <> reqCare;");

         QString facilityRecord = buildFacilityMismatchRecord(AC, CCC, LTC, type,startDate);
         responseString.append(facilityRecord);

           QString occCare ;
           QString reqCare ;
           QString datePlacedOnWaitingList ;

           QString date;

         while (query.next()) {
              occCare = query.value(0).toString();
              reqCare = query.value(1).toString();
              datePlacedOnWaitingList = query.value(2).toString();

              responseString.append(buildFacilityMismatchDifference(occCare, reqCare, datePlacedOnWaitingList, AC, CCC, LTC, date, type));
          }

          responseString.append("</Report>");
          responseString.append("</Response>");

    return responseString;


}

QString XMLReader::buildFacilityMismatchDifference(QString occCare, QString reqCare, QString datePlacedOnWaitingList, QString AC, QString CCC, QString LTC, QString date, QString type)
{

    QString returnString;

            if (AC == "1"){
                    if(occCare == "1"){
                        if (type == "CCC"){
                            if (reqCare == "2"){
                                returnString.append("<FacilityRecordDifference dateTime=\"" + datePlacedOnWaitingList + "\">");
                                returnString.append("<ACRecord occupiedByCCC=\"1\"/>");
                                returnString.append("</FacilityRecordDifference>");
                            }
                        }
                        if (type == "LTC"){
                            if (reqCare == "3"){
                                returnString.append("<FacilityRecordDifference dateTime=\"" + datePlacedOnWaitingList + "\">");
                                returnString.append("<ACRecord occupiedByLTC=\"1\"/>");
                                returnString.append("</FacilityRecordDifference>");
                            }
                        }
                    }
            }


            if (CCC == "1"){
                if(occCare == "2"){
                    if (type == "AC"){
                        if (reqCare == "1"){
                            returnString.append("<FacilityRecordDifference dateTime=\"" + datePlacedOnWaitingList + "\">");
                            returnString.append("<CCCRecord occupiedByAC=\"1\"/>");
                            returnString.append("</FacilityRecordDifference>");
                        }
                    }
                    if (type == "LTC"){
                        if (reqCare == "3"){
                            returnString.append("<FacilityRecordDifference dateTime=\"" + datePlacedOnWaitingList + "\">");
                            returnString.append("<CCCRecord occupiedByLTC=\"1\"/>");
                            returnString.append("</FacilityRecordDifference>");
                        }
                    }
                }
            }


            if (LTC == "1"){
                if(occCare == "3"){
                    if (type == "AC"){
                        if (reqCare == "1"){
                            returnString.append("<FacilityRecordDifference dateTime=\"" + datePlacedOnWaitingList + "\">");
                            returnString.append("<LTCRecord occupiedByAC=\"1\"/>");
                            returnString.append("</FacilityRecordDifference>");
                        }
                    }
                    if (type == "CCC"){
                        if (reqCare == "2"){
                            returnString.append("<FacilityRecordDifference dateTime=\"" + datePlacedOnWaitingList + "\">");
                            returnString.append("<LTCRecord occupiedByCCC=\"1\"/>");
                            returnString.append("</FacilityRecordDifference>");
                        }
                    }
                }
            }





    return returnString;
}

QString XMLReader::buildFacilityMismatchRecord(QString AC, QString CCC, QString LTC, QString type, QString startDate)
{
    QString returnString;
    returnString.append("<FacilityRecord dateTime=\"" + startDate + "\">");


    QSqlQuery query;
    query.exec("SELECT Count(occCare), occCare, reqCare FROM patient WHERE datePlacedOnWaitingList <='" + startDate + "' and occCare <> reqCare group by occCare, reqCare;");

    if (query.numRowsAffected() == 0){
        if (AC == "1"){
            if(type == "CCC"){
                returnString.append("<ACRecord occupiedByCCC=\"0\"/>");
            }
            if(type == "LTC"){
                returnString.append("<ACRecord occupiedByLTC=\"0\"/>");
            }
        }
        if (CCC == "1"){
            if(type == "AC"){
                returnString.append("<CCCRecord occupiedByAC=\"0\"/>");
            }
            if(type == "LTC"){
                returnString.append("<CCCRecord occupiedByLTC=\"0\"/>");
            }
        }
        if (LTC == "1"){
            if(type == "CCC"){
                returnString.append("<LTCRecord occupiedByCCC=\"0\"/>");
            }
            if(type == "AC"){
                returnString.append("<LTCRecord occupiedByAC=\"0\"/>");
            }
        }
    }

    while (query.next()) {

        if (query.value(1).toString() == "1"){
            if (AC == "1"){
                if(type == "CCC"){
                    if (query.value(2).toString() == "2"){
                        returnString.append("<ACRecord occupiedByCCC=\"" + query.value(0).toString() + "\"/>");
                    }
                }
                if(type == "LTC"){
                    if (query.value(2).toString() == "3"){
                        returnString.append("<ACRecord occupiedByLTC=\"" + query.value(0).toString() + "\"/>");
                    }
                }
            }
        }
        else if (query.value(1).toString() == "2"){
            if (CCC == "1"){
                if(type == "AC"){
                    if (query.value(2).toString() == "1"){
                        returnString.append("<CCCRecord occupiedByAC=\"" + query.value(0).toString() + "\"/>");
                    }
                }
                if(type == "LTC"){
                    if (query.value(2).toString() == "3"){
                        returnString.append("<CCCRecord occupiedByLTC=\"" + query.value(0).toString() + "\"/>");
                    }
                }
            }
        }
        else if (query.value(1).toString() == "3"){
            if (LTC == "1"){
                if(type == "AC"){
                    if (query.value(2).toString() == "1"){
                        returnString.append("<LTCRecord occupiedByAC=\"" + query.value(0).toString() + "\"/>");
                    }
                }
                if(type == "CCC"){
                    if (query.value(2).toString() == "2"){
                        returnString.append("<LTCRecord occupiedByCCC=\"" + query.value(0).toString() + "\"/>");
                    }
                }
            }
        }

    }

    returnString.append("</FacilityRecord>");
    return returnString;
}

QString XMLReader::requestAmountOfBeds(QList<QString> facilityIDs,QString AC,QString CCC,QString LTC,QString requestID,QString startDate,QString endDate)
{
    QString request;

    request.append(this->xmlHeader);
    request.append(this->buildRequestID(requestID));
    request.append(this->buildResponseDate(startDate,endDate));
    request.append("<FacilityRecord>");
    QString str;
     foreach (str, facilityIDs)
     {
        request.append("<Facility ID=\"" + str + "\"/>");
     }
    if (AC == "1") request.append("<ACRecord occupied=\"0\"/>");
    if (CCC == "1") request.append("<CCCRecord occupied=\"0\"/>");
    if (LTC == "1") request.append("<LTCRecord occupied=\"0\"/>");

    request.append("</FacilityRecord>");
    request.append("</Report>");
    request.append("</Request>");

    return request;
}

QString XMLReader::requestMismatches(QList<QString> facilityIDs, QString typeOfBed, QString occupiedByBed, QString requestID, QString startDate, QString endDate)
{
    QString request;
    QString occupiedBed;

    request.append(this->xmlHeader);
    request.append(this->buildRequestID(requestID));
    request.append(this->buildResponseDate(startDate,endDate));
    request.append("<FacilityRecord>");
    QString str;
     foreach (str, facilityIDs)
     {
        request.append("<Facility ID=\"" + str + "\"/>");
     }

    if (occupiedByBed == "AC") occupiedBed  = "occupiedByAC";
    if (occupiedByBed == "CCC") occupiedBed = "occupiedByCCC";
    if (occupiedByBed == "LTC") occupiedBed = "occupiedByLTC";

    if (typeOfBed == "AC") request.append("<ACRecord "   + occupiedBed + "=\"0\"/>");
    if (typeOfBed == "CCC") request.append("<CCCRecord " + occupiedBed + "=\"0\"/>");
    if (typeOfBed == "LTC") request.append("<LTCRecord " + occupiedBed + "=\"0\"/>");

    request.append("</FacilityRecord>");
    request.append("</Report>");
    request.append("</Request>");

    return request;
}

QString XMLReader::requestWaitingListSize(QString requestID, QString startDate, QString endDate){
    QString request;

    request.append(this->xmlHeader);
    request.append(this->buildRequestID(requestID));
    request.append(this->buildResponseDate(startDate,endDate));
    request.append("<WaitingListRecord listSize=\"0\"/>");
    request.append("</Report>");
    request.append("</Request>");
    return request;
}

QString XMLReader::requestWaitTimes(QString requestID, QString startDate, QString endDate){
    QString request;

    request.append(this->xmlHeader);
    request.append(this->buildRequestID(requestID));
    request.append(this->buildResponseDate(startDate,endDate));
    request.append("<WaitingListRecord>");
    request.append("<Patient dateAdded=\"0\" dateAdmitted=\"0\"/>");
    request.append("</WaitingListRecord>");
    request.append("</Report>");
    request.append("</Request>");
    return request;
}

QString XMLReader::readRequestAmountOfBeds(QString xmlRequest){
    QDomDocument doc("xmldocument");
    if (doc.setContent(xmlRequest)) {
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        QDomElement m = n.toElement();
        QString requestID;

       QString type = root.tagName();
       requestID = root.attribute("ID");

       QList<QString> facilityIDs;
       QString AC;
       QString CCC;
       QString LTC;
       QString startDate;
       QString endDate;
       QString typeOf;

       bool mismatch;

        //request and responses
        if(type == "Request") {
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            m = n.toElement();

            if(m.tagName() == "Report") {
                startDate = m.attribute("startDate");
                endDate = m.attribute("endDate");
                n = n.firstChild();
                m = n.toElement();
                if(m.tagName() == "FacilityRecord") {
                    n = n.firstChild();
                    m = n.toElement();
                    while(!n.isNull()) {
                        if(m.tagName() == "Facility") {
                            facilityIDs.append(m.attribute("ID"));
                        }
                        if(m.tagName() == "ACRecord") {
                            AC = "1";
                        }
                        if(m.tagName() == "CCCRecord") {
                            CCC = "1";
                        }
                        if(m.tagName() == "LTCRecord") {
                            LTC = "1";
                        }
                   qDebug() << m.attribute("ID");
                   n = n.nextSibling();
                   m = n.toElement();
                }

            }
                if (AC == ""){AC = "0";}
                if (CCC == ""){CCC = "0";}
                if (LTC == ""){LTC = "0";}


                QString str;
                bool weReport = false;
                 foreach (str, facilityIDs)
                {
                    if (str == "7")
                        weReport = true;

                 }

                 QString response;
                 response = buildBedReportResponse(requestID, CCC, AC, LTC, startDate, endDate);
                 return response;
        }
    }
  }
    return "-1";
}

QString XMLReader::readRequestMismatches(QString xmlRequest){

}

QString XMLReader::readRequestWaitTimes(QString xmlRequest){

}

QString XMLReader::readRequestWaitingListSize(QString xmlRequest){

}

/*insert into bed_hist
SELECT  AC, CCC, LTC,  date()  || 'T' || time()
FROM facility*/
