#ifndef SHARPEN
#define SHARPEN
#include<imagefilter.h>

//@brief apply sharpen filter over an image
class Sharpen : public ImageFilter
{
public:
    //@brief Applies sharpen filter to the source image.
    //Parameters: QImage srcImage - the source image
    //Return type: QImage - the sharpened image
    QImage apply(QImage srcImage);
};

#endif // SHARPEN

