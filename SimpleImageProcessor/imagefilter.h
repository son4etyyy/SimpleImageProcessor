#ifndef IMAGEFILTER
#define IMAGEFILTER
#include<QImage>

class ImageFilter
{
public:
    // pure virtual method providing interface
    virtual QImage apply(QImage srcImage) = 0;
};

#endif // IMAGEFILTER
