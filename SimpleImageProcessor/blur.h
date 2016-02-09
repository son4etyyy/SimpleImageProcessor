#ifndef BLUR
#define BLUR
#include"imagefilter.h"
#include<QGraphicsEffect>

//@brief apply blur filter over an image
class Blur : public ImageFilter
{
public:
    //@brief Constructs a Blur object
    //Parameters: int radius - the radius sith which the blur
    //method will be applied
    //Return type: None
    Blur(int radius);
    //@brief Applies blur filter to the source image.
    //Parameters: QImage srcImage - the source image
    //Return type: QImage - the blured image
    QImage apply(QImage srcImage);
private:
    int radius;
};

#endif // BLUR

