#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
private:
    Ui::MainWindow *ui;
    QGraphicsScene currScene;
    QImage currImg;
    QString fileName;
    QCustomPlot *customPlot;
    void display();
};

#endif // MAINWINDOW_H
