#include "grayscale.h"


void GrayScale::apply(QImage &srcImage){
    /*for (int ii = 0; ii < srcImage.height(); ii++) {
        uchar* scan = srcImage.scanLine(ii);
        int depth =4;
        for (int jj = 0; jj < srcImage.width(); jj++) {

            QRgb* rgbpixel = reinterpret_cast<QRgb*>(scan + jj*depth);
            int gray = qGray(*rgbpixel);
            *rgbpixel = QColor(gray, gray, gray).rgba();
        }
    }*/
    // Convert to 32bit pixel format
         QImage dstImage = srcImage.convertToFormat(srcImage.hasAlphaChannel() ?
                  QImage::Format_ARGB32 : QImage::Format_RGB32);

         unsigned int *data = (unsigned int*)dstImage.bits();
         int pixelCount = dstImage.width() * dstImage.height();

         // Convert each pixel to grayscale
         for(int i = 0; i < pixelCount; ++i) {
            int val = qGray(*data);
            *data = qRgba(val, val, val, qAlpha(*data));
            ++data;
         }

         srcImage = QImage(dstImage);
}

