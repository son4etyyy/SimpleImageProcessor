#include "displaywindow.h"
#include "ui_displaywindow.h"

DisplayWindow::DisplayWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaywindow)
{
    this->ui->setupUi(this);
    this->ui->graphicsView->setScene(&currScene);
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

void DisplayWindow::show(QImage &src)
{
    this->currScene.addPixmap(QPixmap::fromImage(src));
    this->exec();
}
