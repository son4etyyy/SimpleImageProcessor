#ifndef IMAGEDATABASECONNECTION_H
#define IMAGEDATABASECONNECTION_H
#include<characterimage.h>
#include <QtSql/QSqlDatabase>

//@brief ImageDatabaseConnection is a class which is responsible
//for the database connection and queries.
class ImageDatabaseConnection
{
public:
    //@brief Conects to a database
    ImageDatabaseConnection();
    //@brief Closes the database connection
    void close();
    //@brief Saves an image, representing one character to the database.
    //Parameters: QImage image - the character image
    void saveImageData(CharacterImage image);
    //@brief Gets an image, representing one character from the database.
    //Parameters: QString documentName - the name of the picture,
    //            int lineNumber - the line number to be found,
    //            int characterNumber - the character number to be found
    //Return type: CharacterImage
    CharacterImage getImageData(QString documentName, int lineNumber, int characterNumber);
private:
    QSqlDatabase db;
};

#endif // IMAGEDATABASECONNECTION_H
