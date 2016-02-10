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
    //make a QGraphicsEffect object for bluring
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(radius);
    //apply the effect ot a QGraphicsPixmapItem
    //and add it to a QGraphicsScene
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(srcImage));
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    //make new image with the size of the source
    QImage dstImage(srcImage.size(), QImage::Format_ARGB32);
    //paint on it the scene with the Blur effect
    QPainter ptr(&dstImage);
    scene.render(&ptr, QRectF(), QRectF( 0, 0, srcImage.width(), srcImage.height()));
    return dstImage;
}
