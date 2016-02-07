#include "sharpen.h"
#include "blur.h"
using namespace std;
const int size = 5;

QRgb applyEffectToPixel(const int (&kernel)[size][size], const QImage &image, int x, int y)
{
    int kernelsize = size;
    qreal total = 0;
    qreal red = 0;
    qreal green = 0;
    qreal blue = 0;
    for(int r = -kernelsize/2 ; r<=kernelsize/2; ++r)
    {
        for(int c = -kernelsize/2; c<=kernelsize/2; ++c)
        {
            int kerVal = kernel[kernelsize/2+r][kernelsize/2+c];
            total+=kerVal;
            red += qRed(image.pixel(x+c, y+r))*kerVal;
            green += qGreen(image.pixel(x+c, y+r))*kerVal;
            blue += qBlue(image.pixel(x+c, y+r))*kerVal;
        }
    }
    if(total==0)
    {
        return qRgb(qBound(0, qRound(red), 255), qBound(0, qRound(green), 255), qBound(0, qRound(blue), 255));
    }
    return qRgb(qBound(0, qRound(red/total), 255), qBound(0, qRound(green/total), 255), qBound(0, qRound(blue/total), 255));
}

QImage Sharpen::apply(QImage srcImage){
    QImage dstImage = srcImage;

    int sharpen[size][size] =
    {
        {0, 0, 0, 0,0},
        {0, 0,-1, 0,0},
        {0,-1, 5,-1,0},
        {0, 0,-1, 0,0},
        {0, 0, 0, 0,0}
    };

    for(int r=2;r<srcImage.height()-2;r++){
        for(int c=2;c<srcImage.width()-2;c++){
            dstImage.setPixel(c, r, applyEffectToPixel(sharpen, srcImage, c, r));
        }
    }
    return dstImage;
}
