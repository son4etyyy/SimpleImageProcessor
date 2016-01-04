#include "graylevelhistogram.h"
QVector<int> GrayLevelHistogram::getHistogram(QImage *image)
{
    QVector<int> histogram = QVector<int>(256);
    QRgb valueOfPixel;
    QRgb grayValue;
    for(int y = 0; y < image->height(); y++)
    {
        for(int x = 0; x < image->width(); x++)
        {
            valueOfPixel = image->pixel(x, y);
            grayValue = qGray(valueOfPixel);
            histogram[grayValue]++;
        }
    }
    return histogram;
}
