#ifndef OTSU_H
#define OTSU_H
#include"imagefilter.h"
#include<QImage>

//@brief Otsu is a class which is responsible
//for the applying Otsu's method over an image
class Otsu : public ImageFilter
{
public:
    //@brief Constructs an Otsu object
    //Parameters: QVector<double> histogram - the Gray-Level Histogram
    //Return type: None
    Otsu(QVector<double> histogram);
    //@brief Applies Otsu's method(Binarization of image) to the source image.
    //Parameters: QImage srcImage - the source image
    //Return type: QImage
    QImage apply(QImage srcImage);
private:
    QVector<double> histogram;
    //@brief Return the threshold of a certain image
    //Parameters: QImage srcImage - the source image
    //            QVector<double> histogram - the Gray-Level Histogram
    //Return type: int
    int getThreshold(QImage srcImage, QVector<double> histogram);
};

#endif // OTSU_H
