#include "grayscale.h"


QImage GrayScale::apply(QImage srcImage)
{
    QImage dstImage = srcImage.convertToFormat(srcImage.hasAlphaChannel() ?
                                                   QImage::Format_ARGB32 : QImage::Format_RGB32);
    unsigned int *data = (unsigned int*)dstImage.bits();
    int pixelCount = dstImage.width() * dstImage.height();
    //set each pixel to grayscale
    for(int i = 0; i < pixelCount; ++i)
    {
        int val = qGray(*data);
        *data = qRgba(val, val, val, qAlpha(*data));
        ++data;
    }

    return dstImage;
}

