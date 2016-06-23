#ifndef LINESELECT_H
#define LINESELECT_H

#include <QDialog>
#define INVALID_VALUE 255u
namespace Ui {
class lineselect;
}

class CharcterSelect : public QDialog
{
    Q_OBJECT

public:
    explicit CharcterSelect(QWidget *parent = 0);
    ~CharcterSelect();
    void getLineNumber( unsigned char &lineNumber, unsigned char &charNumber );

private slots:
    void on_pushButton_clicked();

private:
    Ui::lineselect *ui;
    unsigned char lineNumber;
    unsigned char charNumber;
};

#endif // LINESELECT_H
