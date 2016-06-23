#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagefilter.h"
#include "blur.h"
#include "sharpen.h"
#include "grayscale.h"
#include "graylevelhistogram.h"
#include "qcolor.h"
#include "otsu.h"
#include "leveldialog.h"
#include "lineselect.h"
#include "displaywindow.h"
#include "ocr.h"
#include "imagedatabaseconnection.h"
#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    customPlotSize(800,500)
{
    this->ui->setupUi(this);
    this->ui->graphicsView->setScene(&currScene);
    this->customPlot.setMinimumSize(this->customPlotSize);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//@brief Used to update the current scene displayed
//Parameters: None
//Return type: None
void MainWindow::display()
{
    //Used to wipe off current scene
    this->currScene.clear();
    //Construct a new scene from pixel map
    this->currScene.addPixmap(QPixmap::fromImage(currImg));
    //Set the new scene as current
    this->ui->graphicsView->show();
}

//@brief Callback function from QT events used to load an image file
//Parameters: None
//Return type: None
void MainWindow::on_actionOpen_triggered()
{
    //QFileDialog with the folloing types allowed - jpg, bmp, tif and png
    this->fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open Image"),
                                                  QDir::currentPath(),
                                                  tr("Image Files (*.jpeg *.jpg *.bmp *.tif *.png)")
                                                  );
    //Load the selected file
    this->currImg.load(fileName);
    //Immediately display the file loaded
    this->display();
}

//@brief Callback function from QT events used to save the current image
//Parameters: None
//Return type: None
void MainWindow::on_actionSave_triggered()
{
    //Apply changes to filename kept from opening the file
    this->currImg.save(this->fileName,0,100);
}

//@brief Callback function from QT events used to save the current image as a different file
//Parameters: None
//Return type: None
void MainWindow::on_actionSave_As_triggered()
{
    //Used to get new file name and format
    QString suffix;
    QString saveName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Image"),
                                                    QDir::currentPath(),
                                                    tr("Jpeg (*.jpeg);;Bmp (*.bmp);; Tif (*.tif);;Png (*.png)"),
                                                    &suffix
                                                    );
    //Determine correct suffix and append it
    //Apply changes to file selected
    if(suffix.contains("Jpeg (*.jpeg)"))
    {
        saveName.append(".jpeg");
        this->currImg.save(saveName,0,100);
    }
    else if(suffix.contains("Bmp (*.bmp)"))
    {
        saveName.append(".bmp");
        this->currImg.save(saveName,0,100);
    }
    else if(suffix.contains("Tif (*.tif)"))
    {
        saveName.append(".tif");
        this->currImg.save(saveName,0,100);
    }
    else if(suffix.contains("Png (*.png)"))
    {
        saveName.append(".png");
        this->currImg.save(saveName,0,100);
    }
    else
    {
        //Do nothing
    }
}

//@brief Callback function from QT events used to apply blur filter
//Parameters: None
//Return type: None
void MainWindow::on_actionBlur_triggered()
{
    //Object of class inheriting from QDialog used to adjust blur value
    LevelDialog BlurDialog;
    //Main BlurDialog funciton used to show the dialog and get the value
    int radius = BlurDialog.getValue();
    /*Apply filter to this->currImg */
    ImageFilter* filter = new Blur(radius);
    this->currImg = filter->apply(this->currImg);
    this->display();
    filter = 0;
}

//@brief Callback function from QT events used to apply sharpen filter
//Parameters: None
//Return type: None
void MainWindow::on_actionSharpen_triggered()
{
    /*Apply filter to this->currImg */
    ImageFilter* filter = new Sharpen();
    this->currImg = filter->apply(this->currImg);
    this->display();
    filter = 0;
}

//@brief Callback function from QT events used to apply greyscale filter
//Parameters: None
//Return type: None
void MainWindow::on_actionTo_Greyscale_triggered()
{
    /*Apply filter to this->currImg */
    ImageFilter* filter = new GrayScale();
    this->currImg = filter->apply(this->currImg);
    this->display();
    filter = 0;
}

//@brief Callback function from QT events used to show greylevel histogram
//Parameters: None
//Return type: None
void MainWindow::on_actionShow_Greylevel_Histogram_triggered()
{
    GrayLevelHistogram glh;
    glh.drawHistogram(&this->customPlot, this->currImg);
    this->customPlot.show();
}

//@brief Callback function from QT events used to apply Otsu's method
//Parameters: None
//Return type: None
void MainWindow::on_actionOtsu_s_method_triggered()
{
    ImageFilter* toGrayscale = new GrayScale();
    this->currImg = toGrayscale->apply(this->currImg);
    GrayLevelHistogram glh;
    QVector<double> histogram = glh.getHistogram(this->currImg);
    ImageFilter* filter = new Otsu(histogram);
    this->currImg = filter->apply(this->currImg);
    this->display();
    toGrayscale = 0;
    filter = 0;
}

//@brief Callback function from QT events used to perform OCR
//Parameters: None
//Return type: None
void MainWindow::on_actionApply_OCR_triggered()
{
    ImageFilter* toGrayscale = new GrayScale();
    this->currImg = toGrayscale->apply(this->currImg);
    GrayLevelHistogram glh;
    QVector<double> histogram = glh.getHistogram(this->currImg);
    ImageFilter* filter = new Otsu(histogram);
    this->currImg = filter->apply(this->currImg);
    OCR ocr;
    QVector<CharacterImage> result = ocr.doOCR(this->currImg, this->fileName);
    ImageDatabaseConnection idc;
    for(int i = 0; i < result.size(); i++){
        cout << i << endl;
        idc.SaveImageData(result[i]);
    }
    cout << "resultSize " << result.size() << endl;
}

//@brief Callback function for showling line
//Paramaeters None
//Return type: None
void MainWindow::on_actionShow_Line_triggered()
{
    lineselect LineSelect;
    this->show_Line(LineSelect.getLineNumber());

    int lineNumber, characterNumber;
    ImageDatabaseConnection dbConnection;
    dbConnection.GetImageData(fileName,lineNumber,characterNumber);
}

//@brief Used to show line of the segmentated text
//Parameters: Uint8 [0-255] Line Number
//Return type: None
void MainWindow::show_Line(unsigned char lineNumber)
{
    displaywindow Dialog;
    lineNumber < this->seperatedImage.size() ? Dialog.show(this->seperatedImage[lineNumber]) : Dialog.show(this->currImg);
}
