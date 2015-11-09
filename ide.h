#ifndef IDE_H
#define IDE_H

#include <QMainWindow>
#include "Updater.h"
#include "qmutex.h"

namespace Ui {
class IDE;
}

class IDE : public QMainWindow
{
    Q_OBJECT

    bool onEdit;
    int lines;
    QMutex mut,mut2;

public:
    explicit IDE(QWidget *parent = 0);
    Ui::IDE *ui;
    Renderizer mthread;
    ~IDE();

private slots:
/*
private:
    Ui::IDE *ui;
    */
    void on_pushButton_clicked();
    void on_langu_cursorPositionChanged();
};

#endif // IDE_H
