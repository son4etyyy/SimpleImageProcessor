#ifndef LINESELECT_H
#define LINESELECT_H

#include <QDialog>

namespace Ui {
class lineselect;
}

class lineselect : public QDialog
{
    Q_OBJECT

public:
    explicit lineselect(QWidget *parent = 0);
    ~lineselect();
    unsigned char getLineNumber( void );

private slots:
    void on_pushButton_clicked();

private:
    Ui::lineselect *ui;
    unsigned char number;
};

#endif // LINESELECT_H
