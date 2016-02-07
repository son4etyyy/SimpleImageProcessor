#ifndef GRAYLEVELHISTOGRAM_H
#define GRAYLEVELHISTOGRAM_H
#include<QImage>
#include"qcustomplot.h"
class GrayLevelHistogram
{
public:
    QVector<double> getHistogram(QImage image);
    void drawHistogram(QCustomPlot *customPlot, QImage image);
};

#endif // GRAYLEVELHISTOGRAM_H
