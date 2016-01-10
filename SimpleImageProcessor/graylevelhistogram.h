#ifndef GRAYLEVELHISTOGRAM_H
#define GRAYLEVELHISTOGRAM_H
#include<QImage>
#include<qwt.h>
class GrayLevelHistogram
{
public:
    QVector<int> getHistogram(QImage *image);
};

#endif // GRAYLEVELHISTOGRAM_H
