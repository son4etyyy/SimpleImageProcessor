#include "blur.h"
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>

QImage applyEffectToImage(QImage srcImage, QGraphicsEffect *effect, int extent=0)
{
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(srcImage));
    item.setGraphicsEffect(effect);
    scene.addItem(&item);
    QImage dstImage(srcImage.size()+QSize(extent*2, extent*2), QImage::Format_ARGB32);
    QPainter ptr(&dstImage);
    scene.render(&ptr, QRectF(), QRectF( -extent, -extent, srcImage.width()+extent*2, srcImage.height()+extent*2 ) );
    return dstImage;
}

QImage Blur::apply(QImage srcImage)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    QImage dstImage = applyEffectToImage(srcImage, blur);
    return dstImage;
}

