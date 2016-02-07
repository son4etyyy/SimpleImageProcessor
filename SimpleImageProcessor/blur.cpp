#include "blur.h"
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>

Blur::Blur(int radius)
{
    this->radius = radius;
}

QImage Blur::apply(QImage srcImage)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(radius);
    QImage dstImage = applyEffectToImage(srcImage, blur);
    return dstImage;
}


QImage Blur::applyEffectToImage(QImage srcImage, QGraphicsEffect *effect)
{
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(srcImage));
    item.setGraphicsEffect(effect);
    scene.addItem(&item);
    QImage dstImage(srcImage.size(), QImage::Format_ARGB32);
    QPainter ptr(&dstImage);
    scene.render(&ptr, QRectF(), QRectF( 0, 0, srcImage.width(), srcImage.height()));
    return dstImage;
}


