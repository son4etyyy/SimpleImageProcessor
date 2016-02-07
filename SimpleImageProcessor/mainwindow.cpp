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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->graphicsView->setScene(&currScene);
    this->customPlot = ui->customPlot;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete customPlot;
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
    QString saveName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Image"),
                                                    QDir::currentPath(),
                                                    tr("Jpeg (*.jpeg);;Bmp (*.bmp);; Tif (*.tif);;Png (*.png)")
                                                    );
    //Apply changes to file selected
    this->currImg.save(saveName,0,100);
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
}

//@brief Callback function from QT events used to show greylevel histogram
//Parameters: None
//Return type: None
void MainWindow::on_actionShow_Greylevel_Histogram_triggered()
{
    GrayLevelHistogram glh;
    glh.drawHistogram(ui->customPlot, this->currImg);
}

//@brief Callback function from QT events used to apply otsu's method
//Parameters: None
//Return type: None
void MainWindow::on_actionOtsu_s_method_triggered()
{
    GrayLevelHistogram glh;
    QVector<double> histogram = glh.getHistogram(this->currImg);
    ImageFilter* filter = new Otsu(histogram);
    this->currImg = filter->apply(this->currImg);
    this->display();
}
