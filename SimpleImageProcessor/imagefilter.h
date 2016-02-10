#ifndef IMAGEFILTER
#define IMAGEFILTER
#include<QImage>

//@brief apply filter over an image
class ImageFilter
{
public:
    //@brief Applies some filter to the source image.
    //Parameters: QImage srcImage - the source image
    //Return type: QImage
    virtual QImage apply(QImage srcImage) = 0;
};

#endif // IMAGEFILTER
