#ifndef SHARPEN
#define SHARPEN
#include<imagefilter.h>

class Sharpen : public ImageFilter
{
public:
    void apply(QImage &srcImage);
};

#endif // SHARPEN

