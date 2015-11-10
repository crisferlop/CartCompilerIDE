#include "Updater.h"
#include <QMutex>
Renderizer::Renderizer(QObject *parent) :
    QThread(parent),open(true)
{
}

void Renderizer::run()
{
    while(open){
        QMutex m;
        m.lock();
        emit updateText();
        m.unlock();
        this->msleep(5000);

    }
}

void Renderizer::setActive(bool b)
{
    open = b;
}
