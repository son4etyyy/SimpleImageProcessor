#ifndef BLUR
#define BLUR

#include<imagefilter.h>

class Blur : public ImageFilter
{
public:
    void apply(QImage &srcImage);
};

#endif // BLUR

