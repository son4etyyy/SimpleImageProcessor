#include "lineselect.h"
#include "ui_lineselect.h"

lineselect::lineselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lineselect)
{
    ui->setupUi(this);
    this->number = 0;
}

lineselect::~lineselect()
{
    delete ui;
}

unsigned char lineselect::getLineNumber( void )
{
    this->exec();
    return this->number;
}

void lineselect::on_pushButton_clicked()
{
    this->number = this->ui->lineEdit->text().toInt();
}
