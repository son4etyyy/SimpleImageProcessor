#include "sharpen.h"
#include "blur.h"
using namespace std;

Sharpen::Sharpen()
{
    //kernel matrix for sharpen effect
    int sharpen[5][5] =
    {
        {0, 0, 0, 0,0},
        {0, 0,-1, 0,0},
        {0,-1, 5,-1,0},
        {0, 0,-1, 0,0},
        {0, 0, 0, 0,0}
    };
    kernel.resize(5);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            kernel[i].push_back(sharpen[i][j]);
        }
    }
}

QImage Sharpen::apply(QImage srcImage){
    QImage dstImage = srcImage;
    //apply effect to each pixel
    for(int r=2;r<srcImage.height()-2;r++){
        for(int c=2;c<srcImage.width()-2;c++){
            dstImage.setPixel(c, r, applyEffectToPixel(srcImage, c, r));
        }
    }
    return dstImage;
}

QRgb Sharpen::applyEffectToPixel(const QImage &image, int x, int y)
{
    int kernelsize = this->kernel.size();
    qreal total = 0;
    qreal red = 0;
    qreal green = 0;
    qreal blue = 0;
    //for each element of kernel sum all red, green and blue
    //each of which is product of the picture pixel and and corresponding kernel pozition
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
