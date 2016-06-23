#ifndef IMAGEDATABASECONNECTION_H
#define IMAGEDATABASECONNECTION_H
#include<characterimage.h>
#include <QtSql/QSqlDatabase>

class ImageDatabaseConnection
{
public:
    ImageDatabaseConnection();
    void SaveImageData(CharacterImage image);
    CharacterImage GetImageData();//parameters x,y - coordinates of top left
private:
    QSqlDatabase db;
};

#endif // IMAGEDATABASECONNECTION_H
