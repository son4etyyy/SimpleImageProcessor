#include "graylevelhistogram.h"
QVector<double> GrayLevelHistogram::getHistogram(QImage image)
{
    QVector<double> histogram = QVector<double>(256);
    QRgb valueOfPixel;
    QRgb grayValue;
    for(int y = 0; y < image.height(); y++)
    {
        for(int x = 0; x < image.width(); x++)
        {
            valueOfPixel = image.pixel(x, y);
            grayValue = qGray(valueOfPixel);
            histogram[grayValue]++;
        }
    }
    return histogram;
}

void GrayLevelHistogram::drawHistogram(QCustomPlot *customPlot, QImage image){
    //trea se za4isti
    // create empty bar chart objects:
    QCPBars *pixelsBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(pixelsBars);
    //customPlot->setWindowFlags(Qt::Popup);
    pixelsBars->setName("Gray Level Histogram");
    pixelsBars->setBrush(QColor(150, 222, 0, 70));
    pixelsBars->setWidth(1);

    // prepare x axis with country labels:
    customPlot->xAxis->setAutoTicks(true);
    customPlot->xAxis->setAutoTickLabels(true);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 5);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, 256);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 600);
    customPlot->yAxis->setLabel("Number of pixels");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> regenData = this->getHistogram(image);
    QVector<double> ticks = QVector<double>(256);
    for(int i = 0; i < 256; i++){
        ticks[i] = i;
    }
    pixelsBars->setData(ticks, regenData);
    customPlot->replot();
}
