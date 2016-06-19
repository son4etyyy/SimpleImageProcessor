#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagefilter.h"
#include "grayscale.h"
#include "graylevelhistogram.h"
#include "qcolor.h"
#include "otsu.h"
#include "displaywindow.h"
#include "lineselect.h"

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

//@brief Used to show line of the segmentated text
//Parameters: Uint8 [0-255] Line Number
//Return type: None
void MainWindow::show_Line(unsigned char lineNumber)
{
    displaywindow Dialog;
    lineNumber < this->seperatedImage.size() ? Dialog.show(this->seperatedImage[lineNumber]) : Dialog.show(this->currImg);
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
    //Implement img seperation
    //seperateImage(seperatedImage, this->currImg);
}

//@brief Callback function for showling line
//Paramaeters None
//Return type: None
void MainWindow::on_actionShow_Line_triggered()
{
    lineselect LineSelect;
    this->show_Line(LineSelect.getLineNumber());
}
