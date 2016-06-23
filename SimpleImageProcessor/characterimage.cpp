#include "characterimage.h"

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
