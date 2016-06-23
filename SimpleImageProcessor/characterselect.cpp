#include "characterselect.h"
#include "ui_lineselect.h"

CharcterSelect::CharcterSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lineselect)
{
    ui->setupUi(this);
    this->lineNumber = INVALID_VALUE;
    this->charNumber = INVALID_VALUE;
}

CharcterSelect::~CharcterSelect()
{
    delete ui;
}
void CharcterSelect::getLineNumber( unsigned char &lineNumber, unsigned char &charNumber )
{
    this->exec();
    lineNumber = this->lineNumber;
    charNumber = this->charNumber;
}

void CharcterSelect::on_pushButton_clicked()
{
    this->lineNumber = this->ui->lineEdit->text().toUInt();
    this->charNumber = this->ui->lineEdit_2->text().toUInt();
}
