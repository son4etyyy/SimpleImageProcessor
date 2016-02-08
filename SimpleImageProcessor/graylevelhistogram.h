#ifndef GRAYLEVELHISTOGRAM_H
#define GRAYLEVELHISTOGRAM_H
#include<QImage>
#include"qcustomplot.h"

//@brief GrayLevelHistogram is a class which is responsible
//for the Gray-Level Histogram of a certain image
class GrayLevelHistogram
{
public:
    //@brief returns the count of pixels of each gray shade
    //Parameters: QImage image - the image which will be analyzed
    //Return type: QVector<double>
    QVector<double> getHistogram(QImage image);

    //@brief Used to update the current scene displayed
    //Parameters: QCustomPlot customPlot - the plot where the histogram will be displayed
    //            QImage image - image which will be analyzed
    //Return type: None
    void drawHistogram(QCustomPlot *customPlot, QImage image);
};

#endif // GRAYLEVELHISTOGRAM_H
