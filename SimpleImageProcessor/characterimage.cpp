#include "characterimage.h"

CharacterImage::CharacterImage()
{
    this->documentName = "";
    this->lineNumber = 0;
    this->characterNumber = 0;
    this->xCoordinate = 0;
    this->yCoordinate = 0;
}

CharacterImage::CharacterImage(QImage image, string documentName, int lineNumber, int characterNumber, int xCoordinate, int yCoordinate)
{
    this->image = image;
    this->documentName = documentName;
    this->lineNumber = lineNumber;
    this->characterNumber = characterNumber;
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
}

QImage CharacterImage::getImage() const
{
    return image;
}

string CharacterImage::getDocumentName() const
{
    return documentName;
}
int CharacterImage::getLineNumber() const
{
    return lineNumber;
}
int CharacterImage::getCharacterNumber() const
{
    return characterNumber;
}
int CharacterImage::getXCoordinate() const
{
    return xCoordinate;
}
int CharacterImage::getYCoordinate() const
{
    return yCoordinate;
}
