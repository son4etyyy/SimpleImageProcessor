#ifndef IMAGEDATABASECONNECTION_H
#define IMAGEDATABASECONNECTION_H
#include<characterimage.h>
#include <QtSql/QSqlDatabase>

class ImageDatabaseConnection
{
public:
    ImageDatabaseConnection();
    void close();
    void SaveImageData(CharacterImage image);
    CharacterImage GetImageData(string documentName, int lineNumber, int characterNumber);
private:
    QSqlDatabase db;
};

#endif // IMAGEDATABASECONNECTION_H
