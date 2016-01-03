#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include<imagefilter.h>

class GrayScale : public ImageFilter
{
public:
    QImage apply(QImage srcImage);
};

#endif // GRAYSCALE_H
