#ifndef CHARACTERIMAGE_H
#define CHARACTERIMAGE_H
#include<string>
#include<QImage>
using namespace std;

//@brief Image representing one character of text
class CharacterImage
{
public:
    //@brief Makes default CharacterImage
    CharacterImage();
    //@brief Makes CharacterImage of the given parameters
    //Parameters: QImage image - the image,
    //            string documentName - the name of the file from which this image is,
    //            int lineNumber - the number of the line of this character,
    //            int characterNumber - the number of the character in the line,
    //            int xCoordinate - c,
    //            int yCoordinate - the stating y coordinate
    CharacterImage(QImage image, string documentName, int lineNumber, int characterNumber, int xCoordinate, int yCoordinate);
    //@brief Gives the the image.
    //Return type: QImage
    QImage getImage() const;
    //@brief Gives the name of the file from which this image is.
    //Return type: string
    string getDocumentName() const;
    //@brief Gives the number of the line of this character.
    //Return type: int
    int getLineNumber() const;
    //@brief Gives the number of the character in the line.
    //Return type: int
    int getCharacterNumber() const;
    //@brief Gives the starting x coordinate.
    //Return type: int
    int getXCoordinate() const;
    //@brief Gives the starting y coordinate.
    //Return type: int
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
