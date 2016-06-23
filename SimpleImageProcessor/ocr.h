#ifndef OCR_H
#define OCR_H
#include<QVector>
#include<QImage>
#include "characterimage.h"
using namespace std;
class OCR
{
private:
    QVector<pair<int, int> > horizontalProjection(QImage& image);
    QVector<CharacterImage> verticalProjection(QImage& image, int begin, int end, int lineNumber);
public:
    QVector<CharacterImage> doOCR(QImage& image);
};

#endif // OCR_H
