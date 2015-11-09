#ifndef UPDATE_H
#define UPDATE_H

#include <QThread>

class Renderizer : public QThread
{
    Q_OBJECT
public:
    explicit Renderizer(QObject *parent = 0);
    void run();
    void setActive(bool b);
    bool isClose();

private:
    bool open;
signals:
    void updateText();
public slots:

};

#endif // UPDATE_H
