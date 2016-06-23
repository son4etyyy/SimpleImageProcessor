#ifndef CHARACTERIMAGE_H
#define CHARACTERIMAGE_H
#include<string>
#include<QImage>
using namespace std;
//TODO CharacterImage
class CharacterImage
{
public:
    CharacterImage();
    CharacterImage(QImage image, string documentName, int lineNumber, int characterNumber, int xCoordinate, int yCoordinate);
    QImage getImage() const;
    string getDocumentName() const;
    int getLineNumber() const;
    int getCharacterNumber() const;
    int getXCoordinate() const;
    int getYCoordinate() const;

private:
    QImage image;
    string documentName;
    int lineNumber;
    int characterNumber;
    int xCoordinate;
    int yCoordinate;
};

#endif // CHARACTERIMAGE_H
