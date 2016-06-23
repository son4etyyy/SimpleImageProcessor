#include "imagedatabaseconnection.h"
#include <QString>
#include <QByteArray>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
#include<QBuffer>

ImageDatabaseConnection::ImageDatabaseConnection()
{
    //QString servername="lacal";
     QString dbname="mydb";

     this->db = QSqlDatabase::addDatabase("QPSQL");

     db.setConnectOptions();

     //QString dsn = QString("Driver={PostgreSQL};Server=%1;Port=5432;Database=%2;").arg(servername).arg(dbname);

     db.setDatabaseName(dbname);

     if (db.open()){
        // qDebug() << "Opened";
        cout << "Opened\n";
        //string query = "CREATE TABLE Characters ( documentName VARCHAR, lineNumber INT, characterNumber INT, xCoordinate INT, yCoordinate INT );";
        QString q = "CREATE TABLE Characters ( picture BYTEA, documentName VARCHAR, lineNumber INT, characterNumber INT, xCoordinate INT, yCoordinate INT, PRIMARY KEY (documentName,lineNumber,characterNumber) );";
        db.exec(q);

     } else {
         //qDebug() << "Error = " << db.lastError().text();
         cout << "Error = " << db.lastError().text().toStdString();
     }

}

void ImageDatabaseConnection::close(){
    db.close();
}

void ImageDatabaseConnection::SaveImageData(CharacterImage image){
    QByteArray picture;
    QBuffer buffer(&picture);
    buffer.open(QIODevice::WriteOnly);
    image.getImage().save(&buffer, "BMP");
    string documentName = image.getDocumentName();
    int lineNumber = image.getLineNumber();
    int characterNumber = image.getCharacterNumber();
    int xCoordinate = image.getXCoordinate();
    int yCoordinate = image.getYCoordinate();
    /*QString query = "";
    query.append(("INSERT INTO Characters VALUES ( '" ));//+ arr.toStdString()+"', '" +documentName+"',"+lineNumber+","+characterNumber+","+xCoordinate+","+yCoordinate +");").to_cstr());
    db.exec(query);*/

    QSqlQuery query = QSqlQuery(db);
    //QByteArray data = QByteArray("start\n\0\n\0\n\0\nend");
     query.prepare("INSERT INTO Characters (picture, documentName, lineNumber, characterNumber, xCoordinate, yCoordinate) VALUES(:picture, :documentName, :lineNumber, :characterNumber, :xCoordinate, :yCoordinate)");
     query.bindValue(":picture", picture, QSql::In | QSql::Binary);
     query.bindValue(":documentName", documentName.c_str());
     query.bindValue(":lineNumber", lineNumber);
     query.bindValue(":characterNumber", characterNumber);
     query.bindValue(":xCoordinate", xCoordinate);
     query.bindValue(":yCoordinate", yCoordinate);
     query.exec();
}

CharacterImage ImageDatabaseConnection::GetImageData(){
}
