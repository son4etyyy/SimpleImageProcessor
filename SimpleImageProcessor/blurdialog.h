#ifndef BLURDIALOG_H
#define BLURDIALOG_H

#include <QDialog>

namespace Ui {
class BlurDialog;
}

class BlurDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BlurDialog(QWidget *parent = 0);
    int getValue();
    ~BlurDialog();
private slots:
    void on_buttonBox_accepted();
private:
    Ui::BlurDialog *ui;
    int blurValue;
};

#endif // BLURDIALOG_H
