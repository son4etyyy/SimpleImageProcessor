#ifndef OTSU_H
#define OTSU_H
#include "imagefilter.h"
#include<QImage>
class Otsu : public ImageFilter
{
public:
    Otsu(QVector<double> histogram);
    QImage apply(QImage srcImage);
private:
    QVector<double> histogram;
    int getThreshold(QImage srcImage, QVector<double> histogram);
};

#endif // OTSU_H
