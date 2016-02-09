#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include<imagefilter.h>

//@brief convert from a color image to grayscale image
class GrayScale : public ImageFilter
{
public:
    //@brief Applies grayscale filter to the source image.
    //Parameters: QImage srcImage - the source image
    //Return type: QImage - the image converted to grayscale
    QImage apply(QImage srcImage);
};

#endif // GRAYSCALE_H
