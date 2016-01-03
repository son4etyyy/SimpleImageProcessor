#ifndef BLUR
#define BLUR

#include<imagefilter.h>

class Blur : public ImageFilter
{
public:
    QImage apply(QImage srcImage);
};

#endif // BLUR

