#ifndef OCR_H
#define OCR_H
#include<QVector>
#include<QImage>
#include "characterimage.h"
using namespace std;
//@brief OCR is a class which is responsible
//for the Optical character recognition
class OCR
{
private:
    //@brief this method is doing a horizontal projection andreturns
    //list of pair of coordinates which tell us where one line starts and ends.
    //Parameters: QImage image - the image of the text
    //Return type: QVector<pair<int, int> >
    QVector<pair<int, int> > horizontalProjection(QImage& image);
    //@brief this method is doing a vertical projection and returns s executed after horizontal projection.
    //list of of character images. This method should be alway
    //Parameters: QImage image - the image of the text
    //            begin - begin coordinate of the line
    //            end - end coordinate of the line
    //            lineNumber - the lineNumber
    //            filename - the filename of the image
    //Return type: QVector<CharacterImage>
    QVector<CharacterImage> verticalProjection(QImage& image, int begin, int end, int lineNumber, QString filename);
public:
    //@brief returns list of splitted items(CharacterImages)
    //Parameters: QImage image - the image of the text
    //            QString filename - filename of the image
    //Return type: QVector<CharacterImage>
    QVector<CharacterImage> doOCR(QImage& image, QString filename);
};

#endif // OCR_H
