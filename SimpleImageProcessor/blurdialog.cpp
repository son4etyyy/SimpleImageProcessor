#include "blurdialog.h"
#include "ui_blurdialog.h"

BlurDialog::BlurDialog(QWidget *parent) :    
    QDialog(parent),
    ui(new Ui::BlurDialog),
    //Initialize the blur value exected for returning
    blurValue(0)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

BlurDialog::~BlurDialog()
{
    delete ui;
}

//@brief Function used to open a dialog and return a value extracted
//Parameters: None
//Return type: int (0-99) in percentage
int BlurDialog::getValue()
{
    //Show the dialog
    this->exec();
    //Return the blurvalue
    return this->blurValue;
}

//@brief Callback function from QT events used to store the slider value
//Parameters: None
//Return type: None
void BlurDialog::on_buttonBox_accepted()
{
    //The slider value is stored only if OK is pressed
    //Otherways the initial 0 is used
    blurValue = ui->blurSlider->value();
}
