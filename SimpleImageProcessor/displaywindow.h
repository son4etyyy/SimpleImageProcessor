#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QImage>

namespace Ui {
class displaywindow;
}

class DisplayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = 0);
    ~DisplayWindow();
    void show(QImage& src);

private:
    Ui::displaywindow *ui;
    QGraphicsScene currScene;
};

#endif // DISPLAYWINDOW_H
