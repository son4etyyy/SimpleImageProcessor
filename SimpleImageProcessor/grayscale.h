#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include<imagefilter.h>

class GrayScale : public ImageFilter
{
public:
    void apply(QImage &srcImage);
};

#endif // GRAYSCALE_H
