#include "lineselect.h"
#include "ui_lineselect.h"

lineselect::lineselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lineselect)
{
    ui->setupUi(this);
    this->lineNumber = INVALID_VALUE;
    this->charNumber = INVALID_VALUE;
}

lineselect::~lineselect()
{
    delete ui;
}
void lineselect::getLineNumber( unsigned char lineNumber, unsigned char charNumber )
{
    this->exec();
    lineNumber = this->lineNumber;
    charNumber = this->charNumber;
}

void lineselect::on_pushButton_clicked()
{
    this->lineNumber = this->ui->lineEdit->text().toUInt();
    this->charNumber = this->ui->lineEdit_2->text().toUInt();
}
