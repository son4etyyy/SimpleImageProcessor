#ifndef IMAGEDATABASECONNECTION_H
#define IMAGEDATABASECONNECTION_H
#include<characterimage.h>
#include <QtSql/QSqlDatabase>

//@brief GrayLevelHistogram is a class which is responsible
//for the Gray-Level Histogram of a certain image
class ImageDatabaseConnection
{
public:
    ImageDatabaseConnection();
    void close();
    void saveImageData(CharacterImage image);
    CharacterImage getImageData(QString documentName, int lineNumber, int characterNumber);
private:
    QSqlDatabase db;
};

#endif // IMAGEDATABASECONNECTION_H
