#ifndef SHARPEN
#define SHARPEN
#include<imagefilter.h>
#include<QVector>

//@brief apply sharpen filter over an image
class Sharpen : public ImageFilter
{
public:
    //@brief Constructs a Sharpen object
    //Parameters: None
    //Return type: None
    Sharpen();
    //@brief Applies sharpen filter to the source image.
    //Parameters: QImage srcImage - the source image
    //Return type: QImage
    QImage apply(QImage srcImage);
private:
    //kernel matrix used to apply sharpen filter
    QVector<QVector<int> > kernel;
    //@brief Applies kernel effect on the given pixel of the image.
    //Parameters: QImage image - the source image,
    //int x - the row of the image,
    //int y - the collumn of the image
    //Return type: QRgb
    QRgb applyEffectToPixel(const QImage &image, int x, int y);
};

#endif // SHARPEN

