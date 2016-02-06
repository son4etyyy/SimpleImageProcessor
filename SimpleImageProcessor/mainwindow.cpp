#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagefilter.h"
#include "blur.h"
#include "sharpen.h"
#include "grayscale.h"
#include "graylevelhistogram.h"
#include "qcolor.h"
#include "otsu.h"

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

void MainWindow::display()
{
    this->currScene.clear();
    this->currScene.addPixmap(QPixmap::fromImage(currImg));
    this->ui->graphicsView->show();
}
void MainWindow::on_actionOpen_triggered()
{
    this->fileName = QFileDialog::getOpenFileName(this,
                                                 tr("Open Image"),
                                                 QDir::currentPath(),
                                                 tr("Image Files (*.jpeg *.jpg *.bmp *.tif *.png)")
                                                 );
    this->currImg.load(fileName);
    this->display();
}

void MainWindow::on_actionSave_triggered()
{
    this->currImg.save(this->fileName,0,100);
}

void MainWindow::on_actionSave_As_triggered()
{
    QString saveName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Image"),
                                                    QDir::currentPath(),
                                                    tr("Jpeg (*.jpeg);;Bmp (*.bmp);; Tif (*.tif);;Png (*.png)")
                                                    );
    this->currImg.save(saveName,0,100);
}

void MainWindow::on_actionBlur_triggered()
{
    /*Apply filter to this->currImg */
    ImageFilter* filter = new Blur();
    this->currImg = filter->apply(this->currImg);
    this->display();

}

void MainWindow::on_actionSharpen_triggered()
{
    /*Apply filter to this->currImg */
    this->display();

}

void MainWindow::on_actionTo_Greyscale_triggered()
{
    /*Apply filter to this->currImg */
    ImageFilter* filter = new GrayScale();
    this->currImg = filter->apply(this->currImg);
    this->display();
}

void MainWindow::on_actionShow_Greylevel_Histogram_triggered()
{
    GrayLevelHistogram glh;
    glh.drawHistogram(ui->customPlot, this->currImg);
}

void MainWindow::on_actionOtsu_s_method_triggered()
{
    GrayLevelHistogram glh;
    QVector<double> histogram = glh.getHistogram(this->currImg);
    ImageFilter* filter = new Otsu(histogram);
    this->currImg = filter->apply(this->currImg);
    this->display();
}
