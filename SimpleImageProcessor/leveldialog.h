#ifndef LEVELDIALOG_H
#define LEVELDIALOG_H

#include <QDialog>

namespace Ui {
class LevelDialog;
}

class LevelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LevelDialog(QWidget *parent = 0);
    ~LevelDialog();
    int getValue();
private slots:
    void on_buttonBox_accepted();
private:
    Ui::LevelDialog *ui;
    int Value;
};

#endif // LEVELDIALOG_H
