#include "leveldialog.h"
#include "ui_leveldialog.h"

LevelDialog::LevelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelDialog),
    //Initialize the value exected for returning
    Value(0)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

LevelDialog::~LevelDialog()
{
    delete ui;
}

//@brief Function used to open a dialog and return a value extracted
//Parameters: None
//Return type: int (0-99) in percentage
int LevelDialog::getValue()
{
    //Show the dialog
    this->exec();
    //Return the blurvalue
    return this->Value;
}

//@brief Callback function from QT events used to store the slider value
//Parameters: None
//Return type: None
void LevelDialog::on_buttonBox_accepted()
{
    //The slider value is stored only if OK is pressed
    //Otherways the initial 0 is used
    Value = ui->horizontalSlider->value();
}
