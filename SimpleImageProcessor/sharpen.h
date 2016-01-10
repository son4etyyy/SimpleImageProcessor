#ifndef SHARPEN
#define SHARPEN
#include<imagefilter.h>

class Sharpen : public ImageFilter
{
public:
    QImage apply(QImage srcImage);
};

#endif // SHARPEN

