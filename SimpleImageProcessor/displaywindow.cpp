#include "displaywindow.h"
#include "ui_displaywindow.h"

displaywindow::displaywindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaywindow)
{
    this->ui->setupUi(this);
    this->ui->graphicsView->setScene(&currScene);
}

displaywindow::~displaywindow()
{
    delete ui;
}

void displaywindow::show(QImage &src)
{
    this->currScene.addPixmap(QPixmap::fromImage(src));
    this->exec();
}
