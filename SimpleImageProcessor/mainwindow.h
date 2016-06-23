#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QFileDialog>
#include <QString>
#include <QMainWindow>
#include <QGraphicsScene>
#include "qcustomplot.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionBlur_triggered();
    void on_actionSharpen_triggered();
    void on_actionTo_Greyscale_triggered();
    void on_actionShow_Greylevel_Histogram_triggered();
    void on_actionOtsu_s_method_triggered();
    void on_actionApply_OCR_triggered();

    void on_actionShow_Line_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene currScene;
    QImage currImg;
    QString fileName;
    QSize customPlotSize;
    QCustomPlot customPlot;
    QVector< QVector< QImage> >seperatedImage;
    void display();
    void show_Line(unsigned char lineNumber, unsigned char charNumber);
};

#endif // MAINWINDOW_H
