#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QImage>

namespace Ui {
class displaywindow;
}

class displaywindow : public QDialog
{
    Q_OBJECT

public:
    explicit displaywindow(QWidget *parent = 0);
    ~displaywindow();
    void show(QImage& src);

private:
    Ui::displaywindow *ui;
    QGraphicsScene currScene;
};

#endif // DISPLAYWINDOW_H
