#ifndef OCR_H
#define OCR_H
#include<QVector>
#include<QImage>
using namespace std;
class OCR
{
private:
    QVector<pair<int, int> > horizontalProjection(QImage& image);
    QVector<QImage> verticalProjection(QImage& image, int begin, int end);
public:
    QVector<QImage> doOCR(QImage& image);
};

#endif // OCR_H
