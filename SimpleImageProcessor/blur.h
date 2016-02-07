#ifndef BLUR
#define BLUR

#include"imagefilter.h"
#include<QGraphicsEffect>

class Blur : public ImageFilter
{
public:
    Blur(int radius);
    QImage apply(QImage srcImage);
private:
    int radius;
    QImage applyEffectToImage(QImage srcImage, QGraphicsEffect *effect);
};

#endif // BLUR

