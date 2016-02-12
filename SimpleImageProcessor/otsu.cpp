#include"otsu.h"
#include<QRgb>
#include<Qt>
#include<cmath>
Otsu::Otsu(QVector<double> histogram){
    this->histogram = histogram;
}

QImage Otsu::apply(QImage srcImage){
    int threshold = getThreshold(srcImage, histogram);
    for(int i = 0; i < srcImage.height(); i++){
        for(int j = 0; j < srcImage.width(); j++){
            QRgb valueOfPixel = srcImage.pixel(j, i);
            int grayValue = qGray(valueOfPixel);
            if(grayValue > threshold){
                srcImage.setPixel(j,i, qRgb(255, 255, 255));
            } else {
                srcImage.setPixel(j,i,qRgb(0, 0, 0));
            }
        }
    }
    return srcImage;
}

int Otsu::getThreshold(QImage srcImage, QVector<double> histogram){
    int totalNumberOfPixels = srcImage.height() * srcImage.width();

    double sum = 0;
    for (int t=0 ; t<256 ; t++) sum += t * histogram[t];

    double sumB = 0;
    int weightBackground = 0;
    int weightForeground = 0;

    double varMax = 0;
    int thresholdStartPos = 0;
    int thresholdEndPos = 0;

    for (int t=0 ; t<256 ; t++) {
        weightBackground += histogram[t];
        if (weightBackground == 0) continue;

        weightForeground = totalNumberOfPixels - weightBackground;
        if (weightForeground == 0) break;

        sumB += (double) (t * histogram[t]);

        double medianBackground = sumB / weightBackground;
        double medianForeground = (sum - sumB) / weightForeground;

        double varBetween = (double)weightBackground * (double)weightForeground * (medianBackground - medianForeground) * (medianBackground - medianForeground);

        if (varBetween > varMax) {
            varMax = varBetween;
            thresholdStartPos = t;
            thresholdEndPos = thresholdStartPos;
        } else if (fabs(varBetween - varMax) < 1e-9){
            if(t == thresholdEndPos+1){
                thresholdEndPos++;
            }
        }
    }

    return (thresholdStartPos + thresholdEndPos)/2;
}
